class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_groups = {}
        for string in strs:
            anagram_key = [0 for _ in range(26)]
            for letter in string:
                anagram_key[ord(letter) - ord('a')] += 1
            anagram_key = tuple(anagram_key)
            if anagram_key in anagram_groups:
                anagram_groups[anagram_key].append(string)
            else:
                anagram_groups[anagram_key] = [string]
        return [*anagram_groups.values()]
