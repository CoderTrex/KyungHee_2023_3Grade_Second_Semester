def mergeSort2(s, low, high):
    if (low < high):
        mid = low + (high - low) // 2
        mergeSort2(s, low, mid)
        mergeSort2(s, mid + 1, high)
        merge2(s, low, mid, high)

def merge2(s, low, mid, high):
    len_low = mid - low + 1
    len_high = high - mid

    arr_low = [0]*len_low  
    arr_high = [0]*len_high

    for i in range(0, len_low):
        arr_low[i] = s[low + i]
    for j in range(0, len_high):
        arr_high[j] = s[mid + 1 + j]

    i, j, k = 0, 0, low

    while (i < len_low and j < len_high):
        if (arr_low[i] <= arr_high[j]):
            s[k] = arr_low[i]
            i += 1
        else:
            s[k] = arr_high[j]
            j += 1
        k += 1

    while i < len_low:
        s[k] = arr_low[i]
        i += 1
        k += 1
    while j < len_high:
        s[k] = arr_high[j]
        j += 1
        k += 1

s = [3, 5, 2, 9, 10, 14, 4, 8]
mergeSort2(s, 0, 7)
print(s)
