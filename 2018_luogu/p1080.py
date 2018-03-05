from math import floor
n = int(input())
[ll, rr] = [int(x) for x in input().split()]
array = []
for _ in range(0, n):
    array.append([int(x) for x in input().split()])

array = sorted(array, key=lambda _:  _[0] * _[1])
array.insert(0, [ll, rr])
sum = 1
for [l, _] in array[:-1]:
    sum *= l
r = floor(sum / array[n][1])
if r == 0:
    r = 1
print(r)
