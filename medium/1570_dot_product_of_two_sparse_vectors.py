class SparseVector:
    def __init__(self, nums: List[int]):
        self.vector = {i : v for i, v in enumerate(nums) if v != 0}

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        common_indices = set(self.vector.keys()).intersection(vec.vector.keys())
        return sum([self.vector[k] * vec.vector[k] for k in common_indices])
