def bs(data, item, low, high):
    while(low <= high):
        mid = int((low+high)/2)
        if (data[mid] == item):
            return mid
        elif (data[mid] > item):
            high = mid - 1
        else:
            low = mid + 1

data = [1,3,5,7,9,11,13,15,17,19]
n = 10
location = bs(data, 17, 0, n - 1)
print(location)