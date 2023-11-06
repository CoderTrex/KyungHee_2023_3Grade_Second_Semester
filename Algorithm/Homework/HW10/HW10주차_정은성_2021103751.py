# import sys

# # 해의 총 개수, 
# # 10번째 해, 
# # 모든 해를 모두 찾기 위해 생성한 상태공간트리의 총 노드 수

# void	func_backtracing(int *the_arr, int i, int *cnt)
# {
# 	int		the_num;

# 	the_num = 0;
# 	if (i == 9)
# 	{
# 		(*cnt)++;
# 		func_printer(the_arr);
# 	}
# 	while (the_num < 10)
# 	{
# 		the_arr[i + 1] = the_num;
# 		if (func_vaild(the_arr, i + 1))
# 			func_backtracing(the_arr, i + 1, cnt);
# 		the_num++;
# 	}
# }

# int	ft_ten_queens_puzzle(void)
# {
# 	int		the_arr[11];
# 	int		cnt;
# 	int		i;

# 	i = -1;
# 	cnt = 0;
# 	while (++i < 10)
# 		the_arr[i] = -1;
# 	func_backtracing(the_arr, -1, &cnt);
# 	return (cnt);
# }

cnt = 0

def promising(i,col):
    k = 1
    valid = True
    
    while (k <i and valid):
        if (col[i] == col[k] or abs(col[i] - col[k]) == i - k):
            valid = False
            k += 1
    return valid
    # 구현



def queens(n, i, col): 
    if (i == n):
        cnt += 1
        print(col)

    for i in range(n):
        col[i+1] = 0
        if (promising(i+1, col)):
            queens(n, i+1, col)

n=5
col=n*[0]
queens(n,-1,col)

print(cnt)

