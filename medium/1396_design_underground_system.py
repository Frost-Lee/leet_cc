import collections
class UndergroundSystem:

    def __init__(self):
        self.time_sum_dict = defaultdict(lambda: defaultdict(lambda: 0.0))
        self.traveller_count_dict = defaultdict(lambda: defaultdict(lambda: 0))
        self.traveller_cache = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.traveller_cache[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        travel_time = t - self.traveller_cache[id][1]
        start_station = self.traveller_cache[id][0]
        self.time_sum_dict[start_station][stationName] += travel_time
        self.traveller_count_dict[start_station][stationName] += 1
        self.traveller_cache.pop(id)

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        return self.time_sum_dict[startStation][endStation] / self.traveller_count_dict[startStation][endStation]
