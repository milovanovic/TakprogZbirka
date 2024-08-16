def sudar(x, y):
    xrev, yrev = x[::-1], y[::-1]
    lenx, leny = len(x), len(y)
    lenmx = max(lenx, leny)
    rrev = ''
    try:
        for i in range(lenmx):
            if xrev[i] > yrev[i]:
                rrev += xrev[i]
            elif yrev[i] > xrev[i]:
                rrev += yrev[i]
            else:
                rrev += xrev[i] + yrev[i]
    except IndexError:
        if lenx > leny:
            rrev += x[:lenx-leny][::-1]
        elif leny > lenx:
            rrev += y[:leny-lenx][::-1]
    return rrev[::-1]

if __name__ == "__main__":
    print(sudar(input(), input()))
