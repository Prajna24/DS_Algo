from math import gcd 

t = int(input())
for tc in range(t):
    
    g = int(input())
    n = int(input())
    
    arr = list(map(int,input().split()))
    
    i , j = 0 , 1
    while(i < j and j < n):
        if (gcd(arr[i] , arr[j]) == g ):
            print(2)
            break
        
        i += 1
        j += 1
        
    else:
        print(-1)
    