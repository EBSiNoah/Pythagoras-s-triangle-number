# -*- coding: utf-8 -*-
"""
Created on Mon Dec 19 17:20:16 2022

@author: NOPE
"""

def pytri(number):
    output=[]
    sideset=[]
    exist=True
    num=int(number)
    a=1
    b=2
    c=0
    loopcount=0
    for i in range(num+1):
        sideset.append(i*i)
    while(b<num):
        a=1
        while(a<b):
            if(sideset[a]+sideset[b]>sideset[num-1]):
                break
            c=b+1
            while(sideset[a]+sideset[b]!=sideset[c]):
                loopcount+=1
                if(sideset[a]+sideset[b]<sideset[c]):
                    exist=False
                    break
                c+=1
            if(exist):
                output.append([a,b,c])
            exist=True
            a+=1
        b+=1
    print("repeat for : ",loopcount)
    return output

def pytriA(number):
    output=[]
    sideset=[]
    num=int(number)
    a=1
    b=2
    c=0
    sp=0
    ep=0
    mid=0
    loopcount=0
    for i in range(num+1):
        sideset.append(i*i)
    while(b<=num):
        a=1
        while(a<b):
            if(sideset[a]+sideset[b]>sideset[num]):
                break
            sp=b+1
            ep=num
            while(sp<=ep):
                mid=(sp+ep)//2
                print(sp,ep,mid,"is work?")
                loopcount+=1
                if(sideset[a]+sideset[b]<sideset[mid]):
                    ep=mid-1
                elif(sideset[a]+sideset[b]>sideset[mid]):
                    sp=mid+1
            c=mid
            if(sideset[a]+sideset[b]==sideset[c]):
                output.append([a,b,c])
            a+=1
        b+=1
    print("repeat for : ",loopcount)
    return output

def pytri_test():
    num=input()
    print(pytriA(num))

def main():
    pytri_test()
    
if(__name__=="__main__"):
    main()