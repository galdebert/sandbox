import module_top_a
import module_top_b

from package1 import module1a
from package1 import module1b
from package1.subdir1 import module1c
from package1.subdir2 import module1d
from package1.subdir3 import module1e
from package1.subpackage1 import module1f
from package1.subpackage1 import module1g
from package1.subpackage2 import module1h

import package1 # allows to write package1.subdir1.module1c.func1c()

from package2 import module2a
from package2 import module2b

from dir3 import module3a
from dir3 import module3b
from dir3 import module3c
import dir3

import dir4
from dir4 import module4a

# root
#   main.py
#   module_top_a.py
#   module_top_b.py            from . import module_top_a              ImportError: attempted relative import with no known parent package
#                              import module_top_a                     OK
#   package1
#     __init__.py
#     module1a.py
#     module1b.py              from . import module1av                 OK
#                              from .subdir1 import module1c           OK
#     subdir1
#       module1c.py
#     subdir2
#       module1d.py            from ..subdir1 import module1c          OK .. works only inside top level package: package1
#     subdir3
#       module1e.py            from .. import module1a                 OK .. works only inside top level package: package1
#     subpackage1
#       __init__.py
#       module1f.py
#       module1g.py            from . import module1f                  OK
#                              from .. import module1a                 OK
#     subpackage2
#       __init__.py
#       module1h.py            from ..subpackage1 import module1g      OK
#   package2
#     __init__.py
#     module2a.py              from ..package1 import module1a         ValueError: attempted relative import beyond top-level package
#     module2b.py              from ..dir3 import module3a             ValueError: attempted relative import beyond top-level package
#   dir3
#     module3a.py
#     module3b.py              from . import module1a                  OK - but pylint makes an error: Attempted relative import beyond top-level package (relative-beyond-top-level)
#     module3c.py              from ..package1 import module1a         ValueError: attempted relative import beyond top-level package     as if dir3 is the top level package
#   dir4
#     module34.py              from ..dir3 import module3a             ValueError: attempted relative import beyond top-level package     as if dir4 is the top level package

# CONCLUSION
# put __init__.py in all sub directories, don't mess with "just directories"
#                 | import a.b | from a import b | from . import a | from .a import b | from ..c import d |
#  in main.py     |    YES     |    YES          |      NO         |      NO          |      NO           |
#  in a package   |    NO      |    NO           |      YES        |      YES         |      YES          |

# Note: from . import a.b     is invalid syntax


if __name__ == '__main__':
    print('----')
    module_top_a.func_top_a()

    print('----')
    module_top_b.func_top_b()

    print('----')
    module1a.func1a()
    package1.module1a.func1a()

    print('----')
    module1b.func1b()
    package1.module1b.func1b()

    print('----')
    module1c.func1c()
    package1.subdir1.module1c.func1c()

    print('----')
    module1d.func1d()
    package1.subdir2.module1d.func1d()

    print('----')
    module1e.func1e()
    package1.subdir3.module1e.func1e()

    print('----')
    module1f.func1f()
    package1.subpackage1.module1f.func1f()

    print('----')
    module1g.func1g()
    package1.subpackage1.module1g.func1g()

    print('----')
    module1h.func1h()
    package1.subpackage2.module1h.func1h()

    print('----')
    module2a.func2a()

    print('----')
    module2b.func2b()

    print('----')
    module3a.func3a()
    dir3.module3a.func3a()

    print('----')
    module3b.func3b()
    dir3.module3b.func3b()

    print('----')
    module3c.func3c()
    dir3.module3c.func3c()

    print('----')
    module4a.func4a()
    dir4.module4a.func4a()
