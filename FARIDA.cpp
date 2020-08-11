#include<bits/stdc++.h>
using namespace std;
//Easy DP Problem of Recurrsion + Memorization
//It is a 1d DP problem solved in a recurrsion manner
int n;

long long recurr_dp(int i, vector<long long>& vec, vector<long long>& monsters)
{
  if(i>=n)
  {
    return 0;
  }
  if(vec[i]!= -1)
  {
    return vec[i];
  }
  long long ans_1 = monsters[i] + recurr_dp(i+2,vec,monsters);
  long long ans_2 = recurr_dp(i+1,vec,monsters);
  long long maxx = max(ans_1,ans_2);
  vec[i] = maxx;
  return maxx;
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
  int i,t;
  int t_count=0;
  cin >> t;
  while(t--)
  {
    cin >> n;
    vector<long long> monsters(n,0);
    for(i=0;i<n;i++)
    {
      cin >> monsters[i];
    }
    vector<long long> vec(10004,-1);
    cout << "Case "<< ++t_count <<": " << recurr_dp(0,vec,monsters) << "\n";
  }
}
