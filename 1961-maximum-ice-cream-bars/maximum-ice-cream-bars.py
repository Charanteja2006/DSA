class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        count = 0
        i = 0
        l = len(costs)
        while i<l and coins >= costs[i]:
            count += 1
            coins -= costs[i]
            i += 1
        
        return count

        