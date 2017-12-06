from . import module1a
from .subdir1 import module1c
#from . import subdir.module1c SyntaxError: invalid syntax

def func1b():
    print('1b')
    module1a.func1a()
    module1c.func1c()
    #subdir.module1c.func1c()
