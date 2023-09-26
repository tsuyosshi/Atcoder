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

int N, Q;
vector<int> A;

signed main() {
    cin >> N;
    A.resize(N);
    vector<PII> S(N); // (起きた時刻, 起きた時間合計)
    for (int i = 0; i < N; ++i) cin >> A[i];
    S[0] = PII(A[0], PI(0, 0));
    for (int i = 1; i < N; ++i) {
        if (i % 2 != 0) {
            S[i] = PII(A[i], PI(S[i-1].second.first, i));
        } else {
            S[i] = PII(A[i], PI(S[i-1].second.first + A[i] - A[i-1], i));
        }
    }
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        auto itr_l = lower_bound(S.begin(), S.end(), PII(l, PI(0, 0)));
        auto itr_r = lower_bound(S.begin(), S.end(), PII(r, PI(0, 0)));
        if (itr_l->first != l) itr_l--;
        if (itr_r->first != r) itr_r--;
        int t_l = itr_l->second.first;
        if (itr_l->second.second % 2 != 0) t_l += (l - itr_l->first);
        int t_r = itr_r->second.first;
        if (itr_r->second.second % 2 != 0) t_r += (r - itr_r->first);
        cout << t_r - t_l << endl;
    }
}  