class Solution:
    def generate_trees_recursive(self, numbers):
        if len(numbers) == 1:
            return [TreeNode(numbers[0], None, None)]
        trees = []
        for i, number in enumerate(numbers):
            left_numbers, right_numbers = numbers[:i], numbers[i + 1:]
            new_trees = []
            if len(left_numbers) == 0:
                right_trees = self.generate_trees_recursive(right_numbers)
                new_trees = [TreeNode(number, None, tree) for tree in right_trees]
            elif len(right_numbers) == 0:
                left_trees = self.generate_trees_recursive(left_numbers)
                new_trees = [TreeNode(number, tree, None) for tree in left_trees]
            else:
                left_trees = self.generate_trees_recursive(left_numbers)
                right_trees = self.generate_trees_recursive(right_numbers)
                for left_tree in left_trees:
                    for right_tree in right_trees:
                        new_trees.append(TreeNode(number, left_tree, right_tree))
            trees += new_trees
        return trees

    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        return self.generate_trees_recursive([i + 1 for i in range(n)])
