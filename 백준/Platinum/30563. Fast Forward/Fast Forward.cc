#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
const ll MAX = 2e6+5;
const int D=25;

int sp[D][MAX];//sp[i][j]=j번 간격에서 출발했을 때 2^i번째 광고가 재생될 간격

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, C;
    cin >> N >> C;
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    for(int i=0; i<N; i++){
        V.push_back(V[i]);
    }
    memset(sp, -1, sizeof(sp));
    int nxt_pos=0;
    int cur_sum=0;
    for(int i=0; i<2*N; i++){
        while(nxt_pos<2*N&&cur_sum<C){
            cur_sum+=V[nxt_pos];
            nxt_pos++;
        }
        if(nxt_pos==2*N) sp[0][i]=-1;
        else sp[0][i]=nxt_pos;
        cur_sum-=V[i];
    }
    /*(int i=0; i<2*N; i++){
        cout << sp[0][i] << " ";
    }*/
    //cout << "\n";
    for(int i=1; i<D; i++){
        for(int j=0; j<2*N; j++){
            if(sp[i-1][j]==-1) sp[i][j]=-1;
            else sp[i][j]=sp[i-1][sp[i-1][j]];
        }
    }
    for(int i=0; i<N; i++){
        int a=i;
        int ans=0;
        for(int j=D-1; j>=0; j--){
            if(sp[j][a]!=-1&&sp[j][a]<i+N){
                ans+=(1<<j);
                a=sp[j][a];
            }
        }
        cout << ans << " ";
    }
    return 0;
}