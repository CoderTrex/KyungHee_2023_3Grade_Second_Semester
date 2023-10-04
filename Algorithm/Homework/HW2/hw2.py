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
    path = [[[] for j in range(len(g[0]))] for i in range(len(g))]
   
    for k in range(n):
        for a in range(n):
            for b in range(n):
                if a == b:
                    continue
               
                if (g[a][k] + g[k][b]) < g[a][b]:
                    check_vertex[a][b] = k + 1
                    g[a][b] = g[a][k] + g[k][b]
                   
                    print(len(path[a][k]))
                    if (len(path[a][k]) == 0):
                        path[a][b].append([k+1])
                    else:
                        path[a][b] = path[a][k] + [[k + 1]]
   
    return g, check_vertex, path


inf=1000
g=\
[[  0,      4,    inf,    inf,    4],
[   6,      0,    inf,    inf,  inf],
[   1,      2,      0,      1,  inf],
[ inf,    inf,      4,      0,  inf],
[   9,    inf,      3,      5,    0]]


print("\n1. floyd 알고리즘\n")
printMatrix(g)
d, p, path= allShortestPath(g, 5)
print()
printMatrix(d)
print()
printMatrix(p)
print()

print("V2 to V4 moving path is : {}".format(path[1][3]))

# for i in range(len(path)):
#     for j in range(len(path[i])):
#         print("a(v{0}) to b(v{1}): path{2}".format(i+1, j+1, path[i][j]))
print()
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

d = [5,2,3,4,6,7,8]
n = len(d) - 1

m = [[0 for j in range(1, n + 2)] for i in range(1, n + 2)]
p = [[0 for j in range(1, n + 2)] for i in range(1, n + 2)]

for diagonal in range(1, n):
    for i in range(1, n-diagonal+1):
        j = i + diagonal
        min_val = 1000
        min_k = i
        for k in range(i, j):
            num = m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j]
            if num < min_val:
                min_val = num
                min_k = k
        m[i][j] = min_val
        p[i][j] = min_k

printMatrix(m)
print()
printMatrix(p)
order(p, 1, 6)