import math

class Solution:
    def findNthDigit(self, n: int) -> int:
        if n < 10:
            return n
        digit_count, number_count, digit_length = 9 * 1, 9, 1
        previous_digit_count, previous_number_count, previous_digit_length = None, None, None
        while digit_count < n:
            previous_digit_count, previous_number_count, previous_digit_length = digit_count, number_count, digit_length
            number_count *= 10
            digit_length += 1
            digit_count += number_count * digit_length
        remaining_digit_count = n - previous_digit_count
        target_number = 10 ** previous_digit_length - 1 + math.ceil(remaining_digit_count / digit_length)
        target_index = (remaining_digit_count % digit_length + digit_length - 1) % digit_length
        return int(str(target_number)[target_index])
