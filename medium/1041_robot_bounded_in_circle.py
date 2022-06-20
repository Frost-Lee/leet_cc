class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        current_index, current_direction = (0, 0), 0
        direction_move_map = {
            0: (0, 1),
            1: (1, 0),
            2: (0, -1),
            3: (-1, 0)
        }
        for instruction in instructions:
            if instruction == 'G':
                move = direction_move_map[current_direction]
                current_index = (current_index[0] + move[0], current_index[1] + move[1])
            elif instruction == 'L':
                current_direction = (current_direction - 1) % 4
            elif instruction == 'R':
                current_direction = (current_direction + 1) % 4
        return current_index == (0, 0) or current_direction != 0
