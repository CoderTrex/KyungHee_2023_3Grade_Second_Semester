import time

def fibo_recursion(n):
    if (n == 1 or n == 2):
        return 1
    else:
        return fibo_recursion(n - 1) + fibo_recursion(n - 2)

def fibo_repeat(n):
    a = [0 for i in range(n)]
    a[0] = 1
    a[1] = 1
    if (n == 1 or n == 2):
        return 1
    else:
        for i in range(2, n):
            a[i] = a[i - 2] + a[i - 1]
    return a[n - 1]


number = 40

start_recur = time.time()
a = fibo_recursion(number)
finish_recur = time.time() - start_recur

start_repeat = time.time()
b = fibo_repeat(number)
finish_repeat = time.time() - start_repeat

print("result     \ta: {0}, b: {1}".format(a, b))
print("finish time\ta: {0}, b: {1}".format(finish_recur, finish_repeat))