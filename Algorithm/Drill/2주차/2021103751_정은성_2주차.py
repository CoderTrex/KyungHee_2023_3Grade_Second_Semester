# py 파일 1개 결과 스크린샷

# 주차_학번_이름.py .jpg .[ng]
# jpg png 압축 X


#교환 정렬
s = [3,2,5,7,1,9,4,6,8]
n = len(s)

for i in range(0, n - 1):
    for j in range(i, n):
        #오름차순 정렬
        if (s[i] > s[j]):
            tmp = s[i]
            s[i] = s[j]
            s[j] = tmp
print("1. 교환정렬[오름차순]:\n", s)

# 순차 정렬
def seqsearch(s, x):
    loc = -1
    for i in range(len(s)):
        if (s[i] == x):
            loc = i
    return loc

s = [3, 5, 2, 1, 7, 9]
loc = seqsearch(s, 4)
loc2 = seqsearch(s, 3)
print("1. 없는 경우 순차검색:\n", loc)
print("2. 있는 경우 순차검색:\n", loc2)
