#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

struct Matrix{
    int m[3][3];
    Matrix(){memset(m,0,sizeof m);};
};

Matrix operator*(Matrix x,Matrix y){
    Matrix r;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++){
                r.m[i][j] = ((ll)r.m[i][j]+x.m[i][k]*y.m[k][j]) % mod;
						}
    return r;
}

int qpow(int n){
    Matrix A,B;
    A.m[1][1]=2;
    A.m[1][2]=1;
    B.m[1][1]=2;
    B.m[1][2]=1;
    B.m[2][1]=-1;
    while(n){
        if(n&1) A=A*B;
        B=B*B;
        n>>=1;
    }
    return ((ll)A.m[1][1]+mod)%mod;
}

int main(){
    int n; cin>>n;
    if(n==0) cout<<1;
		else if(n==1) cout<<2;
    else cout<<qpow(n-1);
    return 0;
}