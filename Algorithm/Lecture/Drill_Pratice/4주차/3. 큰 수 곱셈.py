def int_len(i):
    length = 0
    while (i > 0):
        i = i//10
        length+=1
    return length

def prod1(large_1, large_2):
    n = max(int_len(large_1), int_len(large_2))
    if (large_1 == 0 and large_2 == 0):
        return 0
    elif (n <= 4):
        return large_1*large_2
    else:
        m = n//2
        x = large_1//10**m
        y = large_1 %10**m
        z = large_2//10**m
        w = large_2 %10**m
        return (prod1(x, z)*10**(m*2)) + ((prod1(x, w) + prod1(y, z))*10**m) + (prod1(y, w))

                 
def prod2(large_1, large_2):
    n = max(int_len(large_1), int_len(large_2))
    if (large_1 == 0 and large_2 == 0):
        return 0
    elif (n <= 4):
        return large_1*large_2
    else:
        m = n//2
        x = large_1//10**m
        y = large_1 %10**m
        z = large_2//10**m
        w = large_2 %10**m
        r = prod2(x+y, w+z)
        p = prod2(x, z)
        q = prod2(y, w)
        return (p*10**(2*m) + (r-q-p)*10**m + q)

a=12345678123456783128912891289182222223092038942340932809428309482390483290483209840923928409384092840932840928409238409238509238532098530928209850923850924890238490328432094820948920328409389408204832984093280932892474275847548754837984321201202831092380121983012890820981093809123809123809123809132809280912
b=2345678923456789101010129103280132390203902390239023902809384092384278479843728937482838342093208402938092840932840928340932840932809238509325209350932859032850932850938509328509238509328509238509328509328509328509213891829312893129831092830912830918309128309128390128312091209830912381209389291800238109238091283

import time
stime = time.time()
result = a*b
time0 = time.time() - stime
print("단순 곱셈\n결과값: {0}, 시간: {1}".format(result, time0))

stime1 = time.time()
result1 = prod1(a, b)
time1 = time.time() - stime1
print("일반적인 방법\n결과값: {0}, 시간: {1}".format(result1, time1))

stime2 = time.time()
result2 = prod1(a, b)
time2 = time.time() - stime2
print("개선된 방법\n결과값: {0}, 시간: {1}".format(result1, time2))

# print(prod2(a,b))
# print(a*b)