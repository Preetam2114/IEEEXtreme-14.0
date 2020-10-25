'''
Contest     : IEEEXtreme
Team Name   : AlgoExperts
Question    : Crafting Wooden Tables
Created on  : Sunday, 25th October 2020 12:55:25 pm
'''

import sys

if 'PyPy' in sys.version:
    from _continuation import continulet
else:
    import threading


def main():
    c,n,p,w=list(map(int,input().split()))

    ans=(w//c)
    if c<p and ans>n-(w//p):
        ans=n-(w//p)
    print(ans)


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
