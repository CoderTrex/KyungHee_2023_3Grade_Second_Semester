def matrix_multiplication(a,b):
    result = [[0, 0] for i in range(2)]
    for i in range(len(a)):
        for j in range(len(a)):
            for k in range(len(a)):
                result[i][j] = result[i][j] + a[i][k]*b[k][j]
    return result

a=[ [1,2],[3,4]]
b=[ [4,1],[1,0]]
print(matrix_multiplication(a,b))