class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        def create_line(word_pool, pool_length, left_justify):
            if len(word_pool) == 1:
                return word_pool[0] + ' ' * (maxWidth - len(word_pool[0]))
            if left_justify:
                result = ' '.join(word_pool)
                return result + ' ' * (maxWidth - len(result))
            else:
                base_spacing = (maxWidth - pool_length) // (len(word_pool) - 1)
                extra_spacing = (maxWidth - pool_length) % (len(word_pool) - 1)
                result = ''
                for index, word in enumerate(word_pool):
                    result += word
                    if index != len(word_pool) - 1:
                        result += ' ' * base_spacing
                        if extra_spacing > 0:
                            result += ' '
                            extra_spacing -= 1
                return result
        pool, pool_size_with_space = [], 0
        result = []
        for word in words:
            if pool_size_with_space + len(word) > maxWidth:
                result.append(create_line(pool, pool_size_with_space - len(pool), left_justify=False))
                pool, pool_size_with_space = [], 0
            pool.append(word)
            pool_size_with_space += (len(word) + 1)
        result.append(create_line(pool, pool_size_with_space - len(pool), left_justify=True))
        return result
