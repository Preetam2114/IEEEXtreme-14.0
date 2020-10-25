'''
Contest     : IEEEXtreme
Team Name   : AlgoExperts
Question    : Rescue Mission
Created on  : Sunday, 25th October 2020 12:47:09 am
'''


import sys

if 'PyPy' in sys.version:
    from _continuation import continulet
else:
    import threading


def main():
    n = list(map(int,sys.stdin.readline().strip().split()))[0]
    s = list(map(int,sys.stdin.readline().strip().split()))
    d = list(map(int,sys.stdin.readline().strip().split()))[0]
    details = []
    for _ in range(d):
        details.append(list(map(int,sys.stdin.readline().strip().split())))
    maxres = 0
    for detail in details:
        maxres += detail[2]
    print(maxres)


if __name__ == '__main__':
    if 'PyPy' in sys.version:

        def bootstrap(cont):
            call, arg = cont.switch()
            while True:
                call, arg = cont.switch(to=continulet(lambda _, f, args: f(*args), call, arg))

        cont = continulet(bootstrap)
        cont.switch()

        main()

    else:
        sys.setrecursionlimit(1 << 30)
        threading.stack_size(1 << 27)

        main_thread = threading.Thread(target=main)
        main_thread.start()
        main_thread.join()
