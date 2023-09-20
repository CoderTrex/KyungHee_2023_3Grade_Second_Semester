# 합병 정렬
def merge_sort(array):
    if (len(array) < 2):
        return array
    location = len(array)//2
    array_high = merge_sort(array[:location])
    array_low = merge_sort(array[location:])

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
