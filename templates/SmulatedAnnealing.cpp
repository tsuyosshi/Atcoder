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
    int sum_w;
    vector<int> get_items;

    State(int eval, int sum_w, vector<int> get_items) : eval(eval), sum_w(sum_w), get_items(get_items) {
    }

    State changeState() {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<uint32_t> get_rnd(0, N - 1);
        while (true) {
            State new_state = State(eval, sum_w, get_items);
            int item = get_rnd(mt);
            if (new_state.get_items[item] == 0) {
                new_state.eval += v[item];
                new_state.sum_w += w[item];
            }
            else {
                new_state.eval -= v[item];
                new_state.sum_w -= w[item];
            }
            new_state.get_items[item] = 1 - new_state.get_items[item];
            if (new_state.sum_w > W) continue;
            return new_state;
        }
    }
};

State init_state() {
    return State(0, 0, vector<int>(N, 0));
}

double tempareture(double t0, int loop, int cnt, int paramA = 1, int paramB = 4) {
    double progress = (cnt + 0.5) / loop;
    double remain = 1.0 - progress;
    double t = t0 * pow(remain, paramA) * exp(-progress * paramB);
    return t;
}
 
State simulated_annealing(double t0, int MAX_LOOP = 100000, const uint32_t MAX_RAND = mt19937::max()) {
    State state = init_state();
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<uint32_t> get_rnd(0, MAX_RAND - 1);
    for (int loop = 0; loop < MAX_LOOP; ++loop) {
        auto new_state = state.changeState();
        int pre_eval = state.eval;
        int new_eval = new_state.eval;
        double temp = tempareture(t0, MAX_LOOP, loop);
        double p = exp((double) (new_eval - pre_eval) / temp);
        double q = (double) ((double) get_rnd(mt) / (double) MAX_RAND);
        if (min(p, 1.0) > q) {
            state = new_state;
        }
    }
    return state;
}
 

signed main(){
    cin >> N >> W;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        w.push_back(b);
    }
    auto ret = simulated_annealing(200);
    cout << ret.eval << endl;
}