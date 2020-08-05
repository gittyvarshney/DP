#include<bits/stdc++.h>
using namespace std;
//question of codechef
//simple top down approach

int recurr_dp(int n, vector<int>&vec, vector<int>&dp)
{
  //cout << "In " << n << " \n";
  //cout << "printing dp: \n";
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  int k=0;
  int minn = INT_MAX;
  int value;
  while(n-pow(2,k)>= 1)
  {
    //cout << "\twhile " << n-pow(2,k) << " \n";
    value = abs(vec[n]-vec[n-pow(2,k)]) + recurr_dp(n-pow(2,k),vec,dp);
    minn = min(value,minn);
    k++;
  }
  dp[n] = minn;
  return dp[n];
}

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
  int n,i;
  cin >> n;
  vector<int>vec(n+1,0);
  for(i=0;i<n;i++)
  {
    cin >> vec[i+1];
  }
  vector<int>dp(n+1,-1);
  dp[1] = 0;
  cout << recurr_dp(n,vec,dp) << "\n";

}
