#include<bits/stdc++.h>
using namespace std;
//Very Nice problem of Edit Distance with modification in this problem
//you have two strings with length upt 10^5
//but the problem greedily put some inputs with the problem
//to lower that possible combinations
//Anyway it is a 2D DP PROBLEM which can be down with recursion + memorization
//technique

int a,b,k;
const int inf = 0x3f3f3f3f;

int recurr_dp(string& s,string& w, int n, int m,vector<vector<int>>&vec)
{
  if(n==0)
  {
    return (a*m);
  }
  if(m==0)
  {
    return (a*n);
  }

  if((abs(n-m)*a)>k) //it is given in problem that time cannot
  {//go beyound k if that happend you have to just return a very big number
    return inf;
  }

  //100+ is added to offset the negative n-m
  //so the DP Vector is [n][200] size. i.e. 10^5 x 200 = 2 x 10^7
  //which is in feasible memory
  if(vec[n][100+n-m] != -1)
  {
    //cout << "DP USED\n";
    return vec[n][100+n-m];
  }

  if(s[n-1] == w[m-1])
  {
    vec[n][100+n-m] = recurr_dp(s,w,n-1,m-1,vec);
    return vec[n][100+n-m];
  }

  int val_1;
  int val_2;
  int val_3;
  //replace
  val_1 = b + recurr_dp(s,w,n-1,m-1,vec);
  val_2 = a + recurr_dp(s,w,n,m-1,vec);
  val_3 = a + recurr_dp(s,w,n-1,m,vec);
  vec[n][100+n-m] = min(min(val_1,val_2),val_3);
  return vec[n][100+n-m];
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
  string s;
  string w;
  int t;
  cin >> t;
  while(t--)
  {
    cin >> s;
    cin >> w;
    cin >> a >> b >> k;

    int n= s.size();
    int m= w.size();

    if(a==0)
    {
      cout << 0 << "\n";
      continue;
    }
    if(abs(n-m) * a > k)
    {
      cout << -1 << "\n";
      continue;
    }

    vector<vector<int>>vec(n+1,vector<int>(209,-1));
    int a = recurr_dp(s,w,n,m,vec);
    if(a>k)
    {
      cout << -1 << "\n";
    }
    else
    {
      cout << a << "\n";
    }
  }
}
