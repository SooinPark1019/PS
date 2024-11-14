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
const int MAXN = (1<<18)+5;
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    int total=0;
    int cnt[5]={};
    for(int i=0; i<N; i++){
        string a;
        cin >> a;
        int b=0;
        for(auto i : a){
            if(i=='.') continue;
            b*=10;
            b+=i-'0';
        }
        //cout << b << "\n";
        total+=b;
        cnt[b%5]++;
    }
    int b=0;
    //cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << " " << cnt[4] << "\n";
    b+=cnt[1];
    b+=cnt[2]*2;
    b+=2*min(cnt[3], cnt[4]);
    if(cnt[3]>cnt[4]){
        b+=(cnt[3]-cnt[4])/2;
    }
    else{
        b+=((cnt[4]-cnt[3])/3)*2;
    }
    total-=b;
    cout << fixed;
    cout.precision(2);
    cout << (double)total/100 << "\n";
    
    return 0;
}