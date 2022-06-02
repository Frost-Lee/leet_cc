import collections
import random

class RandomizedSet:
    def __init__(self):
        self.set_dict = {}
        self.set_list = collections.deque()

    def insert(self, val: int) -> bool:
        if val in self.set_dict:
            return False
        else:
            self.set_dict[val] = len(self.set_list)
            self.set_list.append(val)
            return True

    def remove(self, val: int) -> bool:
        if val not in self.set_dict:
            return False
        else:
            index = self.set_dict[val]
            self.set_list[index] = self.set_list[len(self.set_list) - 1]
            self.set_dict[self.set_list[len(self.set_list) - 1]] = index
            self.set_dict.pop(val)
            self.set_list.pop()
            return True

    def getRandom(self) -> int:
        return self.set_list[random.randint(0, len(self.set_list) - 1)]
