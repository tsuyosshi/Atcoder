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
vector<int> T, D;

signed main() {
    cin >> N;
    T.resize(N);
    D.resize(N);
    map<int, vector<int>> S;
    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> D[i];
        S[T[i]].push_back(i);
    }
    priority_queue<PI, vector<PI>, greater<PI>> pq;
    int ans = 0;
    int t = 0;
    while (true) {
        if (S.find(t) != end(S)) for (auto i: S[t]) pq.push(PI(T[i] + D[i], T[i]));
        if (pq.empty()) {
            auto itr = S.upper_bound(t);
            if (itr == end(S)) break;
            t = itr->first;
        } else {
            while (pq.size() > 0) {
                auto p = pq.top();
                pq.pop();
                if (p.first >= t) {
                    ans++;
                    break;
                }
            }
            t++;
        }
    }
    cout << ans << endl;
}                           