'''
Contest     : IEEEXtreme
Team Name   : AlgoExperts
Question    : Poker Game
Created on  : Monday, 26th October 2020 12:07:32 am
'''


import sys
import numpy
from enum import Enum

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


def main():
    N = get_number()
    K = get_number()
    community_cards = get_word()
    actions = get_word()

    count = {
        '2': [0, 0, True],
        '3': [0, 0, True],
        '4': [0, 0, True],
        '5': [0, 0, True],
        '6': [0, 0, True],
        '7': [0, 0, True],
        '8': [0, 0, True],
        '9': [0, 0, True],
        'X': [0, 0, True],
        'J': [0, 0, True],
        'Q': [0, 0, True],
        'K': [0, 0, True],
        'A': [0, 0, True]
    }

    missing_cards = K

    for i in range(len(actions)):
        card = community_cards[i]
        if actions[i] == 'y':
            if not (count[card][0] or count[card][1]):
                count[card] = [1, 1, True]
                missing_cards -= 1
            else: count[card][1] += 1
        else:
            if not count[card][2]:
                print('impossible')
                sys.exit()
            count[card][1] += 1
            count[card][2] = False

    if missing_cards == 0:
        output = ''
        for card in count:
            for _ in range(count[card][0]):
                output += card
        print(output)
        sys.exit()

    if missing_cards < 0:
        print('impossible')
        sys.exit()

    best_hand = ''

    sorted_cards = sorted(count.items(), key=lambda x: -x[1][0])

    for x in sorted_cards:
        num_cards = 4 - (x[1][0] + x[1][1])
        if missing_cards > num_cards:
            x[1][0] += num_cards
            best_hand += x[0] * x[1][0]
            missing_cards -= num_cards
        else:
            x[1][0] += missing_cards
            best_hand += x[0] * x[1][0]
            missing_cards = 0

    alphabet = "23456789XJQKA"
    ordered_hand = sorted(best_hand, key=lambda card: alphabet.index(card))
    new_hand = ''
    for card in ordered_hand:
        new_hand += card

    print(new_hand)


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
