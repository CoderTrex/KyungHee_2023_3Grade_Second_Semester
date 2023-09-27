def quickSort(s,low, high):
    pivotpoint = 0
    if (high > low):
        pivotpoint = partition(s, low, high)
        quickSort(s, low, pivotpoint - 1)
        quickSort(s, pivotpoint + 1, high)

def partition(s, low, high):
    pivotitem = s[low]
    j = low
    for i in range(low + 1, high + 1):
        if (s[i] < pivotitem):
            j += 1
            tmp = s[i]
            s[i] = s[j]
            s[j] = tmp
    pivotpoint = j
    tmp = s[low]
    s[low] = s[pivotpoint]
    s[pivotpoint] = tmp
    return pivotpoint

s=[3,5,2,9,10,14,4,8]
quickSort(s,0,7)

print("\n4주차 2021103751 정은성 quick sort\n")
print(s)


from numpy import *
def strassen (n, A, B, C):
    threshold = 2
    A11 = array([[A[rows][cols] for cols in range(int(n/2))]for rows in range(int(n/2))])
    A12 = array([[A[rows][cols] for cols in range(int(n/2),int(n))]for rows in range(int(n/2))])
    A21 = array([[A[rows][cols] for cols in range(int(n/2))]for rows in range(int(n/2),int(n))])
    A22 = array([[A[rows][cols] for cols in range(int(n/2),int(n))]for rows in range(int(n/2),int(n))])
    B11 = array([[B[rows][cols] for cols in range(int(n/2))]for rows in range(int(n/2))])
    B12 = array([[B[rows][cols] for cols in range(int(n/2),int(n))]for rows in range(int(n/2))])
    B21 = array([[B[rows][cols] for cols in range(int(n/2))]for rows in range(int(n/2),int(n))])
    B22 = array([[B[rows][cols] for cols in range(int(n/2),int(n))]for rows in range(int(n/2),int(n))])
    if (n <= threshold):
        C = array(A) @ array(B)
    else:
        M1 = M2 = M3 = M4 = M5 = M6 = M7 = array([])
        M1=strassen(int(n/2), (A11 + A22), (B11 + B22), M1)
        M2=strassen(int(n/2), (A21 + A22), B11, M2)
        M3=strassen(int(n/2), A11, (B12 - B22), M3)
        M4=strassen(int(n/2), A22, (B21 - B11), M4)
        M5=strassen(int(n/2), (A11 + A12), B22, M5)
        M6=strassen(int(n/2), (A21 - A11), (B11 + B12), M6)
        M7=strassen(int(n/2), (A12 - A22), (B21 + B22), M7)

        C =  vstack([ hstack([M1+M4 -M5 + M7, M3 + M5]), hstack([M2 + M4, M1 - M2 + M3 + M6]) ])
    return C
n = 4
A=[ [1,2,0,2], [3,1,0,0], [0,1,1,2],[2,0,2,0]]
B=[ [0,3,0,2], [1,1,4,0], [1,1,0,2],[0,5,2,0]]
C = array(A)@array(B)
D = [[0 for cols in range(n)]for rows in range(n)]
print("\n4주차 2021103751 정은성 strassen\n")

print(C)
D=strassen(n, A, B, D)
print(D)