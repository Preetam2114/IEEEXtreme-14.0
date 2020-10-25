'''
Contest     : IEEEXtreme
Team Name   : AlgoExperts
Question    : Rotational Lights
Created on  : Saturday, 24th October 2020 4:58:04 pm
'''


import sys

if 'PyPy' in sys.version:
    from _continuation import continulet
else:
    import threading


def main():
    n, t = list(map(int, input().strip().split()))
    L = list(map(int, input().strip().split()))
    M = [False] * t
    for i in L:
        M[i] = True

    copy = M[:]
    a=0
    while True:
        popped = M.pop(-1)
        M.insert(0,popped)
        if(M == copy):
            print (a)
            break
        a+=1


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
