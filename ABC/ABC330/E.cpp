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

void puts_yn(bool flag) { if (flag) { puts("Yes"); } else { puts("No"); }  }

int N, Q;
vector<int> A;

signed main() {
    cin >> N >> Q;
    A.resize(N);
    map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        mp[A[i]]++;
    }
    set<int> st;
    for (int i = 0; i <= 2 * N; ++i) st.insert(i);
    for (int i = 0; i < N; ++i) st.erase(A[i]);
    while (Q--) {
        int i, x;
        cin >> i >> x;
        i--;
        if (mp[A[i]] - 1 == 0) st.insert(A[i]);
        mp[A[i]]--;
        mp[x]++;
        st.erase(x);
        A[i] = x;
        // for (auto x: st) cout << x << " ";
        // cout << endl;
        cout << *st.lower_bound(0) << endl;
    }
}                           