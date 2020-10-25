/*
 * Contest     : IEEEXtreme
 * Team Name   : AlgoExperts
 * Question    : Identifying Infected
 * Created on  : Saturday, 24th October 2020 11:49:19 am
 */


#include <bits/stdc++.h>

using namespace std;

/////////////////////////////////////////// Template ////////////////////////////////////////////
#ifndef preetam
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define F first
#define S second 
#define pb push_back 
#define MP make_pair
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define inputarr(arr,n) for(int i = 0; i < n; i++) cin>>arr[i];
#define inputmat(arr,a,b) for(int i=0; i < a; i++)for(int j=0; j < b; j++)cin>>arr[i][j];
#define print(arr) for(auto a:arr) cout<<a<<" "; cout<<"\n";
#define all(ar) ar.begin(), ar.end()
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))
#define endl '\n'

#ifndef preetam
template<typename KeyType, typename ValueType> 
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>; 
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  }); 
}

template <class Container>
void split(const std::string& str, Container& cont){
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(cont));
}

constexpr unsigned int shash(const char *s, int off = 0){                        
    return !s[off] ? 5381 : (shash(s, off+1)*33) ^ s[off];                           
}

typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
const ll mod = 1e9;
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 1e5;
vector<int>gp[N];
map<int,int>mp;

void visit(int a){
    if(gp[a].size()>2) return ;
    for(auto x: gp[a])
    {
        if(mp[x]==1) continue;
        else
        {
            mp[x]++;
            visit(x);
 
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int n,m;
  cin >> n >> m ;
  rep(i,0,m-1){
      int x, y ;
      cin >> x >> y ;
      gp[x].push_back(y);
      gp[y].push_back(x);
  }
  int q ;
  cin >> q ;
  while(q--){
    int a , b ;
    int cnt=0;
    cin >> a >> b ;
    mp.clear();
    mp[a]++;
    mp[b]++;
    if(gp[b].size()==1){
        if(gp[b][0]!=a){
            mp[gp[b][0]]++;
            visit(gp[b][0]);
        }
    }
    cout<<mp.size()<<endl;
  }
	return 0;
}