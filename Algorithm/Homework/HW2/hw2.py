from utility import *

######################################################################################
################################## 1. Floyd 알고리즘 ##################################
######################################################################################

def allShortestPath(g,n):
    check_vertex = [[0 for j in range(len(g[0]))] for i in range(len(g))]

    # 해당 배열은 이미 자신으로 이동하는 경우의 수를 0으로 초기화를 했음
    # for i in range(n):
    #     for j in range(n):
    #         check_vertex[i][j] = 0
    #         if (i == j):
    #             g[i][j] = 0

    for k in range(n):
        for a in range(n):
            for b in range(n):
                # 최적화
                if (a == b):
                    continue
                # 알고리즘 2 : 최단 경로 경유 노드
                if ((g[a][k]+g[k][b]) < g[a][b]):
                    check_vertex[a][b] = k + 1

                # 알고리즘 1 : 최단 거리           
                # 이는 직접 가는게 빠른지 아니면 경유가 빠른지 계산한다.
                g[a][b] = min(g[a][b], g[a][k] + g[k][b])
    return g, check_vertex

inf=1000
g=\
[[  0,      1,    inf,      1,    5],
[   9,      0,      3,      2,  inf],
[   inf,    inf,    0,      4,  inf],
[   inf,    inf,    2,      0,    3],
[   3,      inf,  inf,    inf,    0]]


print("\n1. floyd 알고리즘\n")
printMatrix(g)
d, p = allShortestPath(g, 5)
print()
printMatrix(d)
print()
printMatrix(p)
print()


######################################################################################
############################ 2. 연쇄행렬 최소 곱셈 알고리즘 ############################
######################################################################################
# void order(index i, index j) {
#     if (i == j) 
#         cout << “A” << i;
#     else {
#         k = P[i][j];
#         cout << “(”;
#         order(i,k);
#         order(k+1,j);
#         cout << “)”;
#     }
# }

# int minmult(int n, const int d[], index P[][]) {
#     index i, j, k, diagonal;
#     int M[1..n][1..n];
#     for(i=1; i <= n; i++)
#         M[i][i] = 0;
#     for(diagonal = 1; diagonal <= n-1; diagonal++)
#         for(i=1; i <= n-diagonal; i++) {
#             j = i + diagonal;
#             M[i][j]= minimumi<=k<=j-1(M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j]); 
#             P[i][j] = 최소치를 주는 k의 값
#         }
#     return M[1][n];
# }


def order(p,i,j):
# 구현

    return 0


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