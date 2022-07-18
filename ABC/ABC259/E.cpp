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

int N;

signed main() {
    cin >> N;
    vector<map<int, int>> X(N); 
    map<int, PI> max_e;
    for (int i = 0; i < N; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int p, e;
            cin >> p >> e;
            X[i][p] = e;
            if (max_e.find(p) == end(max_e) || max_e[p].first < e) {
                max_e[p] = PI(e, 1);
            }
            else if (max_e[p].first == e) {
                max_e[p].second++;
            }
        }
    }
    int ans = 0;
    bool nonchanged = false;
    for (int i = 0; i < N; ++i) {
        bool changed = false;
        for (auto x : X[i]) {
            int p = x.first, e = x.second;
            if (max_e[p].first == e && max_e[p].second == 1) {
                ans++;
                changed = true;
                break;
            }
        }
        if (!changed) nonchanged = true;
    }
    if (nonchanged) ans++;
    cout << ans << endl;
}