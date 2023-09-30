def mergeSort(n, s):
    if n > 1:
        h = n // 2
        m = n - h
        U = s[:h]
        V = s[h:]
        mergeSort(h, U)
        mergeSort(m, V)
        merge(h, m, U, V, s)

def merge(h, m, u, v, s):
    i, j, k = 0, 0, 0
    while i < h and j < m:
        if u[i] < v[j]:
            s[k] = u[i]
            i += 1
        else:
            s[k] = v[j]
            j += 1
        k += 1

    while i < h:
        s[k] = u[i]
        i += 1
        k += 1

    while j < m:
        s[k] = v[j]
        j += 1
        k += 1

s=[3,5,2,9,10,14,4,8]
mergeSort(8,s)
print(s)