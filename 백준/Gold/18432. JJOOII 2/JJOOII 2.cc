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
#define zip(v) sort(all(v)); v.erase(unique(all(v)), v.end());
#define int long long
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
Z로 생각을 해보자
먼저 첫번째 두 배열을 그대로 붙인 상태로 시작을 해서
Z값을 계산
접두사=접미사 되는 곳을 찾아가지고 비용계산
남은 것을 다음 문자열로 이월
*/
int Knextpos[3][200005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    memset(Knextpos, -1, sizeof(Knextpos));

    char JOI[3]={'J', 'O', 'I'};

    for(int i=0; i<3; i++){
        int cur_cnt=0;
        queue<pii> Q;
        for(int j=0; j<N; j++){
            Q.push({j, cur_cnt});
            if(S[j]==JOI[i]) cur_cnt++;
            while(!Q.empty()&&Q.front().second+K<=cur_cnt){
                Knextpos[i][Q.front().first]=j;
                Q.pop();
            }
        }
    }

    int ans=1e18;

    for(int i=0; i<N; i++){
        int nxt=i;
        for(int j=0; j<3; j++){
            nxt=Knextpos[j][nxt];
            if(nxt==-1) break;
        }
        //cout << "i : " << i << " nxt : " << nxt << "\n";
        if(nxt==-1) continue;
        ans=min(ans, nxt-i+1-3*K);
    }
    if(ans==1e18) cout << -1;
    else  cout << ans;
    
    return 0;
}
