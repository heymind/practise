[M, N, K, L, D] = [int(x) for x in input().split()]
hh = [0] * (M+1)
ll = [0] * (N+1)
for i in range(0, D):
    [x, y, p, q] = [int(_) for _ in input().split()]
    if x == p:
        ll[min(y, q)] += 1
    elif y == q:
        hh[min(x, p)] += 1


def solve(a, limit):
    return sorted(map(
        lambda _: _[0],
        sorted(enumerate(a), key=lambda _: _[1], reverse=True)[0:limit]
    ))


def do_print(a):
    print(' '.join([str(_) for _ in a]))


do_print(solve(hh, K))
do_print(solve(ll, L))
