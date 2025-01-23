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
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    if(K==0){
        cout << "YES\n";
        for(int i=2; i<=N; i++){
            cout << 1 << " " << i << "\n";
        }
    }
    else if(N<=3) cout << "NO\n";
    else if(K<N-3) cout << "NO\n";
    else if(((N-2)/2)*(N-2-(N-2)/2)<K) cout << "NO\n";
    else{
        cout << "YES\n";
        int a=-1, b=-1, x=-1, y=-1, flag=0;
        for(int i=1; i<=(N-2)/2; i++){
            int j=N-2-i;
            if(i*j<K) continue;
            //cout << "i : " << i << " j : " << j << "\n";
            int xy=i*j-K;
            if(xy==0){
                a=i;
                b=j;
                x=0;
                y=0;
                break;
            }
            for(x=1; x*x<=xy; x++){
                if(x>=i) break;
                if(xy%x||xy/x>=j) continue;
                flag=1;
                y=xy/x;
                break;
            }
            if(flag==1){
                a=i-x;
                b=j-y;
                break;
            }
        }
        assert(a>0);
        //cout << "a : " << a << " b : " << b << " x : " << x << " y : " << y << "\n";
        cout << 1 << " " << 2 << "\n";
        for(int i=0; i<a; i++){
            cout << 1 << " " << 3+i << "\n";
        }
        for(int i=a; i<a+y; i++){
            cout << 3 << " " << 3+i << "\n";
        }
        for(int i=a+y; i<a+y+b; i++){
            cout << 2 << " " << 3+i << "\n";
        }
        for(int i=a+y+b; i<a+y+b+x; i++){
            cout << 3+a+y << " " << 3+i << "\n";
        }
    }

    return 0;
}
