def mergeSort(a):
    width = 1   
    array_len = len(a)                                         
    while (width < array_len):
        left=0
        while (left < array_len):
            right = min(left+(width*2-1), array_len-1)        
            mid = min(left+width-1, array_len-1)
            merge(a, left, mid, right)
            left += width*2
        width *= 2
    return a
   
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
 



def merge_sort(array):
    width = 1
    array_len = len(array)
    while (width < array_len):
        left = 1
        while (width < array_len):
            right = min(left+width*2-1, array_len-1) # 움직여햐는 위치를 2번 가면 마지막 위치
            mid = min(left+width-1, array_len-1) # 움직여야하는 위치에 대해서 중간 값
            merge(array, left, mid, right)
            left = right + 1
        width*=2


    return array


def merge(array, left, mid, right):
    left_array_len = mid - left + 1
    right_array_len = right - mid
    
    left_array = [[0] for i in range(0, left_array_len)]
    right_array = [[0] for i in range(0, right_array_len)]
    for i in range(0, left_array_len):
        left_array[i] = array[left+i]
    
    for i in range(0, right_array_len):
        left_array[i] = array[right+i]
    