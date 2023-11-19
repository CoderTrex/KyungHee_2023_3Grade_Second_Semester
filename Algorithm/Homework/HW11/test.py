














def promising(i: int) -> bool:
    for j in range(1, i + 1):
        if W[i][j] and vcolor[i] == vcolor[j]:
            # 인접한데 색깔까지 같다면 False
            return False
    return True


def m_coloring(i: int, m: int) -> bool:
    if promising(i):
        # 유망하거나 i번째까지 이상이 없는 경우
        if i == ver_num:
            # 무사히 leaf node까지 도달했다면
            global flag
            global cnt
            flag = True
            cnt += 1
        else:
            for color in range(1, m + 1):
                # 1부터 m까지 색깔을 넣음
                vcolor[i + 1] = color
                m_coloring(i + 1, m)


if __name__ == "__main__":
    ver_num, edge_num = map(int, input().split())       # 점점과 간선의 수
    W = [[0] * (ver_num + 1) for _ in range(ver_num + 1)]       # 인접행렬
    for _ in range(edge_num):
        # 인접행렬 만듬
        i, j = map(int, input().split())
        W[i][j] = 1
        W[j][i] = 1

    vcolor = [0] * (ver_num + 1)        # 색깔의 집합

    for m in range(1, ver_num + 1):
        # 최소의 m값을 출력하는 것
        flag = False        # 기본적으로 False로 나둔 후 색깔 칠하기가 가능하면 True로 변경
        cnt = 0
        m_coloring(0, m)
        if flag:
            # flag가 True라는 것은 색깔 칠하기가 가능하다는 의미
            print(m)
            print(cnt)
            exit()







def promising(i):
    j = 1 #SST를 탐색
    flag = True
    while j < i and flag:
        if W[i][j] and vcolor[i] == vcolor[j]: #W[i][j]가 연결되어 있으며, 두 노드의 색깔이 같다면
            flag = False
        j += 1
    return flag

def m_coloring(i):
    global count # 현재 발견한 solution 개수
    global m # 현재 사용 색깔 개수
    # 탐색
    if promising(i):
        if i == n: # 끝까지 탐색 -> 정답
            count+=1
        else:
            for color in range(1, m + 1): # 모든 가능 색깔 탐색
                vcolor[i + 1] = color
                m_coloring(i + 1) # 다음 재귀로 넘어가고 불가능하다면 backTracking

#input
n ,k = map(int, input().split())

W = [[0]*(n + 1) for _ in range(n + 1)]

for _ in range(k):
    a,b = map(int, input().split())
    W[a][b] = 1
    W[b][a] = 1

m = 1 # color 개수
vcolor = [0]*(n + 1) #노드 개수 (0, 1번, 2번, 3번, ... n번)
while True:
    count = 0
    m_coloring(0) #return count
    if count >=1 :
        break
    else: m += 1

print(m, count, sep="\n")


# void m_coloring(index i) {
#     int color;
#     if(promising(i))
#       if(i==n)
#           cout << vcolor[1] through vcolor[n];
#       else
#           for (color=1; color<=m; color++){
#               vcolor[i+1] = color;
#               m_coloring(i+1);
#           }
# }
# bool promising(index i) {
#     index j;
#     bool switch;
#     switch = true;
#     j=1;
#     while ( j<i && switch){
#         if(W[i][j] && vcolor[i]==vcolor[j]) // W[i][j]:연결표시. T or F
#             switch = false;
#         j++;
#     }
#     return switch;
# }