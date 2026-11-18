#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int mp[101][101];
int ans[101][101];

int main(){
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mp[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int vis[101][101] = {0};
            ans[i][j] = -1;
            int x = i, y = j, r = 0;
            while(1){
                vis[x][y] = 1;
                switch(mp[x][y]){
                    case 1: x--; break;
                    case 2: x++; break;
                    case 3: y--; break;
                    case 4: y++; break;
                }
                if(!mp[x][y]) break;
                if(vis[x][y]) break;
                if(x == n && y == m){
                    ans[i][j] = r;
                    break;
                }
            }
        }
    }
    
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << ans[x][y] << '\n';
    }
    return 0;
}