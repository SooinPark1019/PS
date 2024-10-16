N=int(input())

if N==0:
    print(1)
else:
    left=0
    right=1e7
    ans=1e7

    while left<=right:
        mid=int((left+right)//2)
        if N<6**mid:
            ans=min(ans, mid)
            right=mid-1
        else:
            left=mid+1

    print(ans)