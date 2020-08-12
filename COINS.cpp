#include<bits/stdc++.h>
using namespace std;
//Easy DP Problem of Recurrsion + Memorization with hashmap
//It is a 1d DP problem solved in a recurrsion manner
//COINS Problem of Codechef
map<int,long long> vec;


long long recurr_dp(long long i)
{
  if(i==0)
  {
    return 0;
  }
  if(vec[i]!= 0)
  {
    //cout << "dp used\n";
    return vec[i];
  }
  //cout << "tag\n";
  long long ans_1 = recurr_dp(i/2) + recurr_dp(i/3) + recurr_dp(i/4);
  long long ans = max(i,ans_1);
  vec[i] = ans;
  return ans;
}


int main()
{

  #ifndef ONLINE_JUDGE
    freopen("D:\\Project sunrise\\input.txt", "r", stdin);
    freopen("D:\\Project sunrise\\output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  while(cin >> n)
  {
    cout << recurr_dp(n) << "\n";
  }
}
