class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        if len(word) == 0:
            return []
        abbrieviations = [word[0], '_']
        word = word[1:]
        while len(word) > 0:
            new_abbrieviations = []
            for abbrieviation in abbrieviations:
                new_abbrieviations.append(abbrieviation + word[0])
                new_abbrieviations.append(abbrieviation + '_')
            word = word[1:]
            abbrieviations = new_abbrieviations
        def convert_placeholder(string):
            result_string = ''
            place_holder_count = 0
            for element in string:
                if element == '_':
                    place_holder_count += 1
                else:
                    if place_holder_count > 0:
                        result_string += str(place_holder_count)
                    result_string += element
                    place_holder_count = 0
            if place_holder_count > 0:
                result_string += str(place_holder_count)
            return result_string
        return [*map(convert_placeholder, abbrieviations)]
