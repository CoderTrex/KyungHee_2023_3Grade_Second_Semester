import utility
inf = 1000
w=\
[[0, 1, 3,inf, inf],
[1, 0, 3,6, inf],
[3, 3, 0,4, 2],
[inf,6, 4,0, 5],
[inf,inf,2,5, 0]]
F=set()
utility.printMatrix(w)

n=len(w)
nearest=n*[0]
distance=n*[0]

for i in range(1,n):
    nearest[i]=0
    distance[i]=w[0][i]

for repeat in range(0,n-1):
    min = inf

#검색
    for i in range(1,n):
        if 0<distance[i] and distance[i]<min:
            min = distance[i]
            vnear = i

#추가
    distance[vnear] = 0 
    F.add((vnear + 1, nearest[vnear] + 1)) 
    # F.add((vnear + 1, nearest[vnear] + 1)) 

#갱신

    for i in range(1,n):
        if w[i][vnear] < distance[i]:  
            distance[i] = w[i][vnear]  
            nearest[i]=vnear
    
print()
print(F)