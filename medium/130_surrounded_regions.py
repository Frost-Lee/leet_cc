class Solution:
    def dfs(self, board, source_coordinate):
        value = board[source_coordinate[0]][source_coordinate[1]]
        if value != 'O':
            return
        board[source_coordinate[0]][source_coordinate[1]] = '-'
        height, width = len(board), len(board[0])
        for row_delta, col_delta in [(1, 0), (0, -1), (-1, 0), (0, 1)]:
            new_row, new_col = source_coordinate[0] + row_delta, source_coordinate[1] + col_delta
            if 0 <= new_row < height and 0 <= new_col < width:
                self.dfs(board, (new_row, new_col))

    def solve(self, board: List[List[str]]) -> None:
        height, width = len(board), len(board[0])
        for i in range(width):
            self.dfs(board, (0, i))
        if height > 1:
            for i in range(width):
                self.dfs(board, (height - 1, i))
        for i in range(1, height - 1):
            self.dfs(board, (i, 0))
        if width > 1:
            for i in range(1, height - 1):
                self.dfs(board, (i, width - 1))
        for i in range(height):
            for j in range(width):
                if board[i][j] == '-':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'
