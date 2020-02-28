class LRUCache:
    def __init__(self, capacity: int):
        self.cache = {}
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.cache:
            result = self.cache.pop(key)
            self.cache[key] = result
            return result
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.pop(key)
            self.cache[key] = value
        elif len(self.cache) < self.capacity:
            self.cache[key] = value
        else:
            self.cache.pop([*self.cache.keys()][0])
            self.cache[key] = value
