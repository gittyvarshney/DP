#include<bits/stdc++.h>
using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("D:\\Project sunrise\\input.txt", "r", stdin);
    freopen("D:\\Project sunrise\\output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t,i,j,n,m;
  cin >> t;
  while(t--)
  {
    cin >> n >> m;
    vector<vector<long long>>prices(m,vector<long long>(n,0));
    vector<vector<long long>>discounts(m,vector<long long>(n,0));
    vector<vector<long long>>dp(m,vector<long long>(n,0));
    for(j=0;j<n;j++)
    {
      for(i=0;i<m;i++)
      {
        cin >> prices[i][j];
      }
    }

    for(j=0;j<n;j++)
    {
      for(i=0;i<m;i++)
      {
        cin >> discounts[i][j];
      }
    }

    long long minimum_sum = 9000000000000;
    for(i=0;i<m;i++)
    {
      dp[i][0] = prices[i][0];
      //cout << dp[i][0] << " ";
      minimum_sum = min(minimum_sum,dp[i][0]);
    }
    //cout << "\n";
    long long dis,t_dis,without_dis,next_minimum;
    for(j=1;j<n;j++)
    {
      next_minimum = 9000000000000;
      for(i=0;i<m;i++)
      {
        //if brought with discounts
        dis = max((long long)0,prices[i][j]-discounts[i][j-1]);
        t_dis = dp[i][j-1] + dis; //it is to be noted that previous value
        //of the object from same shop have to be added

        //if brought without discounts
        without_dis = minimum_sum + prices[i][j];
        dp[i][j] = min(without_dis,t_dis);
        next_minimum = min(dp[i][j],next_minimum);
        //cout << dp[i][j] << " ";
      }
        //cout << "\n";
      minimum_sum = next_minimum;
    }

    cout << minimum_sum << "\n";
    //cout << "sum: " << sum << "\n";
  }
}
