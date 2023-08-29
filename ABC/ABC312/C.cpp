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

bool ok(int x, vector<int> &A, vector<int> &B) {
    int a = 0, b = 0;
    for (int i = 0; i < N; ++i) if (x >= A[i]) a++;
    for (int i = 0; i < M; ++i) if (x <= B[i]) b++;
    return a >= b;
}

signed main() {
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];
    int l = 0, r = 1000000005;
    while (r - l > 1) {
        int mid = (l+r) / 2;
        if (ok(mid, A, B)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (ok(l, A, B)) {
        cout << l << endl;
    } else {
        cout << r << endl;
    }
}   