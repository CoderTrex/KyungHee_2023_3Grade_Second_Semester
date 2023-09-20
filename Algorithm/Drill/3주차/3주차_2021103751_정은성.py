def bs(data, item, low, high):
    if (low > high):
        return -1
    else:
        mid = int((high + low)/2) 
        if (data[mid] == item):
            return mid
        elif (data[mid] < item):
            return bs(data, item, mid+1, high)
        elif (data[mid] > item):
            return bs(data, item, low, mid-1)

data = [1,3,5,7,9,14,17,19]

n = 10
location = bs(data, 17, 0, n-1)
print("찾지 못하면 -1을 반환")
print(location)



def mergeSort2(array, low, high):
    width = 1
    array_len = len(array)
    while (width < high):
        left = low
        while (left < high):
            right = left + width * 2 - 1
            mid = left + width - 1
            if (right > array_len - 1):
                right = array_len - 1
            if (mid > array_len - 1):
                mid  = array_len - 1
            merge2(array, left, mid, right)
            left = right + 1
        width*=2
    return array


def merge2(array, left, mid, right):
    #왼쪽 배열 길이 중간에서 왼쪽 이동 거리에 + 1
    #오른쪽 배열 길이 마지막에서 중간까지
    left_array_len = mid - left + 1
    right_array_len = right - mid

    left_array = [[0] for i in range(0, left_array_len)]
    right_array = [[0] for i in range(0, right_array_len)]

    for i in range(0, left_array_len):
        left_array[i] = array[left+i]
    for i in range(0, right_array_len):
        right_array[i] = array[mid+i+1]

    i = 0 
    j = 0
    k = left
    while (i < left_array_len and j < right_array_len):
        if (left_array[i] <= right_array[j]):
            array[k] = left_array[i]
            k+=1
            i+=1
        else:
            array[k] = right_array[j]
            k+=1
            j+=1
    
    while (i < left_array_len):
        array[k] = left_array[i]
        k+=1
        i+=1

    while (j < right_array_len):
        array[k] = right_array[j]
        k+=1
        j+=1

s=[3,5,2,9,10,14,4,8]
mergeSort2(s,0,7)
print("비재귀 합병 정렬:\n{0}".format(s))

# import random
# index = []
# for i in range(1, 20):
#     index.append(random.randint(1, 200))

# array = mergeSort2(index, 0, 19)
# print(array) 
    