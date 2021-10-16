class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        letter_indices, permutations = [], []
        for i in range(len(s)):
            if ord('a') <= ord(s[i].lower()) <= ord('z'):
                letter_indices.append(i)
        permutation_count = 2 ** len(letter_indices)
        bit_mask = 0
        for _ in range(permutation_count):
            new_string = list(s)
            for index, letter_index in enumerate(letter_indices):
                new_string[letter_index] = s[letter_index].lower() if bit_mask & (1 << index) else s[letter_index].upper()
            permutations.append(''.join(new_string))
            bit_mask += 1
        return permutations
