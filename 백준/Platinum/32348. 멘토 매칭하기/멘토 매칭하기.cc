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
const ll mod = 1e9+7;
const int MAXN = 1e5+5;

ll fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> A;
    vector<int> B;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0; i<M; i++){
        int a;
        cin >> a;
        B.push_back(a);
    }
    sort(all(A));
    sort(B.rbegin(), B.rend());
    
    int maxmin=1e18;
    for(int i=0; i<N; i++){
        if(i<M) maxmin=min(maxmin, A[i]+B[i]);
        else maxmin=min(maxmin, A[i]);
    }
    int cur=1;
    ll ans=1;
    for(int i=0; i<N; i++){
        if(A[i]>=maxmin){
            int leftmentor=M-i;
            int leftstudent=N-i;
            ll temp=1;
            ll res=1;
            int k=0;
            int fac=1;
            while(leftmentor>0&&leftstudent>0){
                temp*=leftmentor*leftstudent%mod;
                temp%=mod;
                k++;
                temp*=fastmul(k, mod-2);
                temp%=mod;
                leftmentor--;
                leftstudent--;
                res+=temp;
                res%=mod;
            }
            ans*=res;
            ans%=mod;
            break;
        }
        while(cur<M&&B[cur]+A[i]>=maxmin){
            cur++;
        }
        ans*=(cur-i);
        ans%=mod;
    }
    cout << ans;

    return 0;
}