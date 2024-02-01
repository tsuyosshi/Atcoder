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
string T;

signed main() {
    cin >> N;
    cin >> T;
    vector<int> ans;

    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;

        if (S == T) {
            ans.push_back(i);
            continue;;
        }

        if (S.size() == T.size() + 1) {
            bool same = true;
            int A = -1;
            for (int i = 0; i < S.size() - 1; ++i) if (S[i] != T[i]) {
                A = i;
                break;
            }
            if (A != -1) {
                int t = 0;
                for (int i = 0; i < S.size(); ++i) {
                    if (i == A) continue;
                    if (S[i] != T[t]) {
                        same = false;
                        break;
                    }
                    t++;
                }
            }
            if (same) ans.push_back(i);
        }

        if (S.size() == T.size() - 1) {
            bool same = true;
            int A = -1;
            for (int i = 0; i < S.size(); ++i) if (S[i] != T[i]) {
                A = i;
                break;
            }
            if (A != -1) {
                int s = 0;
                for (int i = 0; i < T.size(); ++i) {
                    if (i == A) continue;
                    if (S[s] != T[i]) {
                        same = false;
                        break;
                    }
                    s++;
                }
            }
            if (same) ans.push_back(i);
        }

        if (S.size() == T.size()) {
            bool same = true;
            int A = -1;
            for (int i = 0; i < S.size(); ++i) if (S[i] != T[i]) {
                A = i;
                break;
            }
            if (A != -1) {
                for (int i = 0; i < T.size(); ++i) {
                    if (i == A) continue;
                    if (S[i] != T[i]) {
                        same = false;
                        break;
                    }
                }
            }
            if (same) ans.push_back(i);
        }

    }
    cout << ans.size() << endl;

    for (auto i: ans) cout << i + 1 << " ";
    cout << endl;
}                           