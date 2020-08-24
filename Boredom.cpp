#include<bits/stdc++.h>
using namespace std;
//It is a simple Top Down 1D DP PROBLEM
//DONE WITH RECURSTION + MEMORIZATION
//Problem of Codeforces
map<long long,long long>m;
vector<long long>vec(100006,-1);

long long dp_recursion(long long n)
{
  //cout << "reucrr: " << n << "\n";
  if(n<=0)
  {
    return 0;
  }
  if(vec[n]!=-1)
  {
    //cout << "DP USED\n";
    return vec[n];
  }

  long long val_1 = (n*m[n]) + dp_recursion(n-2);
  long long val_2 = dp_recursion(n-1);

  vec[n] = max(val_1,val_2);
  //cout << "vec[" << n << "]: " << vec[n] << "\n";
  return vec[n];

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
  int n;
  cin >> n;
  long long number;
  long long maxx=-1;
  int i;
  for(i=0;i<n;i++)
  {
    cin >> number;
    m[number]++;
    if(number>maxx)
    {
      maxx = number;
    }
  }


  cout << dp_recursion(maxx) << "\n";

}
