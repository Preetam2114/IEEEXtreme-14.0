/*
 * Contest     : IEEEXtreme
 * Team Name   : AlgoExperts
 * Question    : Linearly Separable Samples
 * Created on  : Saturday, 24th October 2020 5:53:15 am
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

template<class InputIt1, class InputIt2>
bool intersect(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2){
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) {
            ++first1;
            continue;
        } 
        if (*first2 < *first1) {
            ++first2;
            continue;
        } 
        return true;
    }
    return false;
}

constexpr unsigned int shash(const char *s, int off = 0){                        
    return !s[off] ? 5381 : (shash(s, off+1)*33) ^ s[off];                           
}

typedef long long ll;
typedef long double ld;
typedef long double f80;
typedef pair<int, int> pii;
const ll mod = 1e9;
const double PI = 3.14159265;
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////

struct point {
  float x1, x2;
  int y;
  point(float x1, float x2, int y) {
      this->x1 = x1;
      this->x2 = x2;
      this->y = y;
  }
};

float tang(float deg) {
    return tan ( deg * PI / 180.0 );
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin >> t;
	while(t--){
        int n;
        cin >> n;
        float x1, x2;
        int y;
        vector<point> points;
        rep(i,0,n-1){
            cin >> x1 >> x2 >> y;
            points.push_back(point(x1,x2,y));
        }

        bool separate = false;
        for(float angle = 0; angle < 360.0; angle += 0.1) {
            float slope = tang(angle);
            
            bool finished = true;
            for (point& p : points){
                float yval = p.x1 * slope;
                if ((p.y == -1 && p.x2 > yval) || (p.y == 1 && p.x2 < yval)) {
                    finished = false;
                    break;
                }
            }
            if(finished) {
                separate = true;
                break;
            }
        }
        cout << (separate ? "YES" : "NO") << endl;
        
    }
	return 0;
}