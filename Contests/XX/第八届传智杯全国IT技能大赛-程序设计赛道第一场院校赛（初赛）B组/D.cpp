#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;

inline void fun(int &a,int &b,int f,int x){
  a = (a*f*x+b); b = (b*f*x);
  while(a<0) a += mod; while(b<0) b += mod;
  a %= mod; b %= mod;
}

int main(){
	string s; getline(cin,s);
  int a = 1, b = ((s[2]=='+' ? (s[3]-'0') : -(s[3]-'0')) + mod) % mod;
  for(int i=5;i<=s.size()-5;i+=5) fun(a,b,(s[i+2]=='+'?1:-1),s[i+3]-'0');
  printf("%d\n",a);
	return 0;
}