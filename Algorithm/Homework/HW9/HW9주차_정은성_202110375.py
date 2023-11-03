inf=1000

# w=[
#     [0,7,4,6,1],
#     [inf,0,inf,inf,inf],
#     [inf,2,0,5,inf],
#     [inf,3,inf,0,inf],
#     [inf,inf,inf,1,0]
# ]

w=[
    [0,     2,      3,      inf,    inf,    4],
    [inf,   0,      4,      5,      3,      inf],
    [inf,   inf,    0,      6,      2,      inf],
    [inf,   inf,    inf,    0,      2,      inf],
    [inf,   inf,    inf,    inf,    0,      inf],
    [inf,   inf,    inf,    inf,    1,      0]
]

n=len(w[0])

f=set()
touch=n*[0]
length=n*[0]
save_length=n*[0]
NoC=0

for i in range(1, len(w[0])):
    if (w[0][i] != inf):
        NoC += 1

for i in range(0, n-1):
    if (i == 0):
        for k in range(1, n):
            touch[k] = 0
            length[k]=w[0][k]

    min = inf
    vnear = 0
    for i in range(1, n):
        if (0 <= length[i] and length[i] < min):
            min = length[i]
            save_length[i] = min
            vnear = i
    
    f.add((touch[vnear], vnear))
    
    # 실제 인덱스와 같이 맞추기 위해서 +1을 한 코드
    # f.add((touch[vnear]+1, vnear+1))
    
    for i in range(1, n):
        if (length[vnear] + w[vnear][i] < length[i]):
            length[i] = length[vnear] + w[vnear][i]
            # save_length[i] = length[i]
            touch[i] = vnear

    length[vnear] = -1

print(f)
print(save_length)
print(NoC)
