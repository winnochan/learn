class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        doc = {}
        for i in range(len(arr1)):
            if arr1[i] not in doc:
                doc[arr1[i]] = [i]
            else:
                doc[arr1[i]].append(i)
        result = []
        for n in arr2:
            for i in doc[n]:
                result.append(arr1[i])
            del doc[n]
        for n in sorted(doc.keys()):
            for i in doc[n]:
                result.append(arr1[i])
        return result
