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

map<string , int> mp = {{"tourist", 3858},
{"ksun48", 3679},
{"Benq", 3658},
{"Um_nik", 3648},
{"apiad", 3638},
{"Stonefeang", 3630},
{"ecnerwala", 3613},
{"mnbvmar", 3555},
{"newbiedmy", 3516},
{"semiexp", 3481},
};

signed main() {
    string S;
    cin >> S;
    cout << mp[S] << endl;

}  