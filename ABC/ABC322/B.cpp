#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int, int> PI;
typedef pair<int, pair<int, int>> PII;
static const int INF = 1010000000000000017LL;
static const double eps = 1e-12;
static const double pi = 3.14159265358979323846;
static const int dx[4] = {1, -1, 0, 0};
static const int dy[4] = {0, 0, 1, -1};
static const int ddx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
static const int ddy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }

int N, M;
string S, T;

signed main(){
    cin >> N >> M;
    cin >> S >> T;
    string pre_str = T.substr(0, N), suf_str = T.substr(M-N,N);
    // cout << pre_str << " " << suf_str << endl;
    if (S == pre_str && S == suf_str) {
        cout << 0 << endl;
    } else if (S == pre_str) {
        cout << 1 << endl;
    } else if (S == suf_str) {
        cout << 2 << endl; 
    } else {
        cout << 3 << endl;
    }
}