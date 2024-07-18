import time
#재귀적방법
def fib1(n):
    if (n==0 or n==1):
        return 1
    else:
        return fib1(n-1) + fib1(n-2)

stime = time.time()
for i in range(0, 30):
    print( f'{i:2d} {fib1(i): 6d} {" 시간: "} {time.time()-stime:10.5f}')
print( f'{"총걸린시간: "} {i:2d} {time.time()-stime:10.5f}')
print("\n\n\n")

#비재귀적방법
def fib2(n):
    arr = [1, 1]
    if (n==0 or n==1):
        return 1
    else:
        for i in range(0, n+1):
            if (i==0 or i==1):
                continue
            else:
                arr.append(arr[i-1] + arr[i-2])
    return arr[n]

stime = time.time()
for i in range(0, 30):
    print( f'{i:2d} {fib2(i): 6d} {" 시간: "} {time.time()-stime:10.5f}')
print( f'{"총걸린시간: "} {i:2d} {time.time()-stime:10.5f}')