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
string S;

signed main() {
    cin >> N;
    cin >> S;
    deque<int> L;
    vector<PI> X;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '(') {
            L.push_back(i);
        }
        if (S[i] == ')' && L.size() > 0) {
            int l = L.back();
            L.pop_back();
            X.push_back(PI(l, i));
        } 
    }
    vector<int> deleted(N+1, 0);
    for (auto x: X) {
        deleted[x.first] += 1, deleted[x.second+1] -= 1;
    }
    for (int i = 1; i < N; ++i) {
        deleted[i] += deleted[i-1];
    }
    for (int i = 0; i < N; ++i) if (deleted[i] == 0) cout << S[i];
    cout << endl;
}  