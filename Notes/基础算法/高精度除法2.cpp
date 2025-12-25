#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
int la,lb,lc;
int A[N],B[N],C[N],R[N];

// 本质是通过不断做高精度减法来模拟，可以用二分来加速
void div(int A[],int B[],int C[]){
  
  reverse(C,C+lc);
  while(lc&&C[lc]==0) lc--;
}

int main(){
  string a,b;
  cin>>a>>b;
  la=a.size();lb=b.size();lc=max(la,lb);
  for(int i=0;i<la;i++) A[lb-1-i]=a[i]-'0';
  for(int i=0;i<lb;i++) B[lb-1-i]=b[i]-'0';
  div(A,B,C);
  for(int i=lc;~i;i--) cout<<C[i];
  return 0;
}