# -*- coding: utf-8 -*-
"""
Created on Sat Nov 12 16:36:23 2022

@Author: skm
@Filename pytagoras01.py
"""

def pytaBin(Adata, Value):
    N = len(Adata)
    Mid = N // 2
    StartP = 0
    EndP = N-1
    while True :
        Mid = (StartP+EndP) // 2
        if(Value > Adata[Mid]):
            StartP = Mid+1
        elif(Value < Adata[Mid]):
            EndP = Mid-1
        else:
            return Mid, True

    return Mid, False

def pytaBin01(Adata, Value):
    N = len(Adata)
    Mid = N // 2
    StartP = 0
    EndP = N-1
    while (StartP<EndP) :
        Mid = (StartP+EndP) // 2
        if(Value > Adata[Mid]):
            StartP = Mid+1
        elif(Value < Adata[Mid]):
            EndP = Mid-1
        else:
            return Mid, True

    return Mid, False


def pyta_test( N=50, Value=13 ):
    global TestData
    TestData = [ k for k in range(1,N+1) ]
    Idx, TF = pytaBin(TestData, Value)
    print(Idx, TF, TestData[Idx])
    
def pyta_test01( N=50, Value=16 ):
    global TestData01
    # TestData01 = [ 2*k-1 for k in range(1,N+1) ]
    TestData01 = [ k for k in range(1,N+1) ]
    Idx, TF = pytaBin01(TestData01, Value)
    print(Idx, TF, TestData01[Idx])
    
def main():
    pyta_test()
    pyta_test01()
    
if ( __name__ == "__main__" ):
    main()
    