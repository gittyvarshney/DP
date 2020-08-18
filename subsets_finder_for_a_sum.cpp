#include<bits/stdc++.h>
using namespace std;

//It is a type of 2D DP Problem where you have to find a subsets of particular
//sum type.
//In which gonna think to implement recurssion for every subset possible
//but what we have to do is to check for the number of subsets in the next i+1th
//index for sum = (-sum+required_sum) so that our sum can becomes the required sum
//we have to do this for every index visited
//if i==n then we check if our sum is equals to required sum or not if equal
//then [i-1][-sum+required_sum] = 1

//it is to be noted that index offsetting is done only to avoid the negative
//indexes in the array if the numbers are also negatives in the array

int n;
int index_offset;
int sub_set_type;

int recurr_dp(int i,int sum,vector<vector<int>>& vec,vector<int>& v)
{
  if(i==n)
  {
    if(sum==sub_set_type)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  //if we have zero we need only -sum what if any other number we need -sum + that_number
  if(vec[i][index_offset-(sum+sub_set_type)]!= -1)
  {
    return vec[i][index_offset-(sum+sub_set_type)];
  }

  //we can either include that number to sum or we can either not include it to the sum
  //in both cases the required -sum will be different
  vec[i][index_offset-(sum+sub_set_type)] = recurr_dp(i+1,sum,vec,v) + recurr_dp(i+1,sum+v[i],vec,v);

  //return the number of ways to get that -sum from that index
  return vec[i][index_offset-(sum+sub_set_type)];

}


int main()
{
  /*
  #ifndef ONLINE_JUDGE
    freopen("D:\\Project sunrise\\input.txt", "r", stdin);
    freopen("D:\\Project sunrise\\output.txt", "w", stdout);
  #endif
  */
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int i;
  cin >> n; //provide the length of array
  cin >> sub_set_type; //provide the subset sums required
  vector<int>v(n,0);
  int min_possible=0;
  int max_possible=0;
  for(i=0;i<n;i++) //provide the array
  {
    cin >> v[i];
    if(v[i]<0)
    {
      min_possible-= v[i];
    }
    if(v[i]>0)
    {
      max_possible+=v[i];
    }
  }
  int total = min_possible + max_possible;
  //cout << "total = " << total << "\n";
  index_offset = max_possible+sub_set_type;
  //cout << "Index offset= " << index_offset << "\n";
  vector<vector<int>>vec(n,vector<int>(total+sub_set_type+1,-1));
  cout << recurr_dp(0,0,vec,v);
}
