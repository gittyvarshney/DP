#include<bits/stdc++.h>
using namespace std;
//Very nice DP Recursive problem of Top Down manner
//It is a 2d DP Problem of Codeforces round 467 div(2) poblem C
#define MIN -6e12
//as value can be maximum upto 5x10^3 x 10^9 by looking into constraints
vector<long long>sum(5003,0);
vector<long long>arr(5003,0);
vector<vector<long long>>vec(5003,vector<long long>(5003,-1));
long long n,m,k;

long long recurr_dp(long long i, long long k)
{
  //cout << "recurr_dp(" << i << "," << k << ")\n";
  if(i>n-m)
  {
    if(k==0)
    {
      //cout << "returning 0 \n";
      return 0;
    }
    else
    {
      //cout << "returning MIN \n";
      return MIN;
    }
  }
  if(k==0)
  {
    //cout << "returning 0 \n";
    return 0;
  }
  if(vec[i][k]!= -1)
  {
    //cout << "DP Used \n";
    return vec[i][k];
  }


  long long take_curr;
  long long leave_curr;
  long long ans;
  //now we have to either take the current sum and go to next non-overlapping sum
  //or just leave the current sum and start with the second sum
  //take maximum out of them
  take_curr = sum[i] + recurr_dp(i+m,k-1);
  //taking the current sum and going to next overlapping sum
  leave_curr = recurr_dp(i+1,k);
  ans = max(take_curr,leave_curr);
  //cout << "vec["<<i << "]" << "[" <<k <<"]" << " = " << ans << "\n";
  vec[i][k] = ans;
  return ans;
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
  int i;
  cin >> n >> m >> k;
  for(i=0;i<n;i++)
  {
    cin >> arr[i];
  }

  for(i=0;i<m;i++)
  {
    sum[0] += arr[i];
  }

  for(i=1;i<=n-m;i++)
  {
    sum[i] = sum[i-1];
    sum[i] = sum[i] - arr[i-1];
    sum[i] += arr[i+m-1];
  }
  /*
  for(i=0;i<=n;i++)
  {
    cout << sum[i] << " ";
  }
  cout << "\n";
  */
  cout << recurr_dp(0,k) << "\n";
}
