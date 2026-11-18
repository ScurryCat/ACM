#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+9;

int n;
char s[N], t[N];

inline void merge(int l, int r){
  if(l == r) return;
  int m = l + r >> 1;
  merge(l, m); merge(m+1, r);
  int i = l, j = m + 1, k = l;
  int cnt1 = 0, cnt2 = 0, change = 0;
  while(i <= m && j <= r){
    if(s[i] > s[j]) change = 1;
    if(s[i] == '1') cnt1++;
    if(s[j] == '1') cnt2++;
    i++; j++;
  }
  if((r - l + 1) & 1) return;
  i = l, j = m + 1;
  if(cnt1 && cnt2 && change){
    while(j <= r) t[k++] = s[j++];
    while(i <= m) t[k++] = s[i++];
    for(i = l; i <= r; i++) s[i] = t[i];
  }
}

int main(){
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> s[i];
  }
  for(int len=2; len<=n; len++){
    for(int i=1; i+len-1 <= n; i++){
      merge(i, i+len-1);
    }
  }
  for(int i=1; i<=n; i++) cout << s[i];
  return 0;
}