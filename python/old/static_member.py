#!/usr/bin/env python3

def make_myfunc():
    _my_static_var = 0

    def _my_func_impl():
        nonlocal _my_static_var
        _my_static_var += 1
        return _my_static_var
    return _my_func_impl


myfunc = make_myfunc()

print(myfunc())
print(myfunc())

class myclass:
    _my_static_var = 0

    @staticmethod
    def myfunc():
        myclass._my_static_var += 1
        return myclass._my_static_var


print(myclass.myfunc())
print(myclass.myfunc())


class myclass2:
    _my_static_var = 0

    @classmethod
    def myfunc(cls):
        cls._my_static_var += 1
        return cls._my_static_var


print(myclass2.myfunc())
print(myclass2.myfunc())
