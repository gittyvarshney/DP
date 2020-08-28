#include<bits/stdc++.h>
using namespace std;
//very fantastic question of spoj
//It is a 2D DP Problem of bottom up approach

//In this question you have to find the probability of appearance of
//just left or just right or diagonal down cell in the expected sum

//now the lower row numbers can go in one direction similiar for the
//right column so at particular cell the probability of using the
//next cell is 1

//but for other cells the taking of next cell depends upon the
//next minimum cell and maximum cell which are to be considered
//multiply by 0.5 as their choosen probability are equal

double d_min(double a,double b,double c)
{
  double k = min(a,b);
  return min(k,c);
}

double d_max(double a,double b,double c)
{
  double k = max(a,b);
  return max(k,c);
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

  int t,n,m,i,j;
  cin >> t;
  while(t--)
  {
    cin >> n >> m;

    vector<vector<double>>arr(n,vector<double>(m,0));

    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        cin >> arr[i][j];
      }
    }

    vector<vector<double>>vec(n,vector<double>(m,0));

    vec[n-1][m-1] = arr[n-1][m-1]; //storing the lower left element

    for(j=m-2;j>=0;j--)
    {
      vec[n-1][j] = vec[n-1][j+1] + arr[n-1][j]; //all elements taken to be
    }//are to the left only

    for(i=n-2;i>=0;i--)
    {
      vec[i][m-1] = vec[i+1][m-1] + arr[i][m-1];//all elements taken to be
    }//are to the bottom only

    for(i=n-2;i>=0;i--)
    {
      for(j=m-2;j>=0;j--)
      {
        vec[i][j] = 0.5*(d_min(vec[i][j+1],vec[i+1][j],vec[i+1][j+1]) + d_max(vec[i][j+1],vec[i+1][j],vec[i+1][j+1])) + arr[i][j];
      }
    }

    cout << fixed << setprecision(6) << vec[0][0] << "\n";
  }
}
