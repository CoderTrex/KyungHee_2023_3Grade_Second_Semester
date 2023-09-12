import random
import time

try_number = int(input("시도 횟수 직접 혹은 아래 번호를 입력하시오.\n1. 5000 2. 10000\n"))

if (try_number == 1):
    try_number = 5000
elif (try_number == 2):
    try_number = 10000

random_list = []
for i in range(0, try_number):
    random_list.append(random.randint(1, 1000))

# print("this is random list\n",random_list)
# #선택 정렬

# small_one = 0
# location = 0

# print("\n\n\n")
# print("selection sort starts.")
# start = time.time()
# for i in range(len(random_list)):
#     small_one = random_list[i]
#     location = i
#     for j in range(i + 1, len(random_list)):
#         if (small_one > random_list[j]):
#             small_one = random_list[j]
#             location = j
#     if (i != location):
#         random_list[location] = random_list[i]
#         random_list[i] = small_one

# end = time.time() - start
# print(random_list)
# print("\n")
# print("time spend on selection sort: {0}".format(end))

def merge_sort(arr):
    if len(arr) < 2:
        return arr

    mid = len(arr) // 2
    low_arr = merge_sort(arr[:mid])
    high_arr = merge_sort(arr[mid:])

    merged_arr = []
    l = h = 0
    while l < len(low_arr) and h < len(high_arr):
        if low_arr[l] < high_arr[h]:
            merged_arr.append(low_arr[l])
            l += 1
        else:
            merged_arr.append(high_arr[h])
            h += 1
    merged_arr += low_arr[l:]
    merged_arr += high_arr[h:]
    return merged_arr


merge_list = merge_sort(random_list)
print(merge_list)

# try_merge = try_number - 1
# count_merge = 0
# while (try_merge > 0):
#     try_merge = int(try_merge/2)
#     count_merge += 1
# print("merge sort 실행횟수: ", count_merge)


# arrA = []
# arrB = []

# for i in range(1, count_merge + 1):
#     size = 2 ** i
#     for index in range(0, try_number, size):
#         mid = int(size/2)
#         for j in range(index, index + mid):
#             if (i%2 == 0):