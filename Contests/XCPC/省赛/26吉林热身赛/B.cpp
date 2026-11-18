#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  while(t--)
  {
    long long n;
    cin>>n;
    long long l = 1;
    long long r = n;
    int last = -1;
    while(l<r)
    {
      long long mid = (l+r)/2;
      long long y = mid;
      if(last != -1){
        int current = y%2;
        if(current == last)
        {
          if(y+1<=r)
          {
            y = y+1;

          }
          else
          {
            y = y -1;

          }
        }
      }
      cout<<"?"<<y<<endl;
      cout.flush();
      int res;
      if(res == 1)
      {
        r = y;

      }
      else
      {
        l = y+1;
      }
      last = y%2;
    }
    cout<<"!"<<l<<endl;
    cout.flush();
  }
  return 0;
}