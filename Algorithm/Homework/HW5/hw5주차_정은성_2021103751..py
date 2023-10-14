# import utility

######################################################################################
################################## HW2 알고리즘 과제 ##################################
######################################################################################

def printMatrix(d):
    m = len(d)
    n=len(d[0])
    for i in range(0,m):
        for j in range(0,n):
            print(f'{d[i][j]:4d}',end=" ")
        print()

#print float matrix
def printMatrixF(d):
    n=len(d[0])
    for i in range(0,n):
        for j in range(0,n):
            print(f'{d[i][j]:5.2f}',end=" ")
            print()

def print_inOrder(root):
    if not root:
        return
    print_inOrder(root.l_child)
    print(root.data)
    print_inOrder(root.r_child)

def print_preOrder(root):
    if not root:
        return
    print(root.data)
    print_preOrder(root.l_child)
    print_preOrder(root.r_child)

######################################################################################
################################## 1. Floyd 알고리즘 ##################################
######################################################################################

def allShortestPath(g, n):
    check_vertex = [[0 for j in range(len(g[0]))] for i in range(len(g))]
   
    for k in range(n):
        for a in range(n):
            for b in range(n):
                # 부분 최적화
                if a == b:
                    continue
                if (g[a][k] + g[k][b]) < g[a][b]:
                    
                    # 알고리즘 2: 최고 인덱스 찾기
                    check_vertex[a][b] = k + 1
                    
                    # 알고리즘 1: 최적 경로 찾기
                    g[a][b] = g[a][k] + g[k][b]
                    
    return g, check_vertex

inf=1000
g=\
[[  0,      4,    inf,    inf,    4],
[   6,      0,    inf,    inf,  inf],
[   1,      2,      0,      1,  inf],
[ inf,    inf,      4,      0,  inf],
[   9,    inf,      3,      5,    0]]

print("\n1. floyd 알고리즘\n")
print("-----------------original matrix:--------------------")
printMatrix(g)
d, p = allShortestPath(g, 5)
print()
print("----------short cut path calculated matrix:----------")
printMatrix(d)
print()
print("------------highest vertex in path matrix:-----------")
printMatrix(p)
print()

print("V2 to V4 path: ", end = "")
def get_path(a, b):
    if (p[a][b] != 0):
        get_path(a, p[a][b] - 1)
        print("V{} ".format(p[a][b]), end= " ")
        get_path(p[a][b] - 1, b)

get_path(1, 3)

print("\n")

######################################################################################
############################ 2. 연쇄행렬 최소 곱셈 알고리즘 ############################
######################################################################################

def order(p, i, j):
    if i == j:
        print("A" + str(i), end='')
    else:
        k = p[i][j]
        print("(", end='')
        order(p, i, k)
        order(p, k+1, j)
        print(")", end='')

# A1: 2×3 A2: 3×4 A3: 4×3 A4: 3×2 A5: 2×4
d = [2,3,4,3,2,4]
n = len(d) - 1

m = [[0 for j in range(1, n + 2)] for i in range(1, n + 2)]
p = [[0 for j in range(1, n + 2)] for i in range(1, n + 2)]

for diagonal in range(1, n):
    for i in range(1, n-diagonal+1):
        j = i + diagonal
        min_val = 9223372036854775807
        min_k = i
        for k in range(i, j):
            num = m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j]
            if num < min_val:
                min_val = num
                min_k = k
        m[i][j] = min_val
        p[i][j] = min_k

print("\n2. 연쇄행렬 최소 곱셈 알고리즘\n")
printMatrix(m)
print()
printMatrix(p)
order(p, 1, 5)