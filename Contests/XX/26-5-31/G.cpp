#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int tr[N][26], fail[N], cnt[N], tot;
vector<int> ids[N];
int ord[N];
int ans[N];

void insert(const string& p, int id) {
  int u = 0;
  for (char c : p) {
    int ch = c - 'a';
    if (!tr[u][ch]) tr[u][ch] = ++tot;
    u = tr[u][ch];
  }
  ids[u].push_back(id);
}

int build() {
  queue<int> q;
  for (int c = 0; c < 26; c++) {
    int v = tr[0][c];
    if (v) {
      fail[v] = 0;
      q.push(v);
    }
  }
  int top = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ord[top++] = u;
    for (int c = 0; c < 26; c++) {
      int v = tr[u][c];
      if (v) {
        fail[v] = tr[fail[u]][c];
        q.push(v);
      } else {
        tr[u][c] = tr[fail[u]][c];
      }
    }
  }
  return top;
}

void run(const string& s) {
  int u = 0;
  for (char c : s) {
    u = tr[u][c - 'a'];
    cnt[u]++;
  }
}

void topo(int top) {
  for (int i = top - 1; i >= 0; i--) {
    int u = ord[i];
    cnt[fail[u]] += cnt[u];
  }
}

void output(int q) {
  for (int i = 0; i <= tot; i++)
    for (int id : ids[i]) ans[id] = cnt[i];
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

void solve(){
  string s; cin >> s;
  int q; cin >> q;

  for (int i = 0; i < q; i++) {
    string p; cin >> p;
    insert(p, i);
  }

  int top = build();
  run(s);
  topo(top);
  output(q);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  // cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
