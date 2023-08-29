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

signed main() {
    cin >> N >> M;
    vector<string> F(N);
    for (int i = 0; i < N; ++i) cin >> F[i];
    queue<PII> que;
    map<PII, bool> visited1;
    map<PI, bool> visited2; 
    que.push(PII(1, PI(1, -1)));
    visited1[PII(1, PI(1, -1))] = true;
    visited2[PI(1, 1)] = true;
    while (que.size() > 0) {
        auto v = que.front();
        que.pop();
        int y = v.first, x = v.second.first, dir = v.second.second;
        if (F[y][x] == '.' && dir != -1) {
            int ny = y + dy[dir], nx = x + dx[dir], ndir = dir;
            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (F[ny][nx] == '#') ny = y, nx = x, ndir = -1;
                PII key = PII(ny, PI(nx, ndir));
                if (visited1.find(key) == end(visited1)) {
                    que.push(key);
                    visited1[key] = true;
                    visited2[PI(ny, nx)] = true;
                }
            }  
        }
        else {
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i], nx = x + dx[i], ndir = i;
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || F[ny][nx] == '#') continue;
                PII key = PII(ny, PI(nx, ndir));
                if (visited1.find(key) == end(visited1)) {
                    que.push(key);
                    visited1[key] = true;
                    visited2[PI(ny, nx)] = true;
                }
            }
        }
    }
    cout << visited2.size() << endl;
}  