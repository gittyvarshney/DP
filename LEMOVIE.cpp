#include<bits/stdc++.h>
using namespace std;
//Very Nice question of Codechef
//It is not even a fully DP question but more algorithm based
//Can Say 1D bottom up DP
//you have to make a system to count the number of permutations
//for a particular level for every number inserted
//call this algorithm as 'Permut recaller algorithm'

const long long mod = 1e9+7;

int Premut_recaller_algorithm(map<long long,long long>&m,vector<long long>&vec,long long k)
{
  map<long long, long long>::reverse_iterator it;
  vector<long long>arr; //insert the elements stored in map to the vector for
  //simplicity
  for(it=m.rbegin();it!=m.rend();it++)
  {
    arr.emplace_back(it->second);
  }

  long long n =arr.size();
  long long permut_size=0;
  for(int i=0;i<n;i++)
  {
    //cout << "i = " << i << "\n";
    long long cal_ways=1;
    for(long long j= permut_size+1;j<permut_size+arr[i];j++)
    {
      cal_ways=(cal_ways%mod * j%mod)%mod; //calculate the ways of putting the elements in between
      //the numbers intitally so don't have to calculate again
      //(size)*(size+1)*(size+n-1) but calculating from (size+1)*(size+n-1)
      //so we can multiply size afterwards
    }

    for(int r = k; r>0; r--)
    {
      vec[r] *= (cal_ways%mod * permut_size%mod)%mod; //total ways we can retain the original r
      vec[r] += ((vec[r-1]%mod *arr[i] %mod)%mod *cal_ways%mod)%mod; //total ways we can make new r's from the r-1
      vec[r] = vec[r]%mod;
      //cout << "vec[" << r << "]: " << vec[r] << "\n";
    }

    vec[0]=0; //remains zero for size of permut greater than equals 1
    permut_size+=arr[i];
  }

  long long sum=0;
  for(int i=0;i<=k;i++)
  {
    sum = (sum%mod + vec[i]%mod)%mod;
  }
  return sum;
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
  long long temp,n,k;
  cin >> t;
  while(t--)
  {
    map<long long,long long>m;
    cin >> n >> k;
    vector<long long>vec(k+1,0);
    vec[0] = 1;
    for(int i=0;i<n;i++)
    {
      cin >> temp;
      m[temp]++;
    }

    cout << Premut_recaller_algorithm(m,vec,k) << "\n";

  }
}
