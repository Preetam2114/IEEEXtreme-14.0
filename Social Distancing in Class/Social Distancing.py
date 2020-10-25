'''
Contest     : IEEEXtreme
Team Name   : AlgoExperts
Question    : Social Distancing
Created on  : Monday, 26th October 2020 12:01:56 am
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


class Student:
    def __init__(self):
        self.bffs = []
        self.bff_pos = 1
    def set_pos(self, x: int):
        self.pos = x
    def add_bff(self, stu: Student):
        self.bffs.append(stu)
        self.opp_pos = stu.pos
    

class Classroom:
    def __init__(self):
        stu = Student()
        stu.set_pos(0)
        self.students = [stu]
        self.count = 1

    def addStudent(self, bff: int):
        self.count += 1
        stu = Student()
        self.students.append(stu)
        self.students[bff-1].add_bff(stu)
def main():
    N = get_number()
    cr = Classroom()
    for _ in range(N-1):
        bff = get_number()
        cr.addStudent(bff)

    for s in cr.students:
        print(s, s.bffs)



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
