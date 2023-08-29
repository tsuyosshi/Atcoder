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

signed main() {
    int N, Q;
    string S;
    cin >> N;
    cin >> S;
    cin >> Q;
    vector<int> T, X;
    vector<char> C;
    for (int i = 0; i < Q; ++i) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;
        T.push_back(t);
        X.push_back(x);
        C.push_back(c);
    }
    int t = -1;
    for (int i = 0; i < Q; ++i) if (T[i] != 1) t = i;
    if (t != -1) {
        for (int i = 0; i < t; ++i) if (T[i] == 1) S[X[i]] = C[i];
        if (T[t] == 2) {
            transform(S.begin(), S.end(), S.begin(), ::tolower);
        } else {
            transform(S.begin(), S.end(), S.begin(), ::toupper);
        }
        for (int i = t+1; i < Q; ++i) S[X[i]] = C[i];
    } else {
        for (int i = 0; i < Q; ++i) S[X[i]] = C[i];
    }
    cout << S << endl;
}  