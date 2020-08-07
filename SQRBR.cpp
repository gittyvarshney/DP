#include<bits/stdc++.h>
using namespace std;
//Very nice and hard think DP Problem of SPOJ
//It is a 2d DP problem solved in a bottom up manner
//but table build for every test case has their is a constraint in each
//test case which can change the table

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
  int t,n,k,k_i,i,j;
  cin >> t;
  while(t--)
  {
    cin >> n >> k;
    vector<int>open_at(2*n+1,0);
    for(i=0;i<k;i++)
    {
      cin >> k_i;
      open_at[k_i] = 1;
    }
    vector<vector<int>>vec(2*n + 1,vector<int>(2*n+1,0));
    vec[1][1] = 1;
    for(i=2;i<2*n+1;i++)
    {
      if(open_at[i] == 1)//do memorization only for '[' bracket
      {
        for(j=1;j<=i;j++)
        {
          vec[i][j] = vec[i-1][j-1];
        }
      }
      else //if no restrictions for brackets don memorization for both
      {
        for(j=1;j<=i;j++)
        {
          vec[i][j] = vec[i-1][j-1];
        }
        for(j=0;j<=i-2;j++)
        {
          vec[i][j]+= vec[i-1][j+1];
        }
      }
    }
    /*
    for(i=1;i<=6;i++)
    {
      for(j=0;j<=6;j++)
      {
        cout << vec[i][j] << " ";
      }
      cout << "\n";
    }
    */
    cout << vec[2*n][0] << "\n";
  }
}
