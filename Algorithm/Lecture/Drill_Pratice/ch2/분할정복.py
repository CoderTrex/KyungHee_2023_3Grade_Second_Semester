# # 이분 검색의 재귀적 방법
# def binaray_search_recursion(target, array, high, low):
#     mid = int(high/2)
#     if (array[mid] == target):
#         return mid
#     elif (array[mid] < target):
#         return binaray_search_recursion(target, array, high, mid+1)
#     elif (array[mid] > target):
#         return binaray_search_recursion(target, array, mid-1, low)

# array = []
# for i in range(1, 20):
#     array.append(i)

# location = -1

# location = binaray_search_recursion(5, array, 20, 0)
# print(location)



# 합병 정렬
def merge_sort(array):
    if (len(array) < 2):
        return array
    location = len(location)//2
    array_high = array[location:]
    array_low = array[:location]

    high = 0
    low = 0
    result = []
    while (low < len(array_low) and high < len(array_high)):
        if (array_low[low] < array_high[high]):
            result.append(array_low[low])
            low += 1
        else:
            result.append(array_high[high])
            high += 1

    result += array_high[high:]
    result += array_low[low:]
    return result


# 사이즈가 2이상이면 -> 재귀를 해서 내보냄

import random
index = []
for i in range(1, 20):
    index.append(random.randint(1, 200))

array = merge_sort(index)
print(array)    