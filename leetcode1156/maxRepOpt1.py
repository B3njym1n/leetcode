from typing import Iterator, Tuple
import itertools
import collections

class Solution:
    def maxRepOpt1(self, text: str) -> int:
        count = collections.Counter(text)
        groups= [[c, sum(1 for _ in group)] for c, group in itertools.groupby(text)]
        m = max(min(length+1, count[c]) for c, length in groups)

        for i in range(1, len(groups)-1):
            if (groups[i-1][0] == groups[i+1][0] and groups[i][1]==1):
                m = max(
                    m,
                    min(groups[i-1][1]+groups[i+1][1]+1, count[groups[i-1][0]])
                )

        return m

if __name__ == '__main__':
    # text = "ababa"
    text = "aaabaaa"
    s = Solution()
    print(s.maxRepOpt1(text))