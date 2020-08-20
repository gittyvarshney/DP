#include<bits/stdc++.h>
using namespace std;
//Simple 1DP implementation but implemented with hash map
//question of codechef

int main()
{

  #ifndef ONLINE_JUDGE
    freopen("D:\\Project sunrise\\input.txt", "r", stdin);
    freopen("D:\\Project sunrise\\output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  map<int,int>m;
  map<int,int>mp;
  int n,k,p,i;
  cin >> n >> k >> p;
  vector<int>vec(n,0);
  for(i=0;i<n;i++)
  {
    cin >> vec[i];
    m[i+1] = vec[i];
  }

  sort(vec.begin(),vec.end());
  int pairs=1;
  mp[vec[0]] = 1;
  for(i=1;i<n;i++)
  {
    if(vec[i]-vec[i-1] <= k)
    {
      mp[vec[i]] = pairs;
    }
    else
    {
      mp[vec[i]] = ++pairs;
    }
  }
  int a,b;
  /*
  cout << "printing map \n";
  for(auto j: mp)
  {
    cout << j.first << "-> " << j.second << "\n";
  }
  */
  while(p--)
  {
    cin >> a >> b;
    if(mp[m[a]] == mp[m[b]])
    {
      cout << "Yes\n";
    }
    else
    {
      cout << "No\n";
    }
  }
}
