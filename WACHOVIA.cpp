#include<bits/stdc++.h>
using namespace std;
//Problem of spoj
//It is a knapsack problem implemented in a 2D DP
//can we implemented in recursion + memorization method

int n_bags;

int recurr_dp(int weight,int i,vector<vector<int>>&bags,vector<vector<int>>&vec)
{

  if(i>=n_bags)
  {
    //cout << "return 0\n";
    return 0;
  }

  if(vec[weight][i] != -1)
  {
    //cout << "DP USED\n";
    return vec[weight][i];
  }

  int value_1,value_2;
  value_2 = recurr_dp(weight,i+1,bags,vec);
  if(weight-bags[i][0] >= 0)
  {
    value_1 = bags[i][1] + recurr_dp(weight-bags[i][0],i+1,bags,vec);
  }
  else
  {
    value_1 = 0;
  }
  vec[weight][i] = max(value_1,value_2);
  //cout << "vec[" << weight << "]" << "[" << i << "]: " << vec[weight][i] << "\n";
  return vec[weight][i];

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

  int t;
  int max_weight;
  int i;
  cin >> t;
  while(t--)
  {
    cin >> max_weight >> n_bags;
    vector<vector<int>>bags(n_bags,vector<int>(2,0));
    for(i=0;i<n_bags;i++)
    {
      cin >> bags[i][0] >> bags[i][1];
    }
    vector<vector<int>>vec(max_weight+1,vector<int>(n_bags,-1));
    cout << "Hey stupid robber, you can get " <<  recurr_dp(max_weight,0,bags,vec) << ".\n";
  }
}
