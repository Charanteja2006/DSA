class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        sum = 0
        maxi = 0

        for n in gain:
            sum += n
            maxi = max(maxi,sum)
    
        return maxi
        