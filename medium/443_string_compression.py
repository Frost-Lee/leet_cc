class Solution:
    def compress(self, chars: List[str]) -> int:
        char_group, char_group_count = chars[0], 1
        result = 0
        for char in chars[1:] + ['*']:
            if char == char_group:
                char_group_count += 1
            else:
                overwrite_index = result
                if char_group_count > 0:
                    
                    chars[overwrite_index] = char_group
                    overwrite_index += 1
                    if char_group_count > 1:
                        repeat_number_string = str(char_group_count)
                        for i in range(len(repeat_number_string)):
                            chars[overwrite_index] = repeat_number_string[i]
                            overwrite_index += 1
                result = overwrite_index
                char_group = char
                char_group_count = 1
        return result
