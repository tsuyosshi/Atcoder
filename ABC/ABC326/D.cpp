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
string R, C;
bool ok = false;

bool check1(vector<string> &S) {
    for (int i = 0; i < N; ++i) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0; 
        for (int j = 0; j < N; ++j) {
            if (S[i][j] == 'A') cnt1++;
            if (S[i][j] == 'B') cnt2++;
            if (S[i][j] == 'C') cnt3++;
        }
        if (cnt1 != 1 || cnt2 != 1 || cnt3 != 1) return false;
    }
    for (int j = 0; j < N; ++j) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0; 
        for (int i = 0; i < N; ++i) {
            if (S[i][j] == 'A') cnt1++;
            if (S[i][j] == 'B') cnt2++;
            if (S[i][j] == 'C') cnt3++;
        }
        if (cnt1 != 1 || cnt2 != 1 || cnt3 != 1) return false;
    }
    return true;
}

bool check2(vector<string> &S) {
    for (int i = 0; i < N; ++i) {
        char c = '.';
        for (int j = 0; j < N; ++j) {
            if (S[i][j] != '.') {
                c = S[i][j];
                break;
            }
            // if (S[i][j] != '.' && S[i][j] != R[i]) {
            //     cout << i << " " << j << " " << S[i][j] << endl;
            //     return false; 
            // }
        }
        if (c != '.' && c != R[i]) {
            // cout << i << " "  << c << endl;
            return false;
        }
    }
    for (int j = 0; j < N; ++j) {
        char c = '.';
        for (int i = 0; i < N; ++i) {
            if (S[i][j] != '.') {
                c = S[i][j];
                break;
            }
        }
        if (c != '.' && c != C[j]) {
            // cout << j << " "  << c << endl;
            return false;
        }
    }
    return true;
}

vector<string> ans;

bool check3(string s, char c) {
    for (int i = 0; i < s.size(); ++i) if (s[i] == c) return false;
    return true;
}

void dfs(int n, vector<string> &S) {
    if (ok) return;
    if (n == N * N) {
        if (check1(S)) {
            ok = true;
            ans = S;
        }
        return;
    }
    int i = n / N, j = n % N;
    string x = S[i];
    string y;
    for (int k = 0; k < N; ++k) y.push_back(S[k][j]);
    S[i][j] = 'A';
    if (!ok && check2(S) && check3(x, 'A') && check3(y, 'A')) dfs(n + 1, S);
    S[i][j] = 'B';
    if (!ok &&check2(S) && check3(x, 'B') && check3(y, 'B')) dfs(n + 1, S);
    S[i][j] = 'C';
    if (!ok &&check2(S) && check3(x, 'C') && check3(y, 'C')) dfs(n + 1, S);
    S[i][j] = '.';
    if (!ok &&check2(S)) dfs(n + 1, S);
    return;
}

signed main() {
    cin >> N;
    cin >> R >> C;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) S[i].push_back('.');
    dfs(0, S);
    if (ok) {
        cout << "Yes" << endl;
        for (auto x : ans) cout << x << endl;
    } else {
        cout << "No" << endl;
    }
}                           