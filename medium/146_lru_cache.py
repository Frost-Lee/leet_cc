class LRUCacheItem:
    def __init__(self, key, value, prev=None, next=None):
        self.key = key
        self.value = value
        self.prev = prev
        self.next = next

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head_pointer = LRUCacheItem(None, None)
        self.tail_pointer = LRUCacheItem(None, None)
        self.head_pointer.next = self.tail_pointer
        self.tail_pointer.prev = self.head_pointer
        self.lookup_table = {}
        self.item_count = 0

    def _remove_item(self, key):
        if key in self.lookup_table:
            self.lookup_table[key].prev.next = self.lookup_table[key].next
            self.lookup_table[key].next.prev = self.lookup_table[key].prev
            self.lookup_table.pop(key, None)
            self.item_count -= 1
    
    def _push_item(self, key, value):
        new_item = LRUCacheItem(key, value)
        self.head_pointer.next.prev = new_item
        new_item.next = self.head_pointer.next
        self.head_pointer.next = new_item
        new_item.prev = self.head_pointer
        self.lookup_table[key] = new_item
        self.item_count += 1

    def get(self, key: int) -> int:
        if key in self.lookup_table:
            value = self.lookup_table[key].value
            self._remove_item(key)
            self._push_item(key, value)
            return value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.lookup_table:
            self._remove_item(key)
        elif self.item_count >= self.capacity:
            self._remove_item(self.tail_pointer.prev.key)
        self._push_item(key, value)
