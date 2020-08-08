#include<bits/stdc++.h>
using namespace std;
//It is a type of DP problem where you can't think of it
//so you just recurr to answer and when TLE happens just
//make a DP Table to see it something happens
vector<vector<int>>vec(1005,vector<int>(5005,-1));
vector<char>equation;
int size;
//bottom up approach
int recurrance(int i, int sum)
{
  //cout << "sum: " << sum << " and " << i << "\n";
  if(i>= size)
  {
    if(sum==0)
    {
      return 0;
    }
    //cout << "returning 1009 \n";
    return 1009; //1009 is used as max plus can't go more than 999
  }
  else if(vec[i][sum] != -1)
  {
    //cout << "DP used \n";
    return vec[i][sum];
  }
  int digits_build = 0; //building the digit to be considered in the sum
  int k;
  int maxx_pluses = 1009;

  for(k=i;k<size;k++)
  {
    //cout << "\tat " << equation[i] << "\n";
    digits_build = digits_build*10 + (equation[k] - '0');
    if(digits_build> sum)//if next to be added is greater than the current sum
    {//then there is no need to consider it
      break;
    }
    maxx_pluses = min(maxx_pluses,1+recurrance(k+1,sum-digits_build));
  }
  vec[i][sum] = maxx_pluses;
  //cout << "returning : " << maxx_pluses << "\n";
  return maxx_pluses;
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
  string st;
  cin >> st;
  int c=0;
  for(i=0;st[i]!='=';i++)
  {
    if(st[i]!='0')
    {
      equation.emplace_back(st[i]);
      c=0;
    }
    else if(st[i]=='0' && c<3)
    {
      equation.emplace_back(st[i]);
      c++;
    }
  }
  size = equation.size();
  //cout << "equation size is: " << size << "\n";
  //cout << "equation is: ";
  /*
  for(auto v: equation)
  {
    cout << v;
  }
  */
  //cout << "\n";
  int sum=0;
  for(j=i+1;st[j]!='\0';j++)
  {
    sum = sum*10 + (st[j] - '0');
  }
  int min_pluses = recurrance(0,sum);
  cout << min_pluses-1 << "\n";
}
