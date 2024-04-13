class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        maxReleaseChar = keysPressed[0]
        maxReleaseTime = releaseTimes[0]
        for i in range(1, len(releaseTimes)):
            newReleaseTime = releaseTimes[i] - releaseTimes[i - 1]
            if newReleaseTime > maxReleaseTime:
                maxReleaseTime = newReleaseTime
                maxReleaseChar = keysPressed[i]
            elif newReleaseTime == maxReleaseTime and keysPressed[i] > maxReleaseChar:
                maxReleaseChar = keysPressed[i]
        return maxReleaseChar
