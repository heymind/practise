[N, M] = [int(_) for _ in input().split()]
array = [int(_) for _ in input().split()]
count = 0
sum = 0
for i in array:
    if sum + i <= M:
        sum += i
    else:
        count += 1
        sum = i
print(count+1)
