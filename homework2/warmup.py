def change(c):
    quarters = divmod(c, 25)
    dimes = divmod(quarters[1], 10)
    nickles = divmod(dimes[1], 5)
    return quarters[0], dimes[0], nickles[0], nickles[1]
