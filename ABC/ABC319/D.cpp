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
vector<int> L;

bool check(int x) {
    int line = 0;
    int pos = 0;
    for (int i = 0; i < N; ++i) if (L[i] > x) return false;
    for (int i = 0; i < N; ++i) {
        if (pos + L[i] > x) {
            line++;
            pos = L[i] + 1;
        } else {
            pos += L[i] + 1;
        }
    }
    return line + 1 <= M;
}

signed main() {
    cin >> N >> M;
    L.resize(N);
    for (int i = 0; i < N; ++i) cin >> L[i];
    int l = 0, r = INT64_MAX;
    while (r - l > 1) {
        int mid = (l+r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) cout << l << endl;
    else cout << r << endl;
}  