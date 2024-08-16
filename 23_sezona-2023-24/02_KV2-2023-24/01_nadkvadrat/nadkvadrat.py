def nadkvadrat(p1, p2, p3):
    xmin, xmax = min(p1[0], p2[0], p3[0]), max(p1[0], p2[0], p3[0])
    ymin, ymax = min(p1[1], p2[1], p3[1]), max(p1[1], p2[1], p3[1])
    dx, dy = xmax - xmin, ymax - ymin
    return max(dx, dy)**2

if __name__ == "__main__":
    t1 = tuple(map(int, input().split()))
    t2 = tuple(map(int, input().split()))
    t3 = tuple(map(int, input().split()))
    print(nadkvadrat(t1, t2, t3))
