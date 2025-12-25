#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
const int N = 1e5+9;
int la,lb,lc;
int A[N],B[N],C[N];

void add(int A[],int B[],int C[]){
  for(int i=0;i<lc;i++){
    C[i] += A[i] + B[i];      // 累加
    C[i+1] += C[i] / 10;      // 进位
    C[i] %= 10;               // 存余
  }
  if(C[lc]) lc++;
}

int main(){
  string a,b;
  cin>>a>>b;
  la=a.size(),lb=b.size(),lc=max(la,lb);
  for(int i=la-1;~i;i--) A[la-i-1]=a[i]-'0';
  for(int i=lb-1;~i;i--) B[lb-i-1]=b[i]-'0';
  add(A,B,C);
  for(int i=lc-1;~i;i--) cout<<C[i];
  return 0;
}