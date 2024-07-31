size=int(input("enter the size of array"))
def insert(key1,value1,key,value,chain,flag):
    i=0
    loc=key1%size
    while(flag[loc]==1 and i<size):
        if(key[loc]%size==key1%size):
            break
        loc=(loc+1)%size
        i+=1
    if(i==size):
        print("array is full")
    while(chain[loc]!=-1):
        loc=chain[loc]
    j=loc
    while(flag[j]==1 and i<size):
        j=(j+1)%size
        i+=1
    key[j]=key1
    value[j]=value1
    flag[j]=1
    if(j!=loc):
        chain[loc]=j
def display(key,value,chain,flag):
    print("INDEX:",  "KEY:",   "VAALUE:",   "CHAIN",   "FLAG")
    for i in range(size):
        print(i,":",key[i],":",value[i],":",chain[i],":",flag[i])
def search(key_search,key,value,chain,flag):
    i=0
    loc=key_search%size
    while(i<size and flag[loc]==1 and key[loc]%size!=key_search%size):
        j=(j+1)%size
        i+=1
    if(not flag[loc] or i==size):
        return -1
    while(loc!=-1):
        if(key[loc]==key_search):
            return loc
        loc=chain[loc]
    return -1
def main():
    key=[0]*size
    value=[0]*size
    chain=[-1]*size
    flag=[0]*size
    for i in range(size):
        key1=int(input("enter key:"))
        value1=int(input("enter value1:"))
        insert(key1,value1,key,value,chain,flag)
    display(key,value,chain,flag)
    key_search=int(input("enter key to search"))
    res=search(key_search,key,value,chain,flag)
    if(res==-1):
        print("key not found")
    else:
        print("key found !! value is",value[res])

main()



