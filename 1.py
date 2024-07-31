size=4


def linear(tel,name,flag):
    for i in range(size):  
        x=str(input("enter name: "))
        y=int(input("enter telephone no."))
        loc=y%size
        if(flag[loc]==0):
            tel[loc]=y
            name[loc]=x
            flag[loc]=1
        else:
            i=0
            while(i<size and flag[loc]==1):
                loc=(loc+1)%size
                i+=1
            tel[loc]=y
            name[loc]=x
            flag[loc]=1
def search(tel,name,flag):
    x=int(input("enter telno to search: "))
    loc=x%size
    
    if(tel[loc]==x):
        print("tel no is found at ",loc)
    else:
        i=0
        while(i<size and tel[loc]!=x):
            loc=(loc+1)%size
            i+=1
        if(i>=size):
            print("not found")
        else:
            print("tel no is found at ",loc)   

            
def double(tel1,name1,flag1):
    for i in range(size):
        x=str(input("enter name: "))
        y=int(input("enter telephone no."))
        loc=y%size
        loc1=7-(y%7)
        if(flag1[loc]==0):
            tel1[loc]=y
            name1[loc]=x
            flag1[loc]=1
        else:
            i=0
            while(i<size and flag1[loc]==1):
                u=(loc+(i*loc1))%size
                i+=1
            tel1[u]=y
            name1[u]=x
            flag1[u]=1
def hash_search(tel1,name1,flag1):
    x=int(input("enter tel no to search: "))
    loc=x%size
    loc1=7-(x%7)
    
    if(tel1[loc]==x):
        print("tel no. is found at ",loc)
    else:
        i=0
        while(i<size and tel1[loc]!=x):
            u=(loc+(i*loc))%size
            i+=1
        if(i>=size):
            print("not found")
        else:
            print("tel no is found at ",u)


    
def display1(tel1,name1,flag1):
    print(tel1)
    print(name1)
    print(flag1)
def display(tel,name,flag):
    print(tel)
    print(name)
    print(flag)

def main():
    tel=[0]*size
    name=[0]*size
    flag=[0]*size
    tel1=[0]*size
    name1=[0]*size
    flag1=[0]*size
    while True:
        print("1:LINEAR PROBING")
        print("2:DOUBLE HASH")
        print("3:EXIT")
        ch=int(input("enter choice: "))
        if ch==3:
            print("exit")
            break
        elif ch==1:
            
            linear(tel,name,flag)
            display(tel,name,flag)
            search(tel,name,flag)
            
        elif ch==2:
            
            double(tel1,name1,flag1)
            display1(tel1,name1,flag1)
            hash_search(tel1,name1,flag1)
    
            
        else:
            print("wrong choice")


main()
        

    