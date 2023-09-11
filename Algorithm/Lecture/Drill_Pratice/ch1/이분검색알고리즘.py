a = []
for i in range(1, 100):
    a.append(i)


target = int(input())
try_number = 0
low = 0
high = 99
location = 0

while (low <= high and location == 0):
    mid = int ((low + high)/2)
    if (a[mid] == target):
        location = mid
    elif (a[mid] > target):
        high = mid - 1
    else:
        low = mid + 1
    try_number += 1

print("index is {0}".format(mid))
print("try number is {0}".format(try_number))
# number =  int(input())
