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
