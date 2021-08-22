class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        intersectionIntervals = []
        firstListIndex, secondListIndex = 0, 0
        while firstListIndex < len(firstList) and secondListIndex < len(secondList):
            if firstList[firstListIndex][0] > secondList[secondListIndex][1]:
                secondListIndex += 1
            elif secondList[secondListIndex][0] > firstList[firstListIndex][1]:
                firstListIndex += 1
            else:
                intersectionIntervals.append([
                    max(firstList[firstListIndex][0], secondList[secondListIndex][0]),
                    min(firstList[firstListIndex][1], secondList[secondListIndex][1])
                ])
                if firstList[firstListIndex][1] > secondList[secondListIndex][1]:
                    secondListIndex += 1
                elif secondList[secondListIndex][1] > firstList[firstListIndex][1]:
                    firstListIndex += 1
                else:
                    firstListIndex += 1
                    secondListIndex += 1
        return intersectionIntervals
