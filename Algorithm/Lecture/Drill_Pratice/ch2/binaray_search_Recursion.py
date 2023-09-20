# 이분 검색의 재귀적 방법
def binaray_search_recursion(target, array, high, low):
    mid = int(high/2)
    if (array[mid] == target):
        return mid
    elif (array[mid] < target):
        return binaray_search_recursion(target, array, high, mid+1)
    elif (array[mid] > target):
        return binaray_search_recursion(target, array, mid-1, low)

array = []
for i in range(1, 20):
    array.append(i)

location = -1

location = binaray_search_recursion(5, array, 20, 0)
print(location)