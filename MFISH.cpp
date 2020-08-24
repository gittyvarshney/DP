#include<bits/stdc++.h>
using namespace std;
//Very nice 1D DP Problem of SPOJ
//In original problem their is a constraint that you have to use all the ships but
//if their is no constraint on ships
//you can replace the //with constraint <--between-->  //End of constraint With

/*
map<int, int>::reverse_iterator it;
for (it = an.rbegin(); it != an.rend(); it++)
{
  //cout << it->first << " ";
  for(i=it->first;i<=it->first+it->second-1;i++)
  {
    if(m[i]==0)
    {
      m[i] = it->second;
    }
  }
}
*/

int n;
vector<int>arr_sum(1000000,0);
vector<int>vec(1000000,-1);
map<int,int>m;

int recurr_dp(int i)
{
  if(i<=0)
  {
    //cout << "returning 0\n";
    return 0;
  }
  if(vec[i]!= -1)
  {
    //cout << "DP Used\n";
    return vec[i];
  }

  int val_1,val_2;
  if(m[i]==0)
  {
    val_1 = recurr_dp(i-1);
    vec[i] = val_1;
    //cout << "vec[" << i << "]: " << vec[i] << "\n";
    return vec[i];
  }

  if(i-m[i] < 0)
  {
    val_1 = 0;
  }
  else
  {
    val_1 = (arr_sum[i] - arr_sum[i - m[i]]) + recurr_dp(i-m[i]);
  }
  val_2 = recurr_dp(i-1);
  vec[i] = max(val_1,val_2);
  //cout << "vec[" << i << "]: " << vec[i] << "\n";
  return vec[i];
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


  cin >> n;
  int sum=0;
  int fishes;
  int i;
  for(i=1;i<n+1;i++)
  {
    cin >> fishes;
    arr_sum[i] = fishes+sum;
    sum = arr_sum[i];
  }

  int ships;
  int anchor,length;
  cin >> ships;
  map<int,int>an;
  while(ships--)
  {
    cin >> anchor >> length;
    an[anchor] = length;
  }

  //With constraint
  int last = -645;

  for(auto it: an)
  {
    for(i=it.first;i<=it.first+it.second-1;i++)
    {
      if(i-it.second>=last)
      {
        m[i] = it.second;
      }
      else
      {
        m[i] = 0;
      }
    }
    last = it.first;
  }
  //End of constraint

  cout << recurr_dp(n) << "\n";
}
