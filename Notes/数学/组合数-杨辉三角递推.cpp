#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 109;
ll c[N][N];

void per(int n){
  for(int i=0;i<=n;i++){
    for(int j=0;j<=i;j++){
      if(j==0) c[i][j]=1;
      else c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
  }
}

int main(){
  int n;  cin>>n;
  per(n);
  // FILE * output=fopen("output.txt","w");
  // for(int i=0;i<=n;i++){
  //   for(int j=0;j<=i;j++){
  //     // cout<<c[i][j]<<' ';
  //     // fprintf(output,"%lld ",c[i][j]);
  //   }
  //   // cout<<'\n';
  //   // fprintf(output,"\n");
  // }
  int t; 
  cin>>t;
  while(t--){
    int x,y;
    cin>>x>>y;
    printf("C%d%d : %lld\n",x,y,c[x][y]);
  }
}