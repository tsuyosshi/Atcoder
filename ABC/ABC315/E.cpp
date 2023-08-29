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
vector<int> C;
vector<vector<int>> E;
set<int> st;

void dfs(int v) {
    st.insert(v);
    for (auto u: E[v]) {
        if (st.find(u) != end(st)) continue;
        st.insert(u);
        dfs(u);
    }
    return;
}

vector<int> topological_sort() {  
    vector<int> ans;
    vector<int> ind(N);            
    for (int i = 0; i < N; i++) {  
        for (auto v: E[i]) {
            ind[v]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < N; i++) {  
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) { 
        int v = que.front();
        ans.push_back(v);
        que.pop();
        for (auto u : E[v]) {
            ind[u]--;
            if (ind[u] == 0) {
                que.push(u);
            }
        }
    }
    return ans;
}

signed main() {
    cin >> N;
    C = vector<int>(N);
    E = vector<vector<int>>(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        for (int j = 0; j < C[i]; ++j) {
            int p;
            cin >> p;
            p--;
            E[i].push_back(p);
        }
    }
    dfs(0);
    auto res = topological_sort();
    reverse(res.begin(), res.end());
    for (auto v: res) {
        if (st.find(v) != st.end() && v != 0) {
            cout << v + 1 << " ";
        }
    }
    cout << endl;
}   