class Solution:
    def intToRoman(self, num: int) -> str:
        bases_dict = {
            1: 'I', 
            4: 'IV', 
            5: 'V', 
            9: 'IX', 
            10: 'X', 
            40: 'XL', 
            50: 'L', 
            90: 'XC', 
            100: 'C', 
            400: 'CD', 
            500: 'D', 
            900: 'CM', 
            1000: 'M'
        }
        bases = [*bases_dict.keys()]
        result = ''
        base_index = len(bases) 
        while num > 0:
            for index in range(base_index - 1, -1, -1):
                if bases[index] <= num:
                    base_index, base = index, bases[index]
                    break
            base_repeats = num // bases[base_index]
            result += bases_dict[base] * base_repeats
            num -= base * base_repeats
        return result

solution = Solution()
print(solution.intToRoman(1994))
