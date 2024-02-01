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
vector<int> A;

signed main() {
    cin >> N >> M;
    A.resize(M);
    vector<int> S(N, 0);
    vector<set<int>> st(N);
    for (int i = 0; i < M; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) if (s[j] == 'o') {
            S[i] += A[j];
            st[i].insert(j);
        }
        S[i] += i+1;
    }
    vector<PI> B(M);
    for (int i = 0; i < M; ++i) B[i] = PI(A[i], i);
    sort(B.begin(), B.end(), greater<PI>());
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        int ma = -INF;
        int v = S[i];
        // cout << i << " " << S[i] << endl;
        for (int j = 0; j < M; ++j) if (j != i) chmax(ma, S[j]);
        for (int j = 0; j < M; ++j) {
            if (st[i].find(B[j].second) == end(st[i]) && v <= ma) {
                v += B[j].first;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}                           