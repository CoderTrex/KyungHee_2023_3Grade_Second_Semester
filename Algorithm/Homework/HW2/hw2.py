import utility

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
utility.printMatrix(g)
d, p = allShortestPath(g, 5)
print()
utility.printMatrix(d)
print()
utility.printMatrix(p)
print()


######################################################################################
############################ 2. 연쇄행렬 최소 곱셈 알고리즘 ############################
######################################################################################

def order(p,i,j):
# 구현
    return 0

d=[5,2,3,4,6,7,8]
n=len(d)-1
m=[[0 for j in range(1,n+2)] for i in range(1,n+2)]
p=[[0 for j in range(1,n+2)] for i in range(1,n+2)]
# 구현
print("\n2. 연쇄행렬 최소 곱셈 알고리즘\n")
utility.printMatrix(m)
print()
utility.printMatrix(p)
order(p,1,6)