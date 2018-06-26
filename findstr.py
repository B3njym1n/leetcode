# -*- coding: utf-8 -*-

class Solution(object):
    """
    KMP算法是标准解法，但是面试官并不想你直接用KMP算法O(m + n)
    常见错误2：coding style 不好
    变量命名、缩进、括号、变量名、异常检查、边界处理
    测试（主动写出合理的testcase)
    """
    # def __init__(self, arg):
    #     super(, self).__init__()
    #     self.arg = arg

    def sovle(self, source, target):
        if source == None or target == none:
            return -1
        else:
            i = 0
            while i < len(source) - len(target):
                if source[i: len(target)] == target:
                    return i
                else:
                    return -1

if __name__ == '__main__':
    s = Solution()
    source = 'abcdefg'
    target = 'cde'
    i = s.solve(source, target)
    print(i)
