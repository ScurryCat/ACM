#include <bits/stdc++.h>
using namespace std;

int main(){
    int d = 1;
    int x = 1, y = 20;
    cout << d << ' ' << x << ' ' << y << '\n';
    while(y > 0){
        y -= x;
        x <<= 1;
        y <<= 1;
        d++;
        cout << d << ' ' << x << ' ' << y << '\n';
    } 
    cout << d;
    return 0;
}