def matrix_multiplication(a, b):
    c = [[0 for col in range(len(a))] for row in range(len(a[0]))]

    for i in range(0, len(a)):
        for j in range(0, len(a[i])):
            for k in range(0, len(a[i])):
                c[i][j] =  c[i][j] + a[i][k] * b[k][j]
    return c

a = [[1,2],[3,4]]
b = [[4,1],[1,0]]
print(matrix_multiplication(a, b))