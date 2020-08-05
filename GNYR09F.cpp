#include<bits/stdc++.h>
using namespace std;
//Very nice DP Problem of SPOJ
//It is a 3d DP problem solved in a bottom up manner

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("D:\\Project sunrise\\input.txt", "r", stdin);
    freopen("D:\\Project sunrise\\output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int i,j;
  vector<vector<vector<int>>>vec(101,vector<vector<int>>(100,vector<int>(2,0)));
  vec[1][0][0] = 1;
  vec[1][0][1] = 1;
  for(i=2;i<101;i++)
  {
    for(j=0;j<100;j++)
    {
      vec[i][j][0] = vec[i-1][j][0] + vec[i-1][j][1];
      if(j!=0)
      {
        vec[i][j][1] = vec[i-1][j][0] + vec[i-1][j-1][1];
      }
      else
      {
        vec[i][j][1] = vec[i-1][j][0]; //for lenght of 0 only previous 0 is possible
      }
    }
  }
  int p,u,n,k;
  cin >> p;
  while(p--)
  {
    cin >> u >> n >> k;
    if(k>=n)
    {
      cout << u << " " << 0 << "\n";
    }
    else
    {
      cout << u << " " << vec[n][k][0] + vec[n][k][1] << "\n";
    }
  }
}
