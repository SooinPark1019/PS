#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int debug = 1;
const int MAX=1e6+5;

ll sparsetable[25][MAX];
int T, N, L, K;
vector<int> dangertime;
vector<int> safety;
vector<int> V;

void input(){
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        dangertime.push_back(a);
    }

    for(int i=0; i<K; i++){
        int a;
        cin >> a;
        safety.push_back(a);
    }
    for(int i=0; i<K-1; i++){
        V.push_back(safety[i+1]-safety[i]);
    }
}
void fill_sparse(){
    for(int i=0; i<N-1; i++){
        sparsetable[0][i]=dangertime[i+1]-dangertime[i];
    }
    sparsetable[0][N-1]=T-dangertime[N-1]+dangertime[0];

    for(int i=1; i<=20; i++){
        for(int j=0; j<N; j++){
            sparsetable[i][j]=max(sparsetable[i-1][j], sparsetable[i-1][(j+(1ll<<i-1))%N]);
            //cout << i << " " << j << " " << sparsetable[i][j] << "\n";
        }
        //cout << "\n";
    }
}
int max_interval(){
    int ret=0;
    for(int i=0; i<N; i++){
        //cout << sparsetable[0][i] << "\n";
        ret=max(ret, sparsetable[0][i]);
    }
    return ret;
}
int cal(int cur_time, int move){
    //cout << "curtime : " << cur_time << " move : " << move << "\n";
    int temp=cur_time%T;
    int nexttime=(lower_bound(dangertime.begin(), dangertime.end(), temp)-dangertime.begin())%N;
    //cout << "nexttime : " << nexttime << "\n";
    int a=0;
    if(dangertime[nexttime]>=temp) a=dangertime[nexttime]-temp;
    else a=T-temp+dangertime[nexttime];
    if(a>=move){
        return cur_time+move;
    }
    while(sparsetable[0][nexttime]<move){
        for(int i=20; i>=0; i--){
            if(sparsetable[i][nexttime]<move){
                nexttime+=(1ll<<i);
                nexttime%=N;
            }
        }
        /*nexttime++;
        nexttime%=N;*/
    }
    nexttime=dangertime[nexttime];
    //cout << "nexttime : " << nexttime << "\n";
    if(nexttime>=temp) cur_time+=nexttime-temp;
    else cur_time+=T-temp+nexttime;
    cur_time+=move;
    return cur_time;
}

void sol(){
    int maxinterval=max_interval();
    int cur_time=0;
    for(auto i : V){
        if(i>maxinterval){
            cout << "What is that map newbie...";
            return;
        }
        cur_time=cal(cur_time, i);
    }
    cout << cur_time;
    return;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T >> N >> L >> K;
    input();
    fill_sparse();
    sol();
    return 0;
}