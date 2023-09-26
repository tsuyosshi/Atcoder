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
int X, Y;
vector<int> P, T;
map<int, int> mp;

int calc(int q) {
    if (mp.find(q%8) != end(mp)) return mp[q%8];
    int t = q;
    cout << t << endl;
    for (int i = 0; i < N-1; ++i) {
        if (t % P[i] == 0) {
            t += T[i];
        } else {
            int k = t/P[i] + 1;
            t = k*P[i] + T[i];
        }
        cout << t << endl;
    }
    cout << "res: " << t - q << endl;
    return mp[q%8] = t - q;
}

signed main() {
    cin >> N >> X >> Y;
    P.resize(N-1);
    T.resize(N-1);
    for (int i = 0; i < N-1; ++i) cin >> P[i] >> T[i];
    int Q;
    cin >> Q;
    while (Q--) {
        int q;
        cin >> q;
        q += X;
        q += calc(q);
        q += Y;
        cout << q << endl;
    }
}  