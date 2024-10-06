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
const int MAXN = 2e5+5;
const int D = 20;

/*
어떤 A에 대해서 뒤에 나오는 B의 개수/2만큼을 앞에다가 붙여버린다

이거만 하면 또 안되는구나
거꾸로 보면서 A를 마주할때마다 현재까지 마주한 B의 개수%2를 출력하고 B의 개수를 절반으로 줄인다
마지막에는 남은 B의 개수를 모두 출력
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        string S;
        cin >> S;

        reverse(all(S));

        int b=0;
        string T="";
        for(auto i : S){
            if(i=='A'){
                if(b%2) T+="B";
                T+="A";
                b/=2;
            }
            else{
                b++;
            }
        }
        for(int i=0; i<b; i++) T+="B";
        reverse(all(T));
        cout << T << "\n";
    }

    return 0;
}