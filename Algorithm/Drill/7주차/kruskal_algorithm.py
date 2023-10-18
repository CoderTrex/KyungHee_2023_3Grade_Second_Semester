parent = dict()
rank = dict()

def make_singleton_set(v):
    parent[v] = v
    rank[v] = 1

def find(v):
    if parent[v] != v:
        parent[v] = find(parent[v])
    return parent[v]

# 서로 순환이 되지 않기하기 위해서 
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
    lst = sorted(graph['edges'])
    print(lst)
    for t in lst:
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
print(mst)