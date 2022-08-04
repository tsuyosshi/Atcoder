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

signed main(){
    cin >> N >> M;
    vector<PI> P;
    int min_b = INF;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        P.push_back(PI(a, b));
        chmin(min_b, b);
    }
    set<int> st;
    map<int, vector<int>> mp;
    for (auto p : P) {
        st.insert(p.first);
        mp[p.first].push_back(p.second);
    }
    vector<int> f(2 * M, 0);
    for (int i = 1; i <= min_b; ++i) {
        // i を始点とする場合
        auto itr = st.end();
        itr--;
        int ma = *itr;
        if (i <= ma) {
            f[ma - i + 1] += 1;
            f[M - i + 2] -= 1;
        }
        for (auto v : mp[i]) st.insert(v);
        st.erase(i);
    }
    for (int i = 1; i <= M; ++i) f[i] += f[i - 1];
    for (int i = 1; i <= M; ++i) {
        cout << f[i] << " ";
    }
    cout << endl;
}