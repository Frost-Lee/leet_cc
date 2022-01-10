class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjacent_list = {i : [] for i in range(numCourses)}
        indegree_map = {i : 0 for i in range(numCourses)}
        for prerequisite in prerequisites:
            adjacent_list[prerequisite[1]].append(prerequisite[0])
            indegree_map[prerequisite[0]] += 1
        queue = [i for i in range(numCourses) if indegree_map[i] == 0]
        course_schedule = []
        while len(queue) > 0:
            course = queue.pop(0)
            course_schedule.append(course)
            for adjacent_course in adjacent_list[course]:
                indegree_map[adjacent_course] -= 1
                if indegree_map[adjacent_course] == 0:
                    queue.append(adjacent_course)
        return course_schedule if len(course_schedule) == numCourses else []
