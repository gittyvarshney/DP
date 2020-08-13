#include<bits/stdc++.h>
using namespace std;
//Problem named ZigZag of TopCoder
//It is a type of 2D DP problem in which you have to find the longest
//subsequence with alternate positive and negative sums
//the columns of DP is of two length first [0] i.e. if approached for
//next -ve what is maximum length & [1] means if approached for next +ve
//what is the maximum length
//It is to be noted that this problem can be done in O(n) time without DP

vector<int>seq(1001,-1);
vector<vector<int>>vec(1001,vector<int>(2,-1));
int n;

int recurrance(int index, int sign)
{
  //cout << "at index: " << index << " with sign: " <<  sign << "\n";
  int pos_sub= 1;
  int neg_sub= 1;
  int i;
  if(sign == 1)
  {
    if(vec[index][1] != -1)
    {
      //cout << "DP USED FOR +VE AT index " << index << "\n";
      return vec[index][1];
    }
    for(i = index+1;i<n;i++)
    {
      if(seq[i]- seq[index] >= 1)
      {
        pos_sub = 1 + recurrance(i,-1);
        break;
      }
    }
    for(i = index+1;i<n;i++)
    {
      if(seq[i] - seq[index] <= -1)
      {
        neg_sub = recurrance(i,1);
        break;
      }
    }
    vec[index][1] = max(pos_sub,neg_sub);
    //cout << "+ve index: " << index << " returning: " << vec[index][1] << "\n";
    return vec[index][1];
  }
  else
  {
    if(vec[index][0] != -1)
    {
      //cout << "DP USED FOR -VE AT index " << index << "\n";
      return vec[index][0];
    }
    for(i = index+1;i<n;i++)
    {
      if(seq[i]- seq[index] <= -1)
      {
        neg_sub = 1 + recurrance(i,1);
        break;
      }
    }
    for(i = index+1;i<n;i++)
    {
      if(seq[i] - seq[index] >= 1)
      {
        pos_sub = recurrance(i,-1);
        break;
      }
    }
    vec[index][0] = max(pos_sub,neg_sub);
    //cout << "-ve index: " << index << " returning: " << vec[index][0] << "\n";
    return vec[index][0];
  }
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
  int i;
  cin >> n;
  for(i=0;i<n;i++)
  {
    cin >> seq[i];
  }

  for(i=1;i<n;i++)
  {
    if(seq[i] - seq[0] >= 1)
    {
      break;
    }
  }
  int pos_sub = 1 + recurrance(i,-1);

  for(i=1;i<n;i++)
  {
    if(seq[i] - seq[0] <= -1)
    {
      break;
    }
  }
  int neg_sub = 1 + recurrance(i,1);
  cout << max(pos_sub,neg_sub) << "\n";
}
