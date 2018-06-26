# -*- coding: utf-8 -*-

class Solution(object):
    """
    Given a set of distinct integers, return all possible subsets
    Elements in a subset must be in non-descending order
    The solution set must not contain duplicate subset
    """
    def __init__(self, arg):
        super(, self).__init__()
        self.arg = arg

    def solve(self, s):
        s = set(s)
        s = list(s)
        # s is sorted and unique
        e = []

    def subsetHelper(self, result, list):
        
