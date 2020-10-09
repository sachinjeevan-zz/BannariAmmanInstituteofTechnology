N = input()
S = list(map(int,list(N)))
dig = len(S)
S = list(map(lambda a: a**dig,S))
if(int(N) == sum(S)):
    print("YES")
else:
    print("NO")