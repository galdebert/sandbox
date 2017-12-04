import subprocess
import time
import sys
import asyncio
import sys
import threading
import queue

def simple():
    print('#### for line in process.stdout')
    process = subprocess.Popen(['py', '-u', './child_process_produce.py'], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, universal_newlines=True)
    for line in process.stdout:
        print(f'consumed: {line}', end='')


def readline():
    print('#### while True: sleep(3) readline()')
    process = subprocess.Popen(['py', '-u', './child_process_produce.py'], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, universal_newlines=True)

    while True:
        print('consumer sleeping for 3s')
        time.sleep(3)
        line = process.stdout.readline() # block untill a line or EOF is read
        if not line:
            print('EOF')
            break
        print(f'consumed: {line}', end='')


def thread_():
    def process_thread_func(process_stdout, lines):
        for line in iter(process_stdout.readline, b''):
            lines.put(line)
        process_stdout.close()

    # read the process output in a thread, output is stored in a queue: lines
    process = subprocess.Popen(['py', '-u', './child_process_produce.py'], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, bufsize=1, universal_newlines=True)
    lines = queue.Queue()
    thread = threading.Thread(target=process_thread_func, args=(process.stdout, lines))
    thread.daemon = True # thread dies with the program
    thread.start()

    # read line without blocking
    while True:
        try:
            line = lines.get_nowait() # or line_queue.get(timeout=.1)
        except queue.Empty:
            print('consumer sleeping for 3s')
            time.sleep(3)
        else: # line available
            if not line:
                break
            print(f'consumed: {line}', end='')


def async_():
    print('#### read asynchronously')

    async def run_process():
        # start child process
        cmd = ['py', '-u', './child_process_produce.py']
        process = await asyncio.create_subprocess_exec(*cmd, stdout=asyncio.subprocess.PIPE, stderr=asyncio.subprocess.STDOUT)

        # read line (sequence of bytes ending with b'\n') asynchronously
        async for bin_line in process.stdout:
            line = bin_line.decode("utf-8")
            print("consumed:", line, end='')
        return await process.wait() # wait for the child process to exit

    if sys.platform == "win32":
        loop = asyncio.ProactorEventLoop()
        asyncio.set_event_loop(loop)
    else:
        loop = asyncio.get_event_loop()

    loop.run_until_complete(run_process())


if __name__ == "__main__":
    if sys.argv[1] == 'simple':
        simple()
    if sys.argv[1] == 'readline':
        readline()
    if sys.argv[1] == 'thread':
        thread_()
    if sys.argv[1] == 'async':
        async_()