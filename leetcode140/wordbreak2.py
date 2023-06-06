import functools
from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        """Given a string s and a dictionary of strings wordDict, 
        add spaces in s to construct a sentence where each word is a valid dictionary word. 
        Return all such possible sentences in any order.
        Note that the same word in the dictionary may be reused multiple times in the segmentation.
        >>> s = Solution()
        >>> s.wordBreak("catsanddog", ["cat","cats","and","sand","dog"])
        ['cats and dog', 'cat sand dog']
        """
        wordSet = set(wordDict)

        @functools.lru_cache(None)
        def wordBreak(s: str) -> List[str]:
            ans = []
            for i in range(1, len(s)):
                prefix = s[0:i]
                suffix = s[i:]
                if prefix in wordSet:
                    for word in wordBreak(suffix):
                        ans.append(prefix + ' ' + word)

            if s in wordSet:
                ans.append(s)
            
            return ans
        
        return wordBreak(s)
    
if __name__ == '__main__':
    import doctest
    doctest.testmod()