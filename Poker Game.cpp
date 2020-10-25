/*
 * Contest     : IEEEXtreme
 * Team Name   : AlgoExperts
 * Question    : Poker Game
 * Created on  : Saturday, 24th October 2020 11:35:05 pm
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	// cin >> t;
	while(t--){
		int k,n;
    cin>>k>>n;
    map<char,bool> cards;
    cards['2'] = 0;
    cards['3'] = 0;
    cards['4'] = 0;
    cards['5'] = 0;
    cards['6'] = 0;
    cards['7'] = 0;
    cards['8'] = 0;
    cards['9'] = 0;
    cards['X'] = 0;
    cards['J'] = 0;
    cards['Q'] = 0;
    cards['K'] = 0;
    cards['A'] = 0;
    map<char,char> hand;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    rep(i,0,k-1){
      hand[s1[i]]=s2[i];
      if(hand.find(s1[i]) == hand.end()&&hand[s1[i]]=='y'){
        cards[s1[i]]=1;
      }
    }
    for(auto a: cards){
      cout<<a.F<<" "<<a.S<<endl;
    }
	}
	return 0;
}