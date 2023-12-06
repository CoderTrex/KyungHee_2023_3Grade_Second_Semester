# 1. 깊이 우선 탐색(Depth-First Search)을 이용한 0/1 Knapsack Problem 해결 함수
def kp(i, profit, weight):
    global bestset
    global maxp
    global node_count  # 노드 개수를 저장하는 변수
    node_count += 1  # 노드 생성 시 카운트 증가
    
    # 현재 선택한 아이템들이 용량을 초과하지 않고, 현재 이익이 최대 이익보다 크다면 업데이트
    if weight <= W and profit > maxp:
        maxp = profit
        bestset = include[:]
    
    # 현재 상태가 유망하다면 계속 진행
    if promising(i, weight, profit):
        include[i + 1] = 1  # i번째 아이템을 선택하는 경우
        kp(i + 1, profit + p[i + 1], weight + w[i + 1])
        include[i + 1] = 0  # i번째 아이템을 선택하지 않는 경우
        kp(i + 1, profit, weight)

# 1-1. 현재 상태가 유망한지 판단하는 함수
def promising(i, weight, profit):
    global maxp
    if weight >= W:
        return False
    total_weight = weight
    total_profit = profit
    j = i + 1
    while j < n and total_weight + w[j] <= W:
        total_weight += w[j]
        total_profit += p[j]
        j += 1
    if j < n:
        total_profit += (W - total_weight) * (p[j] / w[j])
    return total_profit > maxp

# 1-2. 주어진 데이터로 깊이 우선 탐색 실행
n = 4
W = 7
p = [18, 10, 12, 4]
w = [3, 5, 6, 4]

maxp = 0
include = [0, 0, 0, 0]
bestset = [0, 0, 0, 0]
node_count = 0  # 노드 개수를 초기화

kp(-1, 0, 0)
print("""
----------------
----1번 문제----
----------------
""")
print("최대 이익:", maxp)
print("선택한 아이템:", bestset)
print("노드 개수:", node_count)



# 2. 너비 우선 탐색(Breadth-First Search)을 이용한 0/1 Knapsack Problem 해결 함수
import queue

# 2-1. 노드 클래스 정의
class Node:
    def __init__(self, level, weight, profit, include):
        self.level = level
        self.weight = weight
        self.profit = profit
        self.include = include

# 2-2. 너비 우선 탐색 실행 함수
def kp_BFS():
    global maxProfit
    global bestset
    global total_nodes  # 노드의 총 개수를 저장하는 변수
    global max_queue_size  # 큐에 존재하는 데이터의 최대 개수를 저장하는 변수

    q = queue.Queue()  # 큐 생성 -> 노드를 담아둘 공간
    total_nodes = 0
    max_queue_size = 0
    root = Node(-1, 0, 0, n * [0])
    q.put(root)
    while not q.empty():
        max_queue_size = max(max_queue_size, q.qsize())  # 큐에 존재하는 데이터의 최대 개수 업데이트
        u = q.get()
        if (u.level != -1):
            print("level: {}, weight: {}, size: {}".format(u.level, u.weight, q.qsize()))
        total_nodes += 1  # 노드의 총 개수 증가
        if u.level == n - 1:
            if u.profit > maxProfit:
                maxProfit = u.profit
                bestset = u.include[:]
        else:
            v1 = Node(u.level + 1, u.weight + w[u.level + 1], u.profit + p[u.level + 1], u.include[:])
            v1.include[u.level + 1] = 1  # v1이 선택한 아이템을 표시
            v2 = Node(u.level + 1, u.weight, u.profit, u.include[:])
            if v1.weight <= W and v1.profit + compBound(v1) > maxProfit:
                q.put(v1)
            if v2.weight <= W and v2.profit + compBound(v2) > maxProfit:
                q.put(v2)


# 2-3. 상태의 상한값을 계산하는 함수
def compBound(u):
    if u.weight >= W:
        return 0
    total_weight = u.weight
    total_profit = u.profit
    j = u.level + 1
    while j < n and total_weight + w[j] <= W:
        total_weight += w[j]
        total_profit += p[j]
        j += 1
    if j < n:
        total_profit += (W - total_weight) * (p[j] / w[j])
    return total_profit

# 2-4. 주어진 데이터로 너비 우선 탐색 실행
n = 4
W = 7
p = [18, 10, 12, 4]
w = [3, 5, 6, 4]

include = [0] * n
maxProfit = 0
bestset = n * [0]
total_nodes = 0
max_queue_size = 0

kp_BFS()

print("""
----------------
----2번 문제----
----------------
""")
print("최대 이익:", maxProfit)
print("선택한 아이템:", bestset)
print("총 노드 개수(-1 노드를 계수할 때 조건/아니라면 -1를 하면 된다.):", total_nodes)
print("최대 큐 크기:", max_queue_size)