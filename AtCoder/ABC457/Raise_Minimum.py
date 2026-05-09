import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = [0] + list(map(int, input().split()))

l, r = 1, 10**24
while l < r:
    mid = (l + r + 1) // 2
    tmpK = k
    for i in range(1, n + 1):
        if mid <= a[i]:
            continue
        tmpK -= (mid - a[i] + (i - 1)) // i
        if tmpK < 0:
            break
    if tmpK >= 0:
        l = mid
    else:
        r = mid - 1

print(l)
