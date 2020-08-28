#include<bits/stdc++.h>
using namespace std;
//Nice problem of spoj
//It is a 2D DP Problem with recurrsion + memorization
//You have to think how you could make this problem into
//a DP Recuursion problem by using prefix or suffix sum
//which are common in the DP Problems of such type

int n,m;
vector<vector<int>>arr_ye(503,vector<int>(503,0));
vector<vector<int>>arr_bl(503,vector<int>(503,0));

int recurr_dp(int i,int j,vector<vector<int>>&vec)
{
  if(i>=n || j>=m)
  {
    return 0;
  }

  if(vec[i][j] != -1)
  {
    //cout << "DP Used \n";
    return vec[i][j];
  }

  int val_1,val_2;
  val_1 = arr_ye[i][j] + recurr_dp(i,j+1,vec);
  //cout << val_1 << "\n";
  val_2 = arr_bl[i][j] + recurr_dp(i+1,j,vec);
  //cout << val_2 << "\n";
  vec[i][j] = max(val_1,val_2);
  //cout << "vec[" << i << "]" << "[" << j << "]: " << vec[i][j] << "\n";
  return vec[i][j];
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

  int i,j;
  while(true)
  {
    cin >> n >> m;
    if(n==0 && m==0)
    {
      break;
    }
    vector<vector<int>>vec(n+1,vector<int>(m+1,-1));
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        cin >> arr_ye[i][j];
      }
    }
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        cin >> arr_bl[i][j];
      }
    }

    //for yeyenum
    for(j=0;j<m;j++)
    {
      for(i=n-2;i>=0;i--)
      {
        arr_ye[i][j] +=arr_ye[i+1][j];
      }
    }

    //for bloggium
    for(i=0;i<n;i++)
    {
      for(j=m-2;j>=0;j--)
      {
        arr_bl[i][j] += arr_bl[i][j+1];
      }
    }
    cout << recurr_dp(0,0,vec) << "\n";
  }
}
