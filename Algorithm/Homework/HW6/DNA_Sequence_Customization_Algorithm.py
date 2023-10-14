import utility
a=['C','A','G','A','C','T','A','A']
b=['C','C','G','C','T','A','C']

m=len(a)
n=len(b)

table=[[0 for j in range(0,n+1)] for i in range(0,m+1)]
minindex = [[ (0,0) for j in range(0,n+1)] for i in range(0,m+1)]

for j in range(n-1,-1,-1):
    table[m][j] =table[m][j+1]+2
for i in range(m-1,-1,-1):
    table[i][n] =table[i+1][n]+2
            
# 테이블 생성 구현
for i in range(m-1, -1, -1):
    for j in range(n-1, -1, -1):
        if (a[i] == b[j]):
            table[i][j] = table[i+1][j+1]
        else:
            table[i][j]=min(table[i+1][j+1]+1, table[i+1][j]+2, table[i][j+1]+2)
        
def minidx(i,j):
    if (m >= n):        
        if (table[i][j] == table[i][j+1] + 2): 
            minindex[i][j] = (i,j+1) 
            if (j+1<n): 
                minidx(i,j+1) 
        elif (table[i][j] == table[i+1][j] + 2): 
            minindex[i][j] = (i+1,j) 
            if (i+1<m): 
                minidx(i+1,j) 
        else: 
            minindex[i][j] = (i+1,j+1) 
            if (i+1<m and j+1<n): 
                minidx(i+1,j+1) 
    else:
        if (table[i][j] == table[i+1][j] + 2): 
            minindex[i][j] = (i+1,j) 
            if (i+1<m): 
                minidx(i+1,j) 
        elif (table[i][j] == table[i][j+1] + 2): 
            minindex[i][j] = (i,j+1) 
            if (j+1<n): 
                minidx(i,j+1) 
        else: 
            minindex[i][j] = (i+1,j+1) 
            if (i+1<m and j+1<n): 
                minidx(i+1,j+1) 

minidx(0,0) # 0,0에서 시작

utility.printMatrix(table)
x=0
y=0

while (x <m and y <n):
    tx, ty = x, y
    print(minindex[x][y])
    (x,y)= minindex[x][y]
    if x == tx + 1 and y == ty+1:
        print(a[tx]," ", b[ty])
    elif x == tx and y == ty+1:
        print(" - ", " ", b[ty])
    else:
        print(a[tx], " " , " -")

