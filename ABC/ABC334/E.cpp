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

const int mod = 998244353;

class UnionFind {
private:
	vector<int> par;
	vector<int> siz;
 
public:
	UnionFind(int sz_) : par(sz_), siz(sz_, 1) {
		for (int i = 0; i < sz_; ++i) par[i] = i;
	}

	void init(int sz_) {
		par.resize(sz_);
		siz.resize(sz_, 1);
		for (int i = 0; i < sz_; ++i) par[i] = i;
	}

	int find(int x) {
		while (par[x] != x) x = par[x] = par[par[x]];
		return x;
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(siz[x] < siz[y]) std::swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
	
	int size(int x) {
		return siz[find(x)];
	}
};

int modPow(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a % mod;
    if (n % 2 == 1) return (a * modPow(a, n - 1)) % mod;
    int t = modPow(a, n / 2);
    return (t * t) % mod;
}

int H, W;
vector<string> S;

signed main() {
    cin >> H >> W;
    S.resize(H);
    UnionFind uf(H * W);
    for (int y = 0; y < H; ++y) cin >> S[y];
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (S[y][x] != '#') continue;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H || S[ny][nx] != '#') continue;
                uf.unite(y * W + x, ny * W + nx);
            }
        }
    }

    int r = 0;
    int num_c = 0;
    int ans = 0;
    set<int> components;
    for (int y = 0; y < H; ++y) for (int x = 0; x < W; ++x) if (S[y][x] == '.') r++;
    for (int y = 0; y < H; ++y) for (int x = 0; x < W; ++x) if (S[y][x] == '#') components.insert(uf.find(y * W + x));
    num_c = components.size();
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (S[y][x] != '.') continue;
            set<int> united;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H || S[ny][nx] != '#') continue;
                united.insert(uf.find(ny * W + nx));
            }
            ans += (num_c - united.size() + 1) * modPow(r, mod - 2);
            ans %= mod;
        }
    }
    cout << ans << endl;
}                       