def accept(A,str):
    n=int(input("total no. of students who play %s"%str))
    for i in range(n):
        x=input("name of the student %d who play %s"%((i+1),str))
        A.append(x)
    print("set entered successfully")
def display(A,str):
    n=len(A)
    
    if(n==0):
        print("set is {} for %s"%str)
    else:
        print("group of students who play %s is {"%str,end=',')
        for i in range(n):
            print("%s}"%A[i],"\n")
def search(P,X):
    n=len(P)
    for i in range(n):
        if(P[i]==X):
            return(1)
        else:
            return(0)
def intersection(P,Q,S):
    for i in range(len(P)):
        flag=search(Q,P[i])
        if(flag==1):
            S.append(P[i])
def union(P,Q,S):
    for i in range(len(P)):
        S.append(P[i])
    for i in range(len(P)):
        flag=search(P,Q[i])
        if(flag==0):
            S.append(Q[i])
def diff(P,Q,S):
    for i in range(len(P)):
        flag=search(Q,P[i])
        if(flag==0):
            S.append(P[i])
    
    
            
def main():
    A=[]
    B=[]
    C=[]
    while True:
        print("\n1accept  \n2who play cricket and badminton both \n3either cricket or badminton but not both \n4neither cricket nor badminton \n5cricket and football but not badminton \n6exit")
        ch=int(input("enter choice"))
        R=[]
        if(ch==6):
            print("exit")
            break
        elif(ch==1):
            accept(A,"cricket")
            accept(B,"badminton")
            accept(C,"football")
            display(A,"cricket")
            display(B,"badminton")
            display(C,"football")
            break
        elif(ch==2):
            display(A,"cricket")
            display(B,"badminton")
            intersection(A,B,R)
            display(R,"who play cricket and badminton both")
            break
        elif(ch==3):
            display(A,"cricket")
            display(B,"badminton")
            R1=[]
            union(A,B,R1)
            R2=[]
            intersection(A,B,R2)
            diff(R1,R2,R)
            display(R,"either cricket or badminton but not both")
            break
        elif(ch==4):
            display(A,"cricket")
            display(B,"badminton")
            display(C,"football")
            R1=[]
            union(A,B,R1)
            diff(C,R1.R)
            display(R,"neither cricket nor badminton")
            break
        elif(ch==5):
            display(A,"cricket")
            display(B,"badminton")
            display(C,"football")
            R1=[]
            intersection(A,C,R1)
            deff(R1,B,R)
            display(R,"who play cricket and football but not badminton")
            break
        else:
            print("entered wrong choice")
            break
main()
quit()

