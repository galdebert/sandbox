from . import module1f
from .. import module1a

def func1g():
    print('1g')
    module1f.func1f()
    module1a.func1a()
