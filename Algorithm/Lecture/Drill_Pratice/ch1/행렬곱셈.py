import random

array1 = [[0 for col in range(3)] for row in range(3)]
array2 = [[0 for col in range(3)] for row in range(3)]
array3 = [[0 for col in range(3)] for row in range(3)]


for i in range(len(array1)):
    for j in range(len(array1[i])):
        array1[i][j] = random.randint(1, 10)
        array2[i][j] = random.randint(1, 10)

print(array1)
print("\n")
print(array2)
print("\n")

for i in range(len(array1)):
    for j in range(len(array1[i])):
        for k in range(len(array1[i])):
            array3[i][j] = array3[i][j] + array1[i][k] * array2[k][j]

print(array3)