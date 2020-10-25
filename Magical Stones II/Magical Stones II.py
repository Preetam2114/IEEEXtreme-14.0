'''
Contest     : IEEEXtreme
Team Name   : AlgoExperts
Question    : Magical Stones II
Created on  : Monday, 26th October 2020 12:11:33 am
'''


import sys
import numpy

if 'PyPy' in sys.version:
    from _continuation import continulet
else:
    import threading


def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

class Case:
    def __init__(self, N, w, b):
        self.N = N
        self.w = w
        self.b = b
    def count(self):
        return len(self.N) - 1
    def copy(self):
        return Case(self.N.copy(), self.w.copy(), self.b.copy())
    def white(self):
        newN = [0]
        for stone in self.N:
            newN.append(w[stone])
        self.N = set(newN)
    def black(self):
        newN = [0]
        for stone in self.N:
            newN.append(b[stone])
        self.N = set(newN)
    def write(self):
        st = ''
        for stone in self.N: st += str(stone)
        return st

def W(case: Case):
    newN = [0]
    for stone in case.N:
        newN.append(case.w[stone])
    case.N = set(newN)

def B(case: Case):
    newN = [0]
    for stone in case.N:
        newN.append(case.b[stone])
    case.N = set(newN)

def solve(case: Case):
    def case_op_combo(cs, oper):
        return cs.write(), oper.__name__
    
    operators = [W, B]
    visited = set()
    queue = []
    currStones = case.count()
    for op in operators:
        queue.append((case.copy(), op, ''))
        visited.add(case_op_combo(case, op))

    while True:
        if not queue:
            return 'impossible'
        case, op, path = queue.pop(0)
        op(case)
        sequence = path + op.__name__
        curr = case.count()
        if curr == 1:
            return sequence
        elif curr < currStones:
            currStones = curr
            queue = []
        for op in operators:
            curr = case_op_combo(case, op)
            if curr not in visited:
                visited.add(curr)
                if len(sequence) < pow(10, 6):
                    queue.append((case.copy(), op, sequence))

def main():
    T = get_number()
    for _ in range(T):
        n = get_number()
        w = [0]
        for _ in range(n):
            w.append(get_number())
        b = [0]
        for _ in range(n):
            b.append(get_number())
        case = Case(list(range(1, n+1)), w, b)
        print(solve(case))


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
