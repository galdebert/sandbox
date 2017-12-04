#!/usr/bin/env python3

from unittest import TestCase, main

def get_negative_list(inpt):
    result = []
    for x in inpt:
        if x < 0:
            result.append(x)
    return result

def get_negative_gen(lst):
    for x in lst:
        if x < 0:
            yield x

class GeneratorTestCase(TestCase):

    def setUp(self):
        print("before test")

    def tearDown(self):
        print("after test")

    def test_get_negative_list(self):
        input_ = [1, -1, 2, -2]
        output = get_negative_list(input_)
        for x in output:
            print(x)
        for x in get_negative_gen(input_):
            print(x)


if __name__ == '__main__':
    main()
