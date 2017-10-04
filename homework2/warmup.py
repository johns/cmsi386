from random import shuffle
import math


def change(c):
    if c < 0:
        raise ValueError('amount cannot be negative')
    quarters = divmod(c, 25)
    dimes = divmod(quarters[1], 10)
    nickles = divmod(dimes[1], 5)
    return quarters[0], dimes[0], nickles[0], nickles[1]


def strip_quotes(quote):
    quote = quote.replace('\'', '')
    quote = quote.replace('"', '')
    return quote


def scramble(s):
    s = list(s)
    shuffle(s)
    return ''.join(s)


def say(x): return "oops"
    # if !x:
    #     return ''
    # def sayMore(y):
    #     if y:
    #         return say(x, ' ', y)
    #     return s
    # return sayMore


def triples(): return 0


def powers(base, limit):
    exponent = 0
    current = 1
    while current <= limit:
        yield current
        exponent = exponent + 1
        current = base ** exponent


def interleave(): return "oops"


class Cylinder:
    def __init__(self, radius=1, height=1):
        self.radius = radius
        self.height = height
        self.volume = None
        self.surface_area = None
        self.getMeasurements()

    def stretch(self, factor):
        self.height *= factor
        self.getMeasurements()
        return self

    def widen(self, factor):
        self.radius *= factor
        self.getMeasurements()
        return self

    def getMeasurements(self):
        self.volume = math.pi * (self.radius ** 2) * self.height
        self.surface_area = 2 * math.pi * self.radius * (self.radius + self.height)
        return self


def make_crypto_functions(): return 0


def random_name(): return 0
