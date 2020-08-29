#include<bits/stdc++.h>
using namespace std;
//Very fantastic question of TopCoder
//It is a 4D DP Problem which can be solved in a top down recurssion + memorization
//method
//You have to think is that at the last song you have finished exhausted
//all required songs of three of the singer now what are the ways you can come to that
//song from the last one also remember each song have to sang by atleast one of the
//singer
//This DP Problem can be used as a base for all the problems in which you have to
//calculate the ways at each of the levels have fun

//4D Vector
vector<vector<vector<vector<long long>>>>vec(52,vector<vector<vector<long long>>>(52,vector<vector<long long>>(52,vector<long long>(52,-1))));
const int mod = 1e9 + 7;

int recurr_dp(int n,int a,int b,int c)
{
  if(n<0 || a<0 || b<0 || c<0)
  {
    //cout << "returning 0 n: " << n << "\n";
    return 0;
  }

  if(n==0)
  {
    if(a==0 && b==0 && c==0)
    {
      //cout << "returning 1 \n";
      return 1;
    }
    else
    {
      return 0;
    }
  }

  if(vec[n][a][b][c] != -1)
  {
    //cout << "DP Used \n";
    return vec[n][a][b][c];
  }

  long long total_ways=0;
  if(a==n && b<n && c<n)//then you have to subtract that number for sure
  //also note that we do not have to make a explicit if for b==n
  //as it is a which is always be greater then comes b and c
  {
    total_ways += recurr_dp(n-1,a-1,b,c) %mod;
    total_ways += recurr_dp(n-1,a-1,b-1,c) %mod;
    total_ways += recurr_dp(n-1,a-1,b-1,c-1) %mod;
    total_ways += recurr_dp(n-1,a-1,b,c-1) %mod;
  }
  else if(a==n && b==n && c<n) //have to subtract both
  {
    total_ways += recurr_dp(n-1,a-1,b-1,c) %mod;
    total_ways += recurr_dp(n-1,a-1,b-1,c-1) %mod;
  }
  else if(a==n && b==n && c==n) // have to subtract all
  {
    total_ways += recurr_dp(n-1,a-1,b-1,c-1) %mod;
  }
  else //no boundation
  {
    total_ways += recurr_dp(n-1,a-1,b,c)%mod;
    total_ways += recurr_dp(n-1,a,b-1,c)%mod;
    total_ways += recurr_dp(n-1,a,b,c-1)%mod;
    total_ways += recurr_dp(n-1,a-1,b-1,c)%mod;
    total_ways += recurr_dp(n-1,a-1,b,c-1)%mod;
    total_ways += recurr_dp(n-1,a,b-1,c-1)%mod;
    total_ways += recurr_dp(n-1,a-1,b-1,c-1)%mod;
  }
  vec[n][a][b][c] = total_ways%mod;
  //cout << "vec[" << n << "][" << a << "][" << b << "][" << c << "]: " << vec[n][a][b][c] << "\n";
  return vec[n][a][b][c];
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

  int n_songs,gumi,ia,mayu;
  int a,b,c; //for always making a as maximum & so on, as we only have
  //to calculate the number of ways anyway

  cin >> n_songs>>gumi>>ia>>mayu;
  int sum = gumi+ia+mayu;
  a = max(gumi,max(ia,mayu));
  c = min(gumi,min(ia,mayu));
  b = sum-(a+c); //middle element
  //cout << "a: " << a << " b: " << b << " c: " << c << "\n";
  cout << recurr_dp(n_songs,a,b,c);
}
