# libuv

http://docs.libuv.org/en/v1.x/design.html


- simple abstraction over different I/O polling mechanisms
- ‘handles’ and ‘streams’ provide a high level abstraction for sockets and other entities
- cross-platform file I/O 
- cross-platform threading functionality
- other things

# Handles and requests

libuv provides users with 2 abstractions to work with, in combination with the event loop: handles and requests.

**Handles** represent long-lived objects capable of performing certain operations while active. Some examples:
- A prepare handle gets its callback called once every loop iteration when active.
- A TCP server handle that gets its connection callback called every time there is a new connection.

**Requests** represent (typically) short-lived operations. These operations can be performed over a handle: write requests are used to write data on a handle; or standalone: getaddrinfo requests don’t need a handle they run directly on the loop.

# The I/O (or event) loop

all (network) I/O is performed on **non-blocking sockets which are polled using the best mechanism available on the given platform**:
- epoll on Linux
- kqueue on OSX and other BSDs
- event ports on SunOS
- IOCP on Windows


Network I/O: is always performed in a single thread, each loop’s thread.

File I/O: there are no platform-specific file I/O primitives libuv could rely on, so the current approach is to run blocking file I/O operations in a thread pool.

