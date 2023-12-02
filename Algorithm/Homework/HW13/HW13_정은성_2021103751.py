import math

class Heap(object):
    n = 0
    def __init__(self, data):
        self.data = data
        # heap size를 하나 줄여야 한다. 인덱스는 1부터. 인덱스의 2* 연산 가능하도록.
        self.n = len(self.data) - 1

    def addElt(self, elt):
        # 조건 1: 데이터가 입력되는 순서대로 heap을 매번 구성
        self.data.append(elt)
        self.n += 1
        self.siftUp(self.n)

    def siftUp(self, i):
        # siftUp 메서드는 주어진 인덱스 i에서 시작하여 부모 노드로 올라가면서
        # 힙 속성을 만족하도록 원소를 재배치
        while i >= 2 and self.data[i] > self.data[i // 2]:
            # i가 2 이상이면서 현재 노드의 값이 부모 노드의 값보다 큰 동안 반복
            # 부모 노드의 값과 현재 노드의 값을 교환
            self.data[i], self.data[i // 2] = self.data[i // 2], self.data[i]
            # i를 부모 노드의 인덱스로 갱신하여 계속해서 부모 방향으로 진행
            i //= 2    

    def siftDown(self, i):
        # siftDown 메서드는 주어진 인덱스 i에서 시작하여 자식 노드로 내려가면서
        # 힙 속성을 만족하도록 원소를 재배치하는 역할
        while 2 * i <= self.n:
            # 현재 노드 i에 대한 왼쪽 자식 노드의 인덱스를 계산
            j = 2 * i
            # 만약 오른쪽 자식 노드가 존재하고, 오른쪽 자식의 값이 더 크다면
            if j < self.n and self.data[j] < self.data[j + 1]:
                # 오른쪽 자식과 비교하여 더 큰 자식 노드의 인덱스를 j로 갱신
                j += 1
            # 현재 노드의 값이 자식 노드 중에서 가장 큰 값보다 크거나 같으면 더 이상의 작업이 필요 없으므로 break
            if self.data[i] >= self.data[j]:
                break
            # 현재 노드의 값과 가장 큰 자식 노드의 값을 교환
            self.data[i], self.data[j] = self.data[j], self.data[i]
            # i를 자식 노드의 인덱스로 갱신하여 계속해서 자식 방향으로 진행
            i = j


    def makeHeap1(self):
        # makeHeap1 메서드는 주어진 데이터로부터 Heap을 생성 
        # 데이터가 입력되는 순서대로 Heap을 매번 구성하는 방식
        for i in range(2, self.n + 1):
            # 2부터 n까지의 인덱스에 대해 siftUp 메서드를 호출하여
            # 데이터가 입력되는 순서대로 Heap을 매번 구성
            self.siftUp(i)


    def makeHeap2(self):
        # makeHeap2 메서드는 주어진 데이터로부터 Heap을 생성하는데,
        # 모든 데이터를 트리에 넣은 상태에서 Heap을 구성하는 방식
        for i in range(self.n // 2, 0, -1):
            # n//2부터 1까지의 인덱스에 대해 siftDown 메서드를 호출하여
            # 데이터가 트리에 모두 들어간 상태에서 Heap을 구성
            self.siftDown(i)

    def root(self):
        # 추가 하였음. 힙이 더 이상 없을 때는 down 없음
        return self.data[1] if self.n > 0 else None

    def removeKeys(self):
        while self.n > 0:
            self.data[1], self.data[self.n] = self.data[self.n], self.data[1]
            self.n -= 1
            self.siftDown(1)

    @staticmethod
    def heapSort(a):
        heap = Heap(a)
        heap.makeHeap2()
        heap.removeKeys()
        # 정렬 결과를 역순으로 반환
        return heap.data[1:][::-1]

# makeheap1 / 방법1: 데이터가 입력되는 순서대로 heap을 매번 구성
a1 = [0, 11, 14, 2, 7, 6, 3, 9, 5]
b1 = Heap(a1)
b1.makeHeap1()
print("Heap 1:", b1.data[1:])

# heapSort
s1 = Heap.heapSort(a1)
print("Sorted Heap 1:", s1)

# makeheap2 / 방법2: 모든 데이터를 트리에 넣은 상태에서 heap 구성
a2 = [0, 11, 14, 2, 7, 6, 3, 9, 5]
b2 = Heap(a2)
b2.makeHeap2()
print("Heap 2:", b2.data[1:])

# addElt
b2.addElt(50)
print("Heap 2 after adding 50:", b2.data[1:])

# heapSort
s2 = Heap.heapSort(a2)
print("Sorted Heap 2:", s2)
