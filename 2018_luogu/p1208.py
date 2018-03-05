[N, M] = [int(_) for _ in input().split()]
array = sorted(
    [[int(_) for _ in input().split()] for __ in range(0, M)],
    key=lambda _: _[0]
)
sum = 0
for [p, a] in array:
    if N - a <= 0:
        sum += p * N
        break
    else:
        sum += a*p
        N -= a
print(sum)
