import time
import unittest

class Timer:
    def __enter__(self):
        self.start = time.perf_counter()

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.end = time.perf_counter()
        runtime = self.end - self.start
        print("Runtime: ", runtime, " sec")



class MyRange:
    def __init__(self, start, stop, step=1):
        self.range = range(start, stop, step)

def myrange(*args):
    n = len(args)
    if n <= 0 or n > 3:
        raise TypeError("my range accept one to three arguments (start, stop , step")
    if n == 1:
        return MyRange(0,args[0]).range
    elif n == 2:
        return MyRange(args[0], args[1]).range
    elif n == 3:
        return MyRange(args[0], args[1], args[2]).range


class rangeTest(unittest.TestCase):

    def no_args(self):
        with self.assertRaises(TypeError):
            myrange()

    def more_args(self):
        with self.assertRaises(TypeError):
            myrange(1, 1, 1, 1)

    def args(self):
        self.assertEqual(range(5), myrange(5))
        self.assertEqual(range(0, 5), myrange(0, 5))
        self.assertEqual(range(1, 5, 2), myrange(1, 5, 2))

if __name__ == '__main__':
    unittest.main()


