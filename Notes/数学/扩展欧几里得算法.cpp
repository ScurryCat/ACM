#include <bits/stdc++.h>
using namespace std;

int exgcd(int a, int b, int &x, int &y){
  if(b==0){
    x=1; y=0;
    return a;
  }
  int d, x1, y1;
  d = exgcd(b, a%b, x1, y1);
  x=y1; y=x1-a/b*y1;
  return d;
}

int main(){
  
  return 0;
}