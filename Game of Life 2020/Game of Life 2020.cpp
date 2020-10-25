/*
 * Contest     : IEEEXtreme
 * Team Name   : AlgoExperts
 * Question    : Game of Life 2020
 * Created on  : Sunday, 25th October 2020 11:58:07 pm
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

void print_board(const vector<vector<char>> &board) {
    for(size_t i = 0; i < board.size(); i++) {
        for(size_t j = 0; j < board.size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin >> t;
	while(t--){
    string s;
    int N, M;
    cin >> s >> N >> M;
    
    string r1, r2;
    r1 = s.substr(0, 5);
    r2 = s.substr(6, 5);
    
    vector<vector<char>> board(N, vector<char>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int g = 0; g < M; g++) {
       vector<pair<int,int>> to_change;
       
       for(int row = 0; row < N; row++) {
            for(int col = 0; col < N; col++) {
               int l,r,u,d;
               l = col == 0 ? N-1 : col-1;
               r = col == N-1 ? 0 : col+1;
               u = row == 0 ? N-1 : row-1;
               d = row == N-1 ? 0 : row+1;
               
               vector<pair<int,int>> positions = {{row, l}, {row, r}, {u, col}, {d, col}};
               int alive_count = 0;
               for(const pair<int,int> &p : positions)
                    if (board[p.first][p.second] == '1')
                        alive_count++;
                
                if (board[row][col] == '0') {
                    if (r1[alive_count] == '1')
                        to_change.push_back({row, col});
                }
                else {
                    if (r2[alive_count] != '1')
                        to_change.push_back({row, col});
                }
               
           }
       }
       
       for(const pair<int,int> &p : to_change) {
           char prev = board[p.first][p.second];
           board[p.first][p.second] = (prev == '0' ? '1' : '0');
       }
    }
    
    print_board(board);
	}
	return 0;
}