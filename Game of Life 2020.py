'''
Contest     : IEEEXtreme
Team Name   : AlgoExperts
Question    : Game of Life 2020
Created on  : Sunday, 25th October 2020 1:56:57 am
'''


import sys

if __name__=="__main__":
    a,b = map(str,input().split(";"))
    n,m = map(int,input().split(";"))
    matrix = []
    for i in range(n):
        a =[] 
        for j in range(n):
            a.append(int(input()))
        matrix.append(a)


