class MyCalendarTwo:
    def __init__(self):
        self.tree_map = {}

    def book(self, start: int, end: int) -> bool:
        if start not in self.tree_map:
            self.tree_map[start] = 1
        else:
            self.tree_map[start] += 1
        if end not in self.tree_map:
            self.tree_map[end] = -1
        else:
            self.tree_map[end] -= 1
        self.tree_map = {k : v for k, v in sorted(self.tree_map.items(), key=lambda item: item[0])}
        overlap_count = 0
        for key, value in self.tree_map:
            overlap_count += value
            if overlap_count >= 3:
                self.tree_map[start] -= 1
                self.tree_map[end] += 1
                if self.tree_map[start] == 0:
                    self.tree_map.pop(start)
                if self.tree_map[end] == 0:
                    self.tree_map.pop(end)
                return False
        return True
