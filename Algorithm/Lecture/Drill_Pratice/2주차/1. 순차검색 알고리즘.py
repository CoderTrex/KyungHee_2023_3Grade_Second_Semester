def seqsearch(s,x):
    i, pos = 0, -1
    while (len(s) > i):
        if (s[i] == x):
            pos = i
            break
        i += 1
    return pos

s=[3,5,2,1,7,9]
loc = seqsearch(s, 4)
print("4", loc)
loc = seqsearch(s, 2)
print("2", loc)
loc = seqsearch(s, 7)
print("7", loc) 