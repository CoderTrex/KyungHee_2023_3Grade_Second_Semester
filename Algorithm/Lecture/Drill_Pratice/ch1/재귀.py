# https://richwind.co.kr/3

# 재귀
num = int(input())

def fibonacci(num):
    if (num == 1 or num == 2):
        return 1
    else:
        return fibonacci(num - 1) + fibonacci(num - 2)

result = fibonacci(num)
print(result)


# 반복적 방법
# num = int(input())

# fib = [0]*num
# fib[0] = 1
# fib[1] = 1

# for i in range(2, num):
#     fib[i] = fib[i - 1] + fib[i - 2]

# print(fib[num - 1])


# 동적계획법 / 메모라이제이션

# def fib(n):
#     fibList=[1, 1]
#     if n==1 or n==2:
#         return 1
#     for i in range(2,n):
#         fibList.append( fibList[i-1] + fibList[i-2] )
#     return fibList

# a = fib(5)
# print(a[4])