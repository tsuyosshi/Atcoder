#include<bits/stdc++.h>

#define int  long long

using namespace std;

static const int INF = 1010000000000000017LL;

class SegmentTree{

public:
    int node[5005];
    int n;
    SegmentTree(int n_){
        n = 1;
        while(n < n_) n *= 2;
        for(int i = 0; i < 2 * n - 1; i++) node[i] = -INF;
    }
    void update(int a, int x){
        a += n - 1;
        node[a] = x;
        while(a > 0){
            a = (a - 1) / 2;
            node[a] = max(node[2 * a + 1], node[2 * a + 2]);
        }
    }
    int _query(int a, int b, int k, int l, int r){
        if(b <= l || r <= a) return -INF;
        if(a <= l && r <= b) return node[k];
        int vl = _query(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = _query(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(vl, vr);
    }
    int query(int a, int b){
        return _query(a, b, 0, 0, n);
    }
};

int step;
int N;

signed main(){
}