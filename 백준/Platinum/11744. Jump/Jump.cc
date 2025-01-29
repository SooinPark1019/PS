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
1이 쓰여 있는 칸은 홀수번
0이 쓰여 있는 칸은 짝수번 뒤집어야 함

어떤 칸을 뒤집으면
i+j가 같은 칸 또는 i-j가 같은 칸을 모두 뒤집게 됨

i+j=i+j
i-j=N+M+max(N+M)+i-j
*/

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> dist(0, 1);

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string S;

    int query=0;

    while(1){
        S="";
        for(int i=0; i<N; i++){
            S+=dist(mt)+'0';
        }
        cout << S << endl;
        query++;
        assert(query<=500+N);
        int a;
        cin >> a;
        if(a==N) return 0;
        if(a==N/2) break;
    }

    vector<int> A;
    vector<int> B;

    A.push_back(0);

    for(int i=1; i<N; i++){
        for(int j=0; j<S.length(); j++){
            if(i==j||j==0){
                if(S[j]=='0') cout << '1';
                else cout << '0';
            }
            else cout << S[j];
        }
        cout << endl;
        query++;
        assert(query<=500+N);
        int a;
        cin >> a;
        if(a==N) return 0;
        if(a==0) A.push_back(i);
        else B.push_back(i);
    }

    string T=S;

    for(auto i : A){
        if(T[i]=='0') T[i]='1';
        else T[i]='0';
    }

    cout << T << endl;
    query++;
    assert(query<=500+N);

    int a;
    cin >> a;
    if(a==N) return 0;

    T=S;

    for(auto i : B){
        if(T[i]=='0') T[i]='1';
        else T[i]='0';
    }

    cout << T << endl;
    query++;
    assert(query<=500+N);

    cin >> a;
    if(a==N) return 0;

    return 0;
}
