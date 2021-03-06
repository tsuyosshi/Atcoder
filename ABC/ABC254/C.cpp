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

int N, K;

signed main(){
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<vector<int>> V(K);
    for (int i = 0; i < N; ++i) V[i % K].push_back(A[i]);
    for (int i = 0; i < K; ++i) sort(V[i].begin(), V[i].end(), greater<int>());
    vector<int> res;
    for (int i = 0; i < N; ++i) {
        res.push_back(V[i % K].back());
        V[i % K].pop_back();
    }
    sort(A.begin(), A.end());
    if (A == res) cout << "Yes" << endl;
    else cout << "No" << endl;
}