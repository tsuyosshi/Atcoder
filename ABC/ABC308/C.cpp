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

bool comp(const PII& A, const PII& B) {
    if (A.first*B.second.first > B.first*A.second.first) {
        return true;
    } else if (A.first*B.second.first < B.first*A.second.first) {
        return false;
    } else {
        return A.second.second < B.second.second;
    }
}

int N;

signed main() {
    cin >> N;
    vector<PII> X;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        X.push_back(PII(a, PI(a+b, i)));
    }
    sort(X.begin(), X.end(), comp);
    for (auto x: X) cout << x.second.second+1 << " ";
    cout << endl;
}  