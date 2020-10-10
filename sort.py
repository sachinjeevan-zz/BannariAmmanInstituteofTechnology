N,K = map(int,input().split(" "))
lis = list(map(int,input().split(" "))).sort()
print(*(lis[:K]+ sorted(lis[K:],reverse=True)))