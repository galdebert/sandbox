#!/usr/bin/env python3

from unittest import TestCase, main


class SliceTestCase(TestCase):

    def test(self):
        a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        print("a[:2]={}".format(a[:2]))
        print("a[-2:]={}".format(a[-2:]))
        print("a[2:-2]={}".format(a[2:-2]))
        print("a[0:]={}".format(a[0:]))

if __name__ == '__main__':
    main()
