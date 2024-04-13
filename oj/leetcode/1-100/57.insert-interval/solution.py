class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        if not intervals:
            return [newInterval]
        l = self.search(intervals, newInterval[0], 1)
        r = self.search(intervals, newInterval[1], 0)
        # print(l, r)
        if intervals[r][0] > newInterval[1] and l == r:
            result = intervals[0:l]
            result.append(newInterval)
            result.extend(intervals[l:])
            return result
        if intervals[r][0] > newInterval[1]:
            r -= 1
        # print(l, r)
        if intervals[r][1] < newInterval[0]:
            r += 1
        # print(l, r)
        if r < 0:
            result = [newInterval]
            result.extend(intervals)
            return result
        elif r == len(intervals):
            intervals.append(newInterval)
            return intervals
        result = intervals[0:l]
        result.append(
            [min(intervals[l][0], newInterval[0]), max(intervals[r][1], newInterval[1])]
        )
        result.extend(intervals[r + 1 :])
        return result

    def search(self, intervals: List[List[int]], num: int, i: int) -> int:
        l, r = 0, len(intervals) - 1
        while l < r:
            m = (l + r) // 2
            if intervals[m][i] == num:
                return m
            if intervals[m][i] < num:
                l = m + 1
            else:
                r = m
        return r
