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

signed main() {
    cin >> N >> K;
    vector<PI> X;
    int sum = 0;
    int day = 1;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        X.push_back(PI(a, b));
        sum += b;
    }
    if (sum <= K) {
        cout << 1 << endl;
    }
    else {
        sort(X.begin(), X.end());
        for (auto x: X) {
            if (sum <= K) break;
            day = x.first;
            sum -= x.second;
        }
        cout << day + 1 << endl;
    }
}  