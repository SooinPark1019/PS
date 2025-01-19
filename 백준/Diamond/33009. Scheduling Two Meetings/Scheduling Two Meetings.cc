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
const int mod = 1e9+7;
const int mod2 = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다
*/

pii DP[(1ll<<20)+5];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    for(int i=0; i<=(1ll<<M); i++){
        DP[i]={-1, -1};
    }

    vector<int> V;

    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        int a=0;
        for(auto c : S){
            a<<=1;
            if(c=='Y') a++;
        }
        V.push_back(a);
        int b=__builtin_popcountll(a);
        if(DP[a].first==-1){
            DP[a]={b, i};
        } 
    }

    if(DP[(1ll<<M)-1].first>=0){
        int a=DP[(1ll<<M)-1].second;
        int b=1e18;
        int cur=-1;
        //cout << V.size() << endl;
        for(int i=0; i<N; i++){
            //cout << i << endl;
            if(a==i) continue;
            if(cur<__builtin_popcountll(V[i])||(cur==__builtin_popcountll(V[i])&&b>i)){
                b=i;
                cur=__builtin_popcountll(V[i]);
            }
        }
        int ansa=min(a, b);
        int ansb=max(a, b);
        cout << ansa+1 << " " << ansb+1;
        return 0;
    }

    for(int i=(1ll<<M)-1; i>=0; i--){
        if(DP[i].first==-1) continue;
        //cout << "i : " << i << "\n";
        for(int j=0; j<M; j++){
            if((i&(1ll<<j))==0) continue;
            int temp=i-(1ll<<j);
            //cout << "temp : " << temp << " ";
            if(DP[temp].first<DP[i].first||(DP[temp].first==DP[i].first&&DP[temp].second>DP[i].second)){
                DP[temp]=DP[i];
            }
        }
        //cout << "\n";
    }

    int ans=-1;
    int a=1e18;
    int b=1e18;

    for(int i=0; i<(1ll<<M); i++){
        if(DP[i].first<0) continue;
        //cout << "i : " << i << "\n";
        int other=((1ll<<M)-1-i);
        //cout << "other: " << other << "\n";
        if(DP[other].first<0) continue;
        int tempa=min(DP[i].second, DP[other].second);
        int tempb=max(DP[i].second, DP[other].second);
        int tempans=__builtin_popcountll(i)+DP[other].first-M;
        if(ans<tempans||(ans==tempans&&a>tempa)||(ans==tempans&&a==tempa&&b>tempb)){
            ans=tempans;
            a=tempa;
            b=tempb;
        }
    }

    if(ans<0) cout << "No";
    else{
        cout << a+1 << " " << b+1;
    }
    
    return 0;
}

