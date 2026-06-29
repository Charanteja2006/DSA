class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        count = 0

        for l in patterns:
            if l in word:
                count += 1
        
        return count