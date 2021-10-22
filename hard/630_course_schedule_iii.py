class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        selected_course_durations = []
        consumed_days = 0
        courses = sorted(courses, key=lambda x: x[1])
        for course in courses:
            duration, deadline = course
            if consumed_days + duration <= deadline:
                heapq.heappush(selected_course_durations, -duration)
                consumed_days += duration
            elif len(selected_course_durations) > 0 and -selected_course_durations[0] > duration:
                consumed_days -= -heapq.heappop(selected_course_durations)
                heapq.heappush(selected_course_durations, -duration)
                consumed_days += duration
        return len(selected_course_durations)
