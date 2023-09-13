import random
import time

#선택 정렬
def selection_sort(random_list):
    small_one = 0
    location = 0

    print("\n\n\n")
    print("selection sort starts.")
    start = time.time()
    for i in range(len(random_list)):
        small_one = random_list[i]
        location = i
        for j in range(i + 1, len(random_list)):
            if (small_one > random_list[j]):
                small_one = random_list[j]
                location = j
        if (i != location):
            random_list[location] = random_list[i]
            random_list[i] = small_one

    end = time.time() - start
    return (random_list, end)

# 병합 정렬
def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    low_arr = merge_sort(arr[:mid])
    high_arr = merge_sort(arr[mid:])

    merged_arr = []
    low = 0
    high = 0
    while (low < len(low_arr) and high < len(high_arr)):
        if low_arr[low] < high_arr[high]:
            merged_arr.append(low_arr[low])
            low += 1
        else:
            merged_arr.append(high_arr[high])
            high += 1

    merged_arr += low_arr[low:]
    merged_arr += high_arr[high:]

    return merged_arr



while (1):
    try_number = int(input("시도 횟수 직접 혹은 아래 번호를 입력하시오.\n1. 5000 2. 10000\n"))

    if (try_number == 1):
        try_number = 5000
    elif (try_number == 2):
        try_number = 10000

    random_list = []
    for i in range(0, try_number):
        random_list.append(random.randint(1, 1000))
    print("this is random list\n",random_list)

    sort_method = int(input("실행하고자 하는 정렬 방식을 입력하시오\n1. 선택정렬 2. 병합정렬 3. 둘 다 4. 종료\n"))
    match sort_method:
        case 1:
            random_list, end = selection_sort(random_list)
            print(random_list)
            print("\n")
            print("time spend on selection sort: {0}".format(end))
        
        case 2:
            start = time.time()
            merge_list = merge_sort(random_list)
            end = time.time() - start
            print(merge_list)
            print("\n")
            print("time spend on merge sort: {0}".format(end))
        
        case 3:
            random_list, end_selection = selection_sort(random_list)
            print("selection sort list:\n", random_list)
            print("\n")
            
            start = time.time()
            merge_list = merge_sort(random_list)
            end_merge = time.time() - start
            print("merge sort list:\n", merge_list)
            print("\n")
            
            print("n:                            {0}".format(try_number))
            print("time spend on selection sort: {0}".format(end_selection))
            print("time spend on merge sort:     {0}".format(end_merge))
            
        case 4:
            exit()
        
        case _:
            print("wrong number.. plz input the number 1~4")
