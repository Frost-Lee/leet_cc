class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        def backtrack(string_index, pattern_index, current_mapping, mapped_set):
            nonlocal pattern, s
            if string_index == len(s) and pattern_index == len(pattern):
                return True
            elif string_index == len(s) or pattern_index == len(pattern):
                return False
            if pattern[pattern_index] in current_mapping:
                prefix = current_mapping[pattern[pattern_index]]
                if s[string_index:string_index + len(prefix)] != prefix:
                    return False
                else:
                    return backtrack(string_index + len(prefix), pattern_index + 1, current_mapping, mapped_set)
            else:
                for i in range(string_index, len(s)):
                    if s[string_index:i + 1] in mapped_set:
                        continue
                    current_mapping[pattern[pattern_index]] = s[string_index:i + 1]
                    mapped_set.add(s[string_index:i + 1])
                    if backtrack(i + 1, pattern_index + 1, current_mapping, mapped_set):
                        return True
                    mapped_set.remove(s[string_index:i + 1])
                    current_mapping.pop(pattern[pattern_index], None)
                return False
        return backtrack(0, 0, {}, set())
