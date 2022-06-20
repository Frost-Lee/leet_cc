import collections

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        def get_intermediate_word(word, index):
            return word[:index] + '*' + word[index + 1:]
        if endWord not in wordList:
            return 0
        intermediate_word_map, word_length = {}, len(beginWord)
        for word in [beginWord] + wordList:
            for i in range(word_length):
                intermediate_word = get_intermediate_word(word, i)
                if intermediate_word in intermediate_word_map:
                    intermediate_word_map[intermediate_word].add(word)
                else:
                    intermediate_word_map[intermediate_word] = set([word])
        bfs_queue, visited_nodes = collections.deque(), set()
        bfs_queue.append((beginWord, 1))
        visited_nodes.add(beginWord)
        while len(bfs_queue) > 0:
            popped_word, distance = bfs_queue.popleft()
            for i in range(word_length):
                for word in intermediate_word_map[get_intermediate_word(popped_word, i)]:
                    if word == endWord:
                        return distance + 1
                    elif word not in visited_nodes:
                        visited_nodes.add(word)
                        bfs_queue.append((word, distance + 1))
        return 0
