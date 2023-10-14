import utility
inf=1000
g=\
[[  0,      4,    inf,    inf,    4],
[   6,      0,    inf,    inf,  inf],
[   1,      2,      0,      1,  inf],
[ inf,    inf,      4,      0,  inf],
[   9,    inf,      3,      5,    0]]

vertex_ary = [[0 for i in range(len(g[0]))] for j in range(len(g))]



for k in range(0, 5):
    for i in range(0, 5):
        for j in range(0, 5):
            if (i == j):
                continue
            if ((g[i][k] + g[k][j]) < g[i][j]):
                vertex_ary[i][j] = k+1
                g[i][j] = g[i][k] + g[k][j]

utility.printMatrix(g)
# utility.printMatrix(vertex_ary)