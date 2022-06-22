import collections

class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        pattern_counter = collections.Counter()
        user_history_map = collections.defaultdict(collections.deque)
        sorted_indices = sorted([*range(len(username))], key=lambda x: timestamp[x])
        for i in sorted_indices:
            user_history_map[username[i]].append(website[i])
        for user_name, history in user_history_map.items():
            combination_set = set()
            for i in range(len(history)):
                for j in range(i + 1, len(history)):
                    for k in range(j + 1, len(history)):
                        combination_set.add((history[i], history[j], history[k]))
            for combination in combination_set:
                pattern_counter[combination] += 1
        result_pattern, best_score = tuple(website[:3]), -1
        for pattern, score in pattern_counter.items():
            if score > best_score or (score == best_score and pattern < result_pattern):
                result_pattern = pattern
                best_score = score
        return list(result_pattern)
