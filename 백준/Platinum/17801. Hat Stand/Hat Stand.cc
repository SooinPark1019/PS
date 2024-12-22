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
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
각 모자들의 위치를 a_i라고 하자
이러고 시뮬레이션을 돌려

그러고 제일 많이 나온 것부터 작은 값을 배정한다?
*/
int pos[100005];
int score[100005];
bool compare(int a, int b){
    return score[a]>score[b];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int C, N;
    cin >> C >> N;
    for(int i=1; i<=C; i++){
        pos[i]=i;
    }
    int first;
    cin >> first;
    int cur=first;
    for(int i=0; i<N-1; i++){
        int a;
        cin >> a;
        score[pos[a]]++;
        pos[cur]=pos[a];
        cur=a;
    }
    vector<int> V;
    for(int i=1; i<=C; i++){
        if(i!=first) V.push_back(i);
    }

    sort(all(V), compare);

    int ans=0;
    for(int i=0; i<C-1; i++){
        ans+=(i+1)*score[V[i]];
    }
    cout << ans << "\n";
    for(auto i : V) cout << i << " ";

    return 0;
}
