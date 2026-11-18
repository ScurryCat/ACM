#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+9, p = 1e6+3;

int n, ans[N];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  ans[1] = 1;
  for(ll i=2;i<p;i++){  // 预处理计算出1~p-1之间的所有答案
    ans[i] = (i * ans[i-1]) % p;  // 注意对答案取余
  }

  while(cin >> n){  // 多测样例输入
    if(n < p){  // n<p 直接输出答案
      cout << ans[n] << '\n';
    }
    else{ // n>=p 则说明 n！必包含因数p，所以 n! % p == 0
      cout << 0 << '\n';
    }
  }

  return 0;
}