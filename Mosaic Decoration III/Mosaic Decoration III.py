'''
Contest     : IEEEXtreme
Team Name   : AlgoExperts
Question    : Mosaic Decoration III 
Created on  : Sunday, 25th October 2020 2:19:48 pm
'''

import sys

if 'PyPy' in sys.version:
    from _continuation import continulet
else:
    import threading


def main():
    H,W,h,w=list(map(int,input().split()))
    tmp=0
    for i in range(h):
        line=list(map(int,input().split()))
        tmp+=sum(line)
    print(tmp*(H//h)*(W//w))


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