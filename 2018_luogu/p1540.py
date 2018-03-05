[M, N] = [int(x) for x in input().split()]
words = input().split()
mem = []

count = 0

for word in words:
    if word in mem:
        continue
    else:
        count = count + 1
        if len(mem) == M:
            mem.pop(0)
        mem.append(word)

print(count)
