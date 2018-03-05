import heapq
input()  # N
h = [int(_) for _ in input().split()]
heapq.heapify(h)
result = 0
while len(h) != 1:
    v = heapq.heappop(h)+heapq.heappop(h)
    result += v
    heapq.heappush(h, v)
print(result)
