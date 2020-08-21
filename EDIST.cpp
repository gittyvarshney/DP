#include<bits/stdc++.h>
using namespace std;
//It is a famous Edit Distance question
//A problem of 2D DP which is implemented using recurrsion + Memorization
//this problme can also be done using bottom up approach

//The question is based on simple implementation i.e.
//either be replace both the characters if they are not equal
//or delete the current character or insert the unmatched character
//If we recurr for this we get many overlapping subproblems
//which can be memorized



int recurr_dp(string&a,string&b,int n, int m, vector<vector<int>>&vec)
{
  if(n==0)
  {
    return m;
  }
  if(m==0)
  {
    return n;
  }

  if(vec[n-1][m-1] != -1)
  {
    return vec[n-1][m-1];
  }

  if(a[n-1] == b[m-1])
  {
    return recurr_dp(a,b,n-1,m-1,vec);
  }



  vec[n-1][m-1] = 1 + min(min(recurr_dp(a,b,n-1,m,vec),recurr_dp(a,b,n,m-1,vec)),recurr_dp(a,b,n-1,m-1,vec));
  return vec[n-1][m-1];

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
  string str_a;
  string str_b;
  int n;
  int m;
  cin >> t;
  while(t--)
  {
    cin >> str_a;
    cin >> str_b;
    n = str_a.size();
    m = str_b.size();
    //cout << str_a << " length: " << n << "\n";
    //cout << str_b << " length: " << m << "\n";
    vector<vector<int>>vec(n,vector<int>(m,-1));
    cout << recurr_dp(str_a,str_b,n,m,vec) << "\n";
  }
}
