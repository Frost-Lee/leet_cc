class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(row, col, visit_mask, index):
            if index == len(word) or word[index:] == board[row][col]:
                return True
            elif word[index] != board[row][col]:
                return False
            visit_mask[row][col] = True
            for row_shift, col_shift in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                new_row, new_col = row + row_shift, col + col_shift
                if 0 <= new_row < len(board) and 0 <= new_col < len(board[0]) and not visit_mask[new_row][new_col]:
                    if dfs(new_row, new_col, visit_mask, index + 1):
                        return True
            visit_mask[row][col] = False
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                visit_mask = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
                if dfs(i, j, visit_mask, 0):
                    return True
        return False
