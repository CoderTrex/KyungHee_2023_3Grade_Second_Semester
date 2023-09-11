def seqsearch(s, x):
    loc = -1
    for i in range(len(s)):
        if (s[i] == x):
            loc = i
    return loc

s = [3, 5, 2, 1, 7, 9]
loc = seqsearch(s, 4)
print(loc)
