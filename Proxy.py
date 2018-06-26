# -*- coding: utf-8 -*-

class Proxy(object):

    def __init__(self, target):
        self.target = target

    def __getattribute__(self, name):
        target = object.__getattribute__(self, "target")
        attr = object.__getattribute__(target, name)

        def newAttr(*args, **kwargs):
            print('before ')
            res = attr(*args, **kwargs)
            print('after ')
            return res
        return newAttr

class RealHello(object):

    def prints(self, s):
        print('hello', s)


if __name__ == '__main__':
    t = RealHello()
    p = Proxy(t)
    p.prints('wolrd')
