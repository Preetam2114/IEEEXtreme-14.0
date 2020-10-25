/*
 * Contest     : IEEEXtreme
 * Team Name   : AlgoExperts
 * Question    : Crafting Wooden Tables
 * Created on  : Saturday, 24th October 2020 10:32:46 am
 */


#include <bits/stdc++.h>

using namespace std;

#ifndef preetam
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#define F first
#define S second 
#define pb push_back 
#define mp make_pair
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

void getIndex(vector<int> v, int K){ 
    auto it = find(v.begin(), v.end(), K); 
    if (it != v.end()) {
        int index = distance(v.begin(),it); 
        cout << index << endl; 
    }
    else{
        cout << "-1" << endl; 
    } 
}

ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	// cin >> t;
	while(t--){
		int64_t c,n,p,w;
    cin>>c>>n>>p>>w;
    int64_t w1=w;
    vector<ll> v;
    while(w){
      if(w-p>0){
        v.pb(p);
        w -= p;
      }
      else
      {
        v.pb(w);
        w = 0;
      }
    }
    if(c>w1){
      cout<<0<<endl;
      continue;
    }
    ll looping = v.size();
    bool flag =true;
    ll cnt =0;
    sort(all(v));
    while(flag){
      if(count(all(v),c)!=0){
        int64_t ind = *find(all(v),c);
        v.erase(v.begin()+ind);
        cnt += 1;
      }
      else{
        int64_t mini = *min_element(all(v));
        int64_t ind = *find(all(v),mini);
        if (mini < c){
          for i,pile in enumerate(v):
            indp = m
            if pile>=mini and i!=ind:
              indp = pockets.index(pile)
              break
          if indp == m:
            print(t)
            flag = True
            break
          pockets[indp] = p-(c-mini)
          pockets.pop(ind)
          t += 1
        else:
          if m < n:
            pockets[ind] -= c
            m += 1
            t += 1
          else:
            print(t)
            flag = True
        }
    }
	}
	return 0;
}