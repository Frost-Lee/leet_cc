class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        left_numbers = [i + 1 for i in range(n)]
        permutation_string = ''
        while len(left_numbers) > 1:
            index = (k - 1) // math.factorial(n - 1)
            permutation_string += str(left_numbers[index])
            del left_numbers[index]
            k = k % math.factorial(n - 1)
            n -= 1
        permutation_string += str(left_numbers[0])
        return permutation_string
