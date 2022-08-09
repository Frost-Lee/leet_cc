class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.nested_list = nestedList
        self.current_index = 0
        self.current_nested_iterator = None
        self.current_value = self._seek_next()

    def next(self) -> int:
        result = self.current_value
        self.current_value = self._seek_next()
        return result

    def _seek_next(self):
        if self.current_index >= len(self.nested_list):
            return None
        if self.nested_list[self.current_index].isInteger():
            result = self.nested_list[self.current_index].getInteger()
            self.current_index += 1
            return result
        else:
            if self.current_nested_iterator is None:
                self.current_nested_iterator = NestedIterator(self.nested_list[self.current_index].getList())
                return self._seek_next()
            elif not self.current_nested_iterator.hasNext():
                self.current_nested_iterator = None
                self.current_index += 1
                return self._seek_next()
            else:
                return self.current_nested_iterator.next()

    def hasNext(self) -> bool:
        return self.current_value is not None
