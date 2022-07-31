class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def get_key(log):
            splitted_log = log.split(' ')
            identifier, message = splitted_log[0], ' '.join(splitted_log[1:])
            return (1, ) if message[0].isdigit() else (0, message, identifier)
        return sorted(logs, key=get_key)
