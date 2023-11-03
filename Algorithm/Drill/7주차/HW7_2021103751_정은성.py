print("\n\n1. prim's algorithms\n\n")
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
print()
n=len(w)
nearest=n*[0]
distance=n*[0]

int_MAX = 999999


# prim’s 알고리즘 구현
for i in range(0, n-1):
    if (i == 0):
        for k in range(1,n):
            nearest[k]=0
            distance[k]=w[0][k]

    shortest = int_MAX
    vertex = 0
    for j in range(1, n):
        if (0 < distance[j] and distance[j] < shortest):
            shortest = distance[j]
            vertex = j
    
    F.add((vertex, nearest[vertex]))
    
    # 1번부터 다시 세팅
    for k in range(1, n):
        if (w[k][vertex] < distance[k]):
            # print(w[k][vertex], distance[k])
            distance[k] = w[k][vertex]
            nearest[k] = vertex

print()
print(F) # {(4, 2), (2, 0), (1, 0), (3, 2)}


print("\n\n2. kruskal algorithms\n\n")

parent = dict()
rank = dict()

def make_singleton_set(v):
    parent[v] = v
    rank[v] = 1

def find(v):
    if parent[v] != v:
        parent[v] = find(parent[v])
    return parent[v]

def union(r1, r2):
    if r1 != r2:
        if rank[r1] > rank[r2]:
            parent[r2] = r1
            rank[r1] += rank[r2]
        else:
            parent[r1] = r2
            if rank[r1] == rank[r2]: 
                rank[r2] += rank[r1]

def kruskal(graph):
    # Kruskal algorithm 구현
    for v in graph['vertices']:
        make_singleton_set(v)

    mst = []
    edges = sorted(graph['edges'])
    # print(edges)
    for t in edges:
        # print(t[1], t[2])
        p = find(t[1])
        q = find(t[2])
        # print(p, q)
        
        union(p,q)
        # 서로의 부모가 같다면 순환이므로 -> 조건에 들어가지 않는다.
        if p != q:
            mst.append(t)
            # print(mst)
    return mst

graph = {
    'vertices': ['A', 'B', 'C', 'D', 'E'],
    
    'edges': set([
    (1, 'A', 'B'),
    (3, 'A', 'C'),
    (3, 'B', 'C'),
    (6, 'B', 'D'),
    (4, 'C', 'D'),
    (2, 'C', 'E'),
    (5, 'D', 'E'),
    ])
}
mst=kruskal(graph)
print(mst) # {(2, 'C', 'E'), (4, 'C', 'D'), (1, 'A', 'B'), (3, 'A', 'C')}