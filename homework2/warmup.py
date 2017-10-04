from random import shuffle


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


def say(word):
    return 0


def triples():
    return 0


def powers():
    return 0


def interleave():
    return 0


def Cylinder():
    return 0


def make_crypto_functions():
    return 0


def random_name():
    return 0
