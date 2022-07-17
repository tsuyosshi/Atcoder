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

template <class T>
class SegmentTree {
    int n;
    vector<T> node;
    T def;
    function<T(T, T)> operation;
    function<T(T, T)> update;

    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def; 
        if (a <= l && r <= b) return node[k];
        else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); 
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
            return operation(c1, c2);
        }
    }

public:
    // _n:必要サイズ, def:初期値, operation:クエリ関数,
    // _update:更新関数
    SegTree(size_t _n, T def, function<T(T, T)> operation, function<T(T, T)> update) : def(def), operation(operation), update(update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        node = vector<T>(2 * n - 1, def);
    }

    // 場所i(0-indexed)の値をxで更新
    void change(int i, T x) {
        i += n - 1;
        node[i] = update(node[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            node[i] = operation(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    // [a, b)の区間クエリを実行
    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }

    // 添字でアクセス
    T operator[](int i) {
        return node[i + n - 1];
    }
};

signed main() {
    int N, Q;
    cin >> N >> Q;
    auto operation = [](int a, int b) { return min(a, b); };
    auto update = [](int data, int x) { return x; };
    SegmentTree<int> seg(N, INF, operation, update);
    for ()
}