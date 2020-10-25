/*
 * Contest     : IEEEXtreme
 * Team Name   : AlgoExperts
 * Question    : Coupon Codes
 * Created on  : Sunday, 25th October 2020 4:32:33 am
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

int hammingDist(string str1, string str2){
    int i = 0, count = 0;
    while (str1[i] != '\0'){
        if (str1[i] != str2[i])
            count++;
        i++;
    }
    return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin >> t;
  string in[t];
  for (int i = 0; i < t; i++) 
    cin >> in[i];
  sort(in, in + t);
  vector<pair<string, ll>> dic;
  ll counter = 1LL;
  for (int i = 1; i < t; i++) {
    if (in[i] == in[i - 1]) {
      counter++;
    } else {
      dic.push_back({in[i - 1], counter});
      counter = 1LL;
    }
  }
  dic.push_back({in[t - 1], counter}); 
  map<string, ll> dp;
  ll ans = 0;
  for (int i = t - 1; i >= 0; i--) {
    string& cur = dic[i].first;
    ll cnt = dic[i].second;
    for (int j = 0; j < 14; j++) {
      if (cur[j] == '-') continue;
      char temp = cur[j];
      cur[j] = '*';
      if (dp.count(cur)) ans += (cnt * dp[cur]);
      dp[cur] += cnt;
      cur[j] = temp;
    }
  }
  cout << ans << '\n';
	return 0;
}