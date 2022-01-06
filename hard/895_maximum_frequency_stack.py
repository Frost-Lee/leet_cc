class FreqStack:
    def __init__(self):
        self.max_frequency = 0
        self.frequency_map = Counter()
        self.frequency_stack_map = defaultdict(list)

    def push(self, val: int) -> None:
        self.frequency_map[val] += 1
        if self.frequency_map[val] > self.max_frequency:
            self.max_frequency = self.frequency_map[val]
        self.frequency_stack_map[self.frequency_map[val]].append(val)

    def pop(self) -> int:
        value = self.frequency_stack_map[self.max_frequency].pop()
        self.frequency_map[value] -= 1
        if len(self.frequency_stack_map[self.max_frequency]) == 0:
            self.max_frequency -= 1
        return value
