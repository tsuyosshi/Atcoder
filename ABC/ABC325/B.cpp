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
vector<int> W, X;

signed main() {
    cin >> N;
    W.resize(N);
    X.resize(N);
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        cin >> W[i] >> X[i];
        mp[X[i]] += W[i];
    }
    int ans = 0;
    for (int i = 0; i < 24; ++i) {
        int cnt = 0;
        for (auto [key, value]: mp) {
            int t = (key + i) % 24;
            if (t >= 9 && t <= 17) cnt += value;
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;
}                           