# import time
# star  t = time.time()  # 시작 시간 저장
# 작업 코드
# print("time :", time.time() - start)  # 현재시각 - 시작시간 = 실행 시간

number = int(input())
sum = 0
if (number % 2 == 0):
    sum = number / 2 * (1 + number)
else:
    sum = int(number / 2) * (1 + number) + int (number / 2)  + 1

print(int(sum))