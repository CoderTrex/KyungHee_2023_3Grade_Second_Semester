# import time
# star  t = time.time()  # 시작 시간 저장
# 작업 코드
# print("time :", time.time() - start)  # 현재시각 - 시작시간 = 실행 시간

# number = int(input())
# print(number)
# sum = 0
# if (number % 2 == 0):
#     sum = number / 2 * (1 + number)
# else:
#     sum = int(number / 2) * (1 + number) + int (number / 2)  + 1
    

# print(sum)


# list = [1, 2, 5, 3, 4]

# for i in range(len(list)):
#     j = i + 1
#     for  j in range(len(list)):
#         if (list[i] < list[j]):
#             tmp = list[i]
#             list[i] = list[j]
#             list[j] = tmp

# for i in range(len(list)):
#     print(list[i])



list = [29, 39, 40, 31, 59, 91, 100]
radix = 

count = 0
while (len(list) > 0):
    radix = int(radix / 2)
    count += 1

print(count)