#include<bits/stdc++.h>
using namespace std;
//1D DP With Bottom Up Approach
//Not Even Fully DP It is a implemented using kadane algorithm
//Kadane algorithm is used for maximum or minimum subarray sum

int main()
{

  #ifndef ONLINE_JUDGE
    freopen("D:\\Project sunrise\\input.txt", "r", stdin);
    freopen("D:\\Project sunrise\\output.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int i;
  int t;
  int n;
  cin >> t;
  while(t--)
  {
    cin >> n;
    vector<long long>vec(n,0);
    for(i=0;i<n;i++)
    {
      cin >> vec[i];
    }
    vector<vector<long long>>front(2,vector<long long>(n,0));
    vector<vector<long long>>rear(2,vector<long long>(n,0));
    front[0][0] = vec[0]; //stores maxmimum values
    front[1][0] = vec[0]; //stores minimum values
    long long curr_max = vec[0];
    long long max_so_far = vec[0];
    long long curr_min = vec[0];
    long long min_so_far = vec[0];

    //taking from front
    for(i=1;i<n;i++)
    {
      //for maximum
      curr_max = max(vec[i],curr_max+vec[i]);
      max_so_far = max(curr_max,max_so_far);
      front[0][i] = max_so_far;

      //for minimum
      curr_min = min(vec[i],curr_min+vec[i]);
      min_so_far = min(curr_min,min_so_far);
      front[1][i] = min_so_far;
    }

    /*
    cout << "front values: \n";
    for(i=0;i<n;i++)
    {
      cout << front[1][i] << " ";
    }
    cout << "\n";
    */

    //taking from rear
    curr_max = vec[n-1];
    max_so_far = vec[n-1];
    curr_min = vec[n-1];
    min_so_far = vec[n-1];

    rear[0][n-1] = vec[n-1];
    rear[1][n-1] = vec[n-1];
    for(i=n-2;i>=0;i--)
    {
      //from maximum
      curr_max = max(vec[i],curr_max+vec[i]);
      max_so_far = max(curr_max,max_so_far);
      rear[0][i] = max_so_far;

      //for minimum
      curr_min = min(vec[i],curr_min+vec[i]);
      min_so_far = min(curr_min,min_so_far);
      rear[1][i] = min_so_far;
    }

    /*
    cout << "rear values: \n";
    for(i=0;i<n;i++)
    {
      cout << rear[1][i] << " ";
    }
    cout << "\n";
    */

    long long max_i = abs(front[0][0] - rear[1][1]);
    long long min_i = abs(front[1][0] - rear[0][1]);
    long long maxx = max(max_i,min_i);
    long long local_maxx;
    for(i=1;i<n-1;i++)
    {
      max_i = abs(front[0][i]-rear[1][i+1]);
      min_i = abs(front[1][i]-rear[0][i+1]);
      local_maxx = max(max_i,min_i);
      maxx = max(maxx,local_maxx);
    }
    cout << maxx << "\n";
  }
}
