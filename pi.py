import math
a = 1.0
b = 1 / math.sqrt(2)
t = 1 / 4
p = 1.0
i = 0
while i < 1000:
    an = (a + b) / 2
    bn = math.sqrt(a * b)
    tn = t - p * (a - an) ** 2
    pn = 2*p
    a = an
    b = bn
    t = tn
    p = pn

    pi = ((a + b) ** 2) / (4 * t)
    i += 1
    print(pi)
