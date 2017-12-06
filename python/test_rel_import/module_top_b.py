#from . import module_top_a          ImportError: attempted relative import with no known parent package
import module_top_a

def func_top_b():
    print('top_b')
    module_top_a.func_top_a()
