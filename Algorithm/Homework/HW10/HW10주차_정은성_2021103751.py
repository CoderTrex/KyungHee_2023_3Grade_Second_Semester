# 해의 총 개수, 
# 10번째 해, 
# 모든 해를 모두 찾기 위해 생성한 상태공간트리의 총 노드 수

cnt = 0
node = 0

def promising(i,col):
    vaild = True
    for k in range(i):
        if (col[i] == col[k] or abs(col[i] - col[k]) == abs(i - k)):
            return False
    return vaild

def queens(n, i, col): 
    global cnt
    global node
    if (i == n):
        cnt += 1
        if (cnt == 10):
            print("10th          node: {0}".format(col))
        return
    else:
        for k in range(n):
            node += 1
            col[i] = k
            if (promising(i, col)):
                queens(n, i+1, col)

n=8
col=(n)*[0]
start = 0
queens(n, start, col)
print()
print("solution  node cnt: {0}".format(cnt))
print()
print("Generated node cnt: {0}".format(node))
print()
