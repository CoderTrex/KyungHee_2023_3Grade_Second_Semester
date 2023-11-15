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
# bool promising(index i){
#     return(weight+total>=W)&&(weight == W ||weight+w[i+1]<=W);
# }


n=4
w=[1,2,4,6]
W=6
print("items =",w, "W =", W)
include = n*[0]
total=0
for k in w:
    total += k

# 1번 과제
def promising(i,weight, total):
    # 구현
    return ((weight+total >= W)and(weight+w[i+1] <= W))

def s_s(i, weight, total, include):
    # sum of subsets 구현
    if (promising(i)):
        print()
    return 0




s_s(-1,0,total,include)

# 2번 과제