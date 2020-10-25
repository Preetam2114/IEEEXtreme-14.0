/*
 * Contest     : IEEEXtreme
 * Team Name   : AlgoExperts
 * Question    : Rescue Mission
 * Created on  : Monday, 26th October 2020 12:17:37 am
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

struct day {
  long l, r, v;
  day(long l, long r, long v) {
      this->l = l;
      this->r = r;
      this->v = v;
  }
};

long max_soldiers(vector<long> &hideouts, const vector<day>& days) {
    long evacuated = 0;
    
    vector<long> rescue_opportunities(hideouts.size(), 0);
    for(const day& d: days) {
        for(long i = d.l; i <= d.r; i++) {
            rescue_opportunities[i]++;
        }
    }
    
    for(const day& d : days) {
        long candidates = 0;
        for (long i = d.l; i <= d.r; i++) {
            candidates += hideouts[i];
            hideouts[i] = 0;
            rescue_opportunities[i]--;
        }

        long to_evacuate = min(candidates, d.v);
        evacuated += to_evacuate;
        candidates -= to_evacuate;

        long best_hideout = d.l;
        for (long i = d.l+1; i <= d.r; i++) {
            if (rescue_opportunities[i] > rescue_opportunities[best_hideout])
                best_hideout = i;
        }
        hideouts[best_hideout] = candidates;
    }
    
    return evacuated;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin >> t;
	while(t--){
		// Code here
	}
	return 0;
}