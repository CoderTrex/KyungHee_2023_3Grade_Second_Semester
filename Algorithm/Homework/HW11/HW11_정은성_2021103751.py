# 1번 문제

# sudo 코드

# bool promising(index i){
#     return(weight+total>=W)&&(weight == W ||weight+w[i+1]<=W);
# }

# void sum_of_subsets(index i, int weight, int total)
# {
#     if(promising(i))
#         if (weight == W)
#             cout << include[1] through include[i];
#         else{
#             include[i+1]=“yes”;
#             sum_of_subsets(i+1, weight+w[i+1],total-w[i+1]);
#             include[i+1]=“no”;
#             sum_of_subsets(i+1, weight,total-w[i+1]);
#         }
# }



# --------------------------------------------------------------------------------- #
# --------------------------------------------------------------------------------- #



w = [1, 2, 3, 5, 7, 8]
# w = [1, 2, 4, 6]


n = len(w)
# W(max_weight)=6
Max_Weight = 9
total = 0
call = 0


for k in w:
    total += k

def promising(i, weight, total):
    return (weight + total >= Max_Weight) and (weight == Max_Weight or weight + w[i + 1] <= Max_Weight)

def sum_of_subsets(i, weight, total):
    global include
    global call
    # print("Node:", include, "Weight:", weight)
    call += 1
    if weight == Max_Weight:
        global cnt
        cnt += 1 
        print("sol : ",include)
        temp = [w[j] for j in range(0, i + 1) if include[j]]
        subset_set.append(temp)

    elif promising(i, weight, total):
        include[i + 1] = 1
        sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1])
        include[i + 1] = 0
        sum_of_subsets(i + 1, weight, total - w[i + 1])

cnt = 0
include = (n) * [0]
subset_set = []

print("""
-------------------
    problem 1.
-------------------
    """)
print("items =", w, "W =", Max_Weight)
print()
sum_of_subsets(-1, 0, total)

print()
print("Subsets with sum equal to W: ", subset_set)
print()
print("Total number of nodes generated if all solutions are found: ", call)
print()





# --------------------------------------------------------------------------------- #
# --------------------------------------------------------------------------------- #


# 2번 과제

# void m_coloring(index i) {
#     int color;
#     if(promising(i))
#         if(i==n)
#             cout << vcolor[1] through vcolor[n];
#     else
#         for (color=1; color<=m; color++){
#             vcolor[i+1] = color;
#             m_coloring(i+1);
#         }
# }
# bool promising(index i) {
#     index j;
#     bool switch;
#     switch = true;
#     j=1;
#     while ( j<i && switch){
#         if(W[i][j] && vcolor[i]==vcolor[j]) // W[i][j]:연결표시. T or F
#             switch = false;
#         j++;
#     }
#     return switch;
# }


# --------------------------------------------------------------------------------- #
# --------------------------------------------------------------------------------- #

#    [0, 1, 2, 3, 4, 5]
W = [
    [0, 1, 1, 0, 0, 0], 
    [1, 0, 0, 1, 0, 0],
    [1, 0, 0, 1, 1, 0],
    [0, 1, 1, 0, 0, 1],
    [0, 0, 1, 0, 0, 1],
    [0, 0, 0, 1, 1, 0],
    ]

# W=[[0,1,1,1],[1,0,1,0],[1,1,0,1],[1,0,1,0]]


n = len(W[0])
vcolor = (n) * [0]
count = 0
calling = 0

print("""
-------------------
    problem 2.
-------------------
    """)

def promising(i, W, vcolor):
    j = 0
    switch = True
    # print(i, j)
    if (i == n):
        return False
    while j < i and switch:
        if W[i][j] and vcolor[i] == vcolor[j]:
            switch = False
        j += 1
    return switch

def m_coloring(i, W, vcolor, m):
    global calling
    calling += 1
    if promising(i, W, vcolor):
        if i == n-1:
            global count
            global flag
            count += 1
            flag = True
            print("vcolor:", vcolor)
        else:
            for color in range(0, m):
                vcolor[i + 1] = color+1
                m_coloring(i + 1, W, vcolor, m)

for m in range(0, n):
    flag = False
    count  = 0
    m_coloring(-1, W, vcolor, m)
    if flag:
        print()
        print("count of m(minimal colors)   : ", m)
        print("number of cases in M         : ", count)
        print("how many nodes are generated : ", calling)
        exit()
        