#!/usr/bin/env python
# -*- coding: utf-8 -*-

from typing import List, Dict


class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        if not len(A):
            return []

        if len(A) == 1:
            return list(A[0])

        obj = self.strToMap(A[0])
        for i in range(1, len(A)):
            cur = self.strToMap(A[i])

            for c in obj:
                if c not in cur:
                    obj[c] = 0
                elif obj[c] > cur[c]:
                    obj[c] = cur[c]

        result = []

        for c in obj:
            if not obj[c]:
                continue
            for i in range(obj[c]):
                result.append(c)

        return result

    def strToMap(self, s: str) -> Dict[str, int]:
        obj = {}
        for c in s:
            if c not in obj:
                obj[c] = 1
            else:
                obj[c] += 1
        return obj


# s = Solution()
# s.commonChars(["bella", "label", "roller"])
# s.commonChars(["cool", "lock", "cook"])
