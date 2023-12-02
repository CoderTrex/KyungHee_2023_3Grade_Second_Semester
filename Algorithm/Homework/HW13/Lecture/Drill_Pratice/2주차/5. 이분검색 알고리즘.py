def bs(data,item, low, high):
    if (low >= high):
        return -1
    mid = int((low + high)/2)
    if (data[mid] == item):
        return mid
    elif (data[mid] > item):
        return bs(data, item, low, mid-1)
    elif (data[mid] < item):
        return bs(data, item, mid+1, high)
    
data=[1,3,5,6,7,9,10,14,17,19]
n=10
location=bs(data, 17, 0, n-1)
print(location)
