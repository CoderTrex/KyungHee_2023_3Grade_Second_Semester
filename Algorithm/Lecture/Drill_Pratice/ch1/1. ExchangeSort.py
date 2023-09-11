s = [3,2,5,7,1,9,4,6,8]
n = len(s)

for i in range(0, n - 1):
    for j in range(i, n):
        # 내림차순 정렬
        # if (s[i] > s[j]):
        #오름차순 정렬
        if (s[i] > s[j]):
            tmp = s[i]
            s[i] = s[j]
            s[j] = tmp

print(s)