import utility

print("""
######################################################################################
################################## HW6 알고리즘 과제 ##################################
######################################################################################
""")

print("""
######################################################################################
################################ 1.최적이진탐색 알고리즘 ###############################
######################################################################################
""")

class Node:
    def __init__(self, data):
        self.l_child = None
        self.r_child = None
        self.data = data

    def tree(self, key, r, i, j):
        k = r[i][j]
        if k == 0:
            return
        else:
            p = Node(key[k])
            p.l_child = self.tree(key, r, i, k-1)
            p.r_child = self.tree(key, r, k+1, j)
            return p

key = [" ", "A", "B", "C", "D", "E"]
p = [0, 4/16, 3/16, 6/16, 2/16, 1/16]
n = len(p) - 1
a = [[0 for j in range(n + 2)] for i in range(n + 2)]
r = [[0 for j in range(n + 2)] for i in range(n + 2)]

for i in range(1, n + 1):
    a[i][i - 1] = 0
    a[i][i] = p[i]
    r[i][i] = i
    r[i][i - 1] = 0

a[n + 1][n] = 0
r[n + 1][n] = 0

for diagonal in range(1, n):
    for i in range(1, n - diagonal + 1):
        j = i + diagonal
        min_cost = float('inf')
        for k in range(i, j + 1):
            cost = a[i][k - 1] + a[k + 1][j]
            if cost < min_cost:
                min_cost = cost
                root = k
        a[i][j] = min_cost + sum(p[i:j + 1])
        r[i][j] = root

utility.printMatrixF(a)
print()
utility.printMatrix(r)


root= Node(a).tree(key,r,1,n)
utility.print_inOrder(root)
print()
utility.print_preOrder(root)



print("""
######################################################################################
############################## 2. DNA 염기서열탐색 알고리즘 ############################
######################################################################################
""")

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
