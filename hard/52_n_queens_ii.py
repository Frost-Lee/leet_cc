class Solution:
    def totalNQueens(self, n: int) -> int:
        board = [['.' for _ in range(n)] for _ in range(n)]
        result = 0
        def backtrack(row_index, placed_cols, placed_diagonals, placed_antidiagonals):
            nonlocal board, result, n
            if row_index == n:
                result += 1
            for col_index in range(n):
                diagonal_difference, antidiagonal_sum = row_index - col_index, row_index + col_index
                if col_index in placed_cols or diagonal_difference in placed_diagonals or antidiagonal_sum in placed_antidiagonals:
                    continue
                board[row_index][col_index] = 'Q'
                placed_cols.add(col_index)
                placed_diagonals.add(diagonal_difference)
                placed_antidiagonals.add(antidiagonal_sum)
                backtrack(row_index + 1, placed_cols, placed_diagonals, placed_antidiagonals)
                board[row_index][col_index] = '.'
                placed_cols.remove(col_index)
                placed_diagonals.remove(diagonal_difference)
                placed_antidiagonals.remove(antidiagonal_sum)
        backtrack(0, set(), set(), set())
        return result
