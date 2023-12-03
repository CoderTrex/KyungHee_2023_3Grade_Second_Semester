import utility
n = 10
k = 8
array = [[0 for i in range(k)] for j in range(n)]
for i in range(0, n):
    for j in range(0, k):
        if (i == j or j == 0):
            array[i][j] = 1
        else:
            array[i][j] = array[i-1][j] + array[i-1][j-1]
utility.printMatrix(array)