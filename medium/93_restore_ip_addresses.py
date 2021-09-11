class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        valid_addresses = []
        def is_legal_part(string):
            return 0 <= int(string) <= 255 and not (string[0] == '0' and len(string) > 1)
        for i in range(1, min(4, len(s))):
            for j in range(i + 1, min(i + 4, len(s))):
                for k in range(j + 1, min(i + j + 4, len(s))):
                    if is_legal_part(s[:i]) and is_legal_part(s[i:j]) and is_legal_part(s[j:k]) and is_legal_part(s[k:]):
                        valid_addresses.append('.'.join([s[:i], s[i:j], s[j:k], s[k:]]))
        return valid_addresses
