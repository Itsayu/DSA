#User function Template for python3

def Rearrange( a, n):
    # Your code goes here
    negNo=[]
    posNo=[]
    for i in range(n):
        if a[i]<0:
            negNo.append(a[i])
        else:
            posNo.append(a[i])
    
    negNo.extend(posNo)
    for i in range(n):
        a[i]=negNo[i]
    
#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        Rearrange(a, n)
        print(*a)

        T -= 1


if __name__ == "__main__":
    main()





    
# } Driver Code Ends