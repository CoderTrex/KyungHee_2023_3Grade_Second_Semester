def mergeSort(arru):
    width = 1   
    array_len = len(arru)                                         
    while (width < array_len):
        left=0
        while (left < array_len):
            right = min(left+(width*2-1), array_len-1)        
            mid = min(left+width-1, array_len-1)
            merge(arru, left, mid, right)
            left += width*2
        width *= 2
    return arru
   
def merge(array, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    Left_array = [0] * n1
    Right_array = [0] * n2
    for i in range(0, n1):
        Left_array[i] = array[left + i]
    for i in range(0, n2):
        Right_array[i] = array[mid + i + 1]
 
    i, j, k = 0, 0, left
    while i < n1 and j < n2:
        if Left_array[i] <= Right_array[j]:
            array[k] = Left_array[i]
            i += 1
        else:
            array[k] = Right_array[j]
            j += 1
        k += 1
 
    while i < n1:
        array[k] = Left_array[i]
        i += 1
        k += 1
 
    while j < n2:
        array[k] = Right_array[j]
        j += 1
        k += 1

import random
index = []
for i in range(1, 20):
    index.append(random.randint(1, 200))

array = mergeSort(index)
print(array) 
    