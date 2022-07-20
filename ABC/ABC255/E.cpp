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

signed main() {
    cin >> N >> M;
    vector<int> S(N), X(M);
    vector<int> A(N, 0);
    map<int, int> mp;
    for (int i = 0; i < N - 1; ++i) cin >> S[i];
    for (int i = 0; i < M; ++i) cin >> X[i];
    for(int i = 1; i < N; ++i) {
        if (i % 2 == 0) {
            A[i] = A[i - 1] + S[i - 1];
        }
        else {
            A[i] = A[i - 1] - S[i - 1];
        }
    }
    for (int i = 0; i < N; ++i) if (i % 2 != 0) A[i] = -A[i];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int diff = X[j] - A[i];
            if (i % 2 == 0) diff = -diff;
            mp[diff]++;
        }
    }
    int ma = -INF;
    for (auto m : mp) chmax(ma, m.second);
    cout << ma << endl;
}