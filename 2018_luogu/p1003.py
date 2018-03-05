def input_int_list():
    return [int(x) for x in input().split()]


n = int(input())
list = []
for i in range(0, n):
    list.append(input_int_list())
point = input_int_list()

top = -2

for idx, layer in enumerate(list):
    if point[0] >= layer[0] and point[0] <= layer[0] + layer[2] \
            and point[1] >= layer[1] and point[1] <= layer[1] + layer[3]:
        top = idx

print(top + 1)

# Notes：
# 倒着找。。找到就打印退出
