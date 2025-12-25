#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
int la,lc;
int A[N],b,C[N];
long long r;

// void div(int A[],int b,int C[]){
//   r = 0;
//   for(int i=la-1;~i;i--){
//   r = r*10 + A[i];
//   C[la-1-i] = r / b;
//   r %= b;
//   }
//   reverse(C,C+lc);
//   while(lc&&C[lc]==0) lc--;
// }

// int main(){
//   string a;
//   cin>>a>>b;
//   lc=la=a.size();
//   for(int i=0;i<la;i++) A[la-1-i]=a[i]-'0';
//   div(A,b,C);
//   for(int i=lc;~i;i--) cout<<C[i];
//   cout<<'\n'<<r;
//   return 0;
// }

void div(int A[],int b,int C[]){
  r=0;
  for(int i=0;i<la;i++){
    r = r*10 + A[i];
    C[i] = r / b;
    r %= b;
  }
  reverse(C,C+lc);
  while(lc&&C[lc]==0) lc--;
}

int main(){
  string a;
  cin>>a>>b;
  lc=la=a.size();
  for(int i=0;i<la;i++) A[i]=a[i]-'0';
  div(A,b,C);
  for(int i=lc;~i;i--) cout<<C[i];
  return 0;
}