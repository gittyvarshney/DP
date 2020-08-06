#include<bits/stdc++.h>
using namespace std;
//Very nice DP Problem of SPOJ
//It is a 2d DP Problem with bottom up approach
//In this DP problem you have to take into consideration the previous row
//values

int main()
{
  /*
  #ifndef ONLINE_JUDGE
    freopen("D:\\Project sunrise\\input.txt", "r", stdin);
    freopen("D:\\Project sunrise\\output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  */
  int i,j,k;
  vector<vector<int>>vec(13,vector<int>(99,0));
  int sum;
  for(i=1;i<13;i++)
  {
    vec[i][0] = 1;
  }
  for(i=2;i<13;i++)
  {
    for(j=1;j<99;j++)
    {
      sum=0;
      for(k=j;j-k<=i-1&&k>=0;k--)
      {
        sum+=vec[i-1][k];
      }
      vec[i][j] = sum;
    }
  }
  /*
  for(i=0;i<5;i++)
  {
    for(j=0;j<7;j++)
    {
      cout << vec[i][j] << " ";
    }
    cout << "\n";
  }
  */
  int d,n,k_n;
  cin >> d;
  while(d--)
  {
    cin >> n >> k_n;
    cout << vec[n][k_n] << "\n";
  }
}
