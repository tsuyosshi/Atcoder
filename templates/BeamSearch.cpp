#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int,int> PI;
typedef pair<int,pair<int,int>> PII;
static const int INF=1010000000000000017LL;
static const double eps=1e-12;
static const double pi=3.14159265358979323846;
static const int dx[4]={1,-1,0,0};
static const int dy[4]={0,0,1,-1};
static const int ddx[8]={1,-1,0,0,1,1,-1,-1};
static const int ddy[8]={0,0,1,-1,1,-1,1,-1};

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int N, W;
vector<int> v, w;

struct State{

    int eval;
    int n;
    int sum_w;
    vector<int> get_items;

    State(int eval, int n, int sum_w, vector<int> get_items) : eval(eval), n(n), sum_w(sum_w), get_items(get_items) {
    }

    vector<State> nextStates(){
        vector<State> next_states;
        // n + 1 をとらない
        State state1 = State(eval, n + 1, sum_w, get_items);
        next_states.push_back(state1);

        // n + 1 をとる
        if (sum_w + w[n + 1] <= W) {
            State state2 = State(eval + v[n + 1], n + 1, sum_w + w[n + 1], get_items);
            state2.get_items.push_back(n + 1);
            next_states.push_back(state2);
        }
        return next_states;
    }
};

bool operator< (const State &state1, const State &state2) {
    return state1.eval < state2.eval;
}

bool operator> (const State &state1, const State &state2) {
    return state1.eval > state2.eval;
}

State initState() {
    return State(0, -1, 0, vector<int>());
}

vector<State> initStates() {
}

State beamsearch() {
    int MAXTURN = N;
    const int BeamWidth = 10000;
    priority_queue<State> nowpq;
    // auto init_states = initStates();
    // for (auto state : init_states) nowpq.push(state);
    auto init_state = initState();
    nowpq.push(init_state);
    for (int t = 0; t < MAXTURN; ++t) {
        priority_queue<State> candidates;
        while (nowpq.size() > 0) {
            State now_state = nowpq.top();
            nowpq.pop();
            auto next_states = now_state.nextStates();
            for (auto next_state : next_states) {
                candidates.push(next_state);
            }
        }
        nowpq = priority_queue<State>();
        while (nowpq.size() < BeamWidth && candidates.size() > 0) {
            nowpq.push(candidates.top());
            candidates.pop();
        }
    }
    State ret = nowpq.top();
    return ret;
}

signed main(){
    cin >> N >> W;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        w.push_back(b);
    }
    auto ret = beamsearch();
    cout << ret.eval << endl;
}