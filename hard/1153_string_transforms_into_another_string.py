class Solution:
    def canConvert(self, str1, str2):
        conversion_map = {}
        if len(str1) != len(str2):
            return False
        if str1 == str2:
            return True
        for c1, c2 in zip(str1, str2):
            if c1 not in conversion_map:
                conversion_map[c1] = c2
            elif conversion_map[c1] != c2:
                return False
        print(len(conversion_map))
        print(len(set(conversion_map.values())))
        if len(conversion_map) == 26 and len(set(conversion_map.values())) == 26:
            return False
        return True
