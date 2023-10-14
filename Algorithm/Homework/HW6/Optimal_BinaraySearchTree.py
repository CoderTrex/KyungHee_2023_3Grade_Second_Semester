import utility

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