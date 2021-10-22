class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        color_map = [0 for _ in range(n)]
        edge_map = {i : [] for i in range(n)}
        for dislike in dislikes:
            edge_map[dislike[0] - 1].append(dislike[1] - 1)
            edge_map[dislike[1] - 1].append(dislike[0] - 1)
        def dfs_color(source, previous_color):
            color_map[source] = -previous_color
            for destination in edge_map[source]:
                if color_map[destination] == color_map[source]:
                    return False
                elif color_map[destination] == 0:
                    if not dfs_color(destination, color_map[source]):
                        return False
            return True
        for i in range(n):
            if color_map[i] == 0 and not dfs_color(i, 1):
                return False
        return True
