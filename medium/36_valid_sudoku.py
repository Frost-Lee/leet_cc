import collections

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_map, col_map, box_map = collections.defaultdict(set), collections.defaultdict(set), collections.defaultdict(set)
        for i in range(9):
            for j in range(9):
                if not board[i][j].isdigit():
                    continue
                if board[i][j] not in row_map[i]:
                    row_map[i].add(board[i][j])
                else:
                    return False
                if board[i][j] not in col_map[j]:
                    col_map[j].add(board[i][j])
                else:
                    return False
                box_index = i // 3 * 3 + j // 3
                if board[i][j] not in box_map[box_index]:
                    box_map[box_index].add(board[i][j])
                else:
                    return False
        return True
