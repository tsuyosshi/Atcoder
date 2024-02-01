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

int powi(int x, int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) res *= x;
    return res;
}

void calc(int key, map<int, int> &mp) {
    int value = mp[key];
    mp[key] = 0;
    while (value > 0) {
        int k = floor(log2(value));
        value -= powi(2, k);
        mp[key * powi(2, k)] += 1;
    }
}

int N;
vector<int> S, C;

signed main() {
    cin >> N;
    S.resize(N);
    C.resize(N);
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> C[i];
        mp[S[i]] += C[i];
    }
    int ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) calc(itr->first, mp);
    for (auto &[key, value]: mp) if (value > 0) ans++;
    cout << ans << endl;
}                           