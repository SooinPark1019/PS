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
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
풍선이 부족한 경우는 없으므로
적절한 풍선을 나눠주는 것은 결국 A와 B사이 거리의 차만큼 이득을 보는 행위일 것이다
따라서 차가 큰 것 순으로 정렬

어디서 틀렸을까?

*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, D;
    cin >> N >> D;
    int a=__gcd(abs(N), D);
    N/=a;
    D/=a;
    if(__builtin_popcountll(abs(D))!=1) cout << -1 << "\n";
    else{
        string S;
        a=abs(N/D);
        //cout << "a : " << a << "\n";
        for(int i=0; i<=60; i++){
            if((a&(1ll<<i))!=0){
                if(N<0) S+="L";
                else S+="R";
            }
            S+="U";
        }
        int b=abs(abs(N)%D);
        //cout << "N : " << N << "\n";
        for(int i=0; i<=60; i++) S+="D";
        a=1;
        while(a<D){
            S+="D";
            a<<=1;
        }
        for(int i=0; i<=60; i++){
            if((b&(1ll<<i))!=0){
                if(N<0) S+="L";
                else S+="R";
            }
            S+="U";
        }
        assert(S.length()<=1000);
        cout << S.length() << "\n";
        cout << S;
    }

    return 0;
}
