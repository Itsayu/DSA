#User function Template for python3

def Rearrange( a, n):
    # Your code goes here
    negValue=[]
    posValue=[]
    for i in range(n):
        if a[i]<0:
            negValue.append(a[i])
        else:
            posValue.append(a[i])
    
    negValue.extend(posValue)
    for i in range(n):
        a[i]=negValue[i]
    
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