#include<bits/stdc++.h>
using namespace std;
//Medium DP Problem of SPOJ solved using top down DP
//Recurrsion + Memorization

vector<vector<int>>vec(20,vector<int>(101,-1));
vector<vector<int>>girlfriends(20,vector<int>(2,-1));
int m;
int n;

int recurr_dp(int sum,int i)
{
  //cout << "at i = " << i << "\n";
  if(i==m-1)
  {
    if(girlfriends[i][0] <= sum && sum <= girlfriends[i][1])
    {
      //cout << "\treturning 1 \n";
      return 1;
    }
    else
    {
      //cout << "\treturning 0 \n";
      return 0;
    }
  }
  if(vec[i][sum] != -1)
  {
    //cout << "dp used\n";
    return vec[i][sum];
  }
  int total_sum = 0;
  int ai = girlfriends[i][0];
  for(int k = ai;k<=girlfriends[i][1];k++)
  {
    //cout << "sum current is: " << sum-k << "\n";
    if(sum-k < 0)
    {
      break;
    }
    total_sum += recurr_dp(sum-k,i+1);
  }
  //cout << "total_sum before return: " << total_sum << "\n";
  vec[i][sum] = total_sum;
  return total_sum;
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
  int input_zero;
  int i;
  cin >> m >> n;
  for(i=0;i<m;i++)
  {
    cin >> girlfriends[i][0] >> girlfriends[i][1];
  }
  cin >> input_zero;
  cin >> input_zero;
  cout << recurr_dp(n,0) << "\n";
}
