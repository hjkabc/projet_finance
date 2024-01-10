import numpy as np
def minn(s,n):
    minn=0
    for i in range (n):
        if s[i]<minn :
            minn=s[i]
    return -minn
def nbrejours(n):
    tnj=np.zeros(n)
    for i in range(n):
        print("donner le nombre de jours entre loperation ",i," et ",i+1)
        tnj[i]=int(input())
    return tnj   
def operations_cd(n):
    op=np.zeros(n)
    cd=0
    print("donner le taux de commissions debit")
    tcd=float(input())
    for i in range(n):
        print("donner le montant de lopération n° ",i)
        op[i]=float(input())
        if op[i]<0:
            cd=cd-op*tcd/100
    return op,cd
def soldes_cd(n):
    s=np.zeros(n)
    print("donner le solde initial")
    s[0]=float(input())
    
    op,cd=operations_cd(n)
    for i in range (n):
        if i>0:
            s[i]=s[i-1]+op[i]
    return s,cd
def tauxdeb(n):
    ttaux=np.zeros(n)
    for i in range (n):
        print("donner le taux debiteur correspndant a loperation n°",i)
        ttaux[i]=float(input())
    return ttaux

def intdeb_cpfd(n):
    s,cd=soldes_cd(n)
    minimum=minn(s,n)
    print("donner le taux de commission du plus fort découvert")
    tcpfd=float(input())
    cpfd=minimum*tcpfd/100
    tintdeb=np.zeros(n)
    ttaux=tauxdeb(n)
    tnj=nbrejours(n)
    for i in range(n):
        if s[i]<0:
            tintdeb[i]=tnj[i]*ttaux[i]*s[i]/36000
        else:
            tintdeb[i]=0
    return tintdeb,cpfd,cd
def totalint(n):
    tintdeb,cpfd,cd=intdeb_cpfd(n)
    som=0
    for i in range (n):
        som=som+tintdeb[i]
    l=som+cpfd+cd
    return l
def minn(s,n):
    minn=0
    for i in range (n):
        if s[i]<minn :
            minn=s[i]
    return -minn
