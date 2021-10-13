class Solution:
    def is_same_account(self, account_1, account_2):
        if account_1[0] != account_2[0]:
            return False
        return len(set(account_1[1:]).intersection(set(account_2[1:]))) > 0

    def find(self, disjoint_set, index):
        while disjoint_set[index] >= 0:
            index = disjoint_set[index]
        return index

    def union(self, disjoint_set, index_1, index_2):
        if disjoint_set[index_1] > disjoint_set[index_2]:
            index_1, index_2 = index_2, index_1
        size = -disjoint_set[index_2]
        disjoint_set[index_2] = index_1
        disjoint_set[index_1] -= size

    def accountsMerge(self, accounts):
        disjoint_set = [-1 for _ in range(len(accounts))]
        for i in range(len(accounts)):
            for j in range(i + 1, len(accounts)):
                if self.is_same_account(accounts[i], accounts[j]):
                    i_index = self.find(disjoint_set, i)
                    j_index = self.find(disjoint_set, j)
                    if i_index != j_index:
                        self.union(disjoint_set, i_index, j_index)
        merged_accounts = {}
        for i in range(len(accounts)):
            set_index = self.find(disjoint_set, i)
            if set_index not in merged_accounts:
                merged_accounts[set_index] = (accounts[i][0], set(accounts[i][1:]))
            else:
                merged_accounts[set_index] = (accounts[i][0], merged_accounts[set_index][1].union(set(accounts[i][1:])))
        return [[value[0]] + sorted(list(value[1])) for key, value in merged_accounts.items()]
