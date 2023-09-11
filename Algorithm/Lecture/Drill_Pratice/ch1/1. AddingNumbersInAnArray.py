def sum1(s):
    result = 0
    for a in s:
        result += a
    return result

def sum2(s):
    result = 0
    for a in range(len(s)):
        result += s[a]
    return result

s = [3, 5, 2, 1, 7, 9]
result1 = sum1(s)
result2 = sum2(s)

print("result1: {0}".format(result1))
print("result2: {0}".format(result2))