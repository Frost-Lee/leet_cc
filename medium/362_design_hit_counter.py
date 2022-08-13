import collections

class HitCounter:

    def __init__(self):
        self.ttl = 300
        self.hit_list = collections.deque()

    def _trim(self, timestamp):
        while len(self.hit_list) > 0 and timestamp - self.hit_list[0] >= self.ttl:
            self.hit_list.popleft()

    def hit(self, timestamp: int) -> None:
        self._trim(timestamp)
        self.hit_list.append(timestamp)

    def getHits(self, timestamp: int) -> int:
        self._trim(timestamp)
        return len(self.hit_list)
