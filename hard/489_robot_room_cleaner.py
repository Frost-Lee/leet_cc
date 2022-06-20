class Solution:
    def cleanRoom(self, robot):
        def go_back():
            nonlocal robot
            robot.turnRight()
            robot.turnRight()
            robot.move()
            robot.turnRight()
            robot.turnRight()

        def backtrack(location, visited_locations, directions, direction_index):
            nonlocal robot
            visited_locations.add(location)
            robot.clean()
            for i in range(len(directions)):
                new_direction_index = (direction_index + i) % len(directions)
                new_location = (location[0] + directions[new_direction_index][0], location[1] + directions[new_direction_index][1])
                if new_location not in visited_locations and robot.move():
                    backtrack(new_location, visited_locations, directions, new_direction_index)
                    go_back()
                robot.turnRight()
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        visited_directions = set()
        backtrack((0, 0), visited_directions, directions, 0)
