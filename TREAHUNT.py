m,t,s,n = map(int, input().split())

l = [0]+[[0]+[list(map(int, input().split())) for _ in range(t)] for _ in range(m)]

visit_l = [[-1 for _ in range(t+1)] for _ in range(m+1)]
count = 0
i,j = 1, s
for ii in range(n-1):
    if visit_l[j][i] != -1:
        n -= ii+1
        count = ii-visit_l[j][i]
        break
    visit_l[j][i] = ii
    i,j = l[j][i]
if count != 0:
    n %= count
    for _ in range(n):
        i,j = l[j][i]
print(j)
