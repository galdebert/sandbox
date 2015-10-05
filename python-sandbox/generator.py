from unittest import TestCase, main

def get_negative_list(input):
    result = []
    for x in input:
        if x < 0:
            result.append(x)
    return result

def get_negative_gen(list):
    for x in list:
        if x < 0:
            yield x

class GeneratorTestCase(TestCase):

    def setUp(self):
        print("before test")

    def tearDown(self):
        print("after test")

    def test_get_negative_list(self):
        input = [1, -1, 2, -2]
        output = get_negative_list(input)
        for x in output:
            print(x)
        for x in get_negative_gen(input):
            print(x)

if __name__ == '__main__':
    main()