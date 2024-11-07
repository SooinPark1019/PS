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

/*
*/

vector<int> V;
vector<pii> A;
vector<pii> B;

int dnc(int s, int e, int l, int r){
    if(s>e) return 0;
    int mid=(s+e)/2;
    int opt=-1;
    int ans=0;
    for(int i=l; i<=r; i++){
        if(B[i].second<=mid) continue;
        if(ans==0||ans<(A[mid].first-B[i].first)*(B[i].second-A[mid].second)){
            ans=(A[mid].first-B[i].first)*(B[i].second-A[mid].second);
            opt=i;
        }
    }
    ans=max(ans, dnc(s, mid-1, l, opt));
    ans=max(ans, dnc(mid+1, e, opt, r));
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    for(int i=0; i<N; i++){
        if(A.empty()||A.back().first<V[i]){
            A.push_back({V[i], i});
        }
    }
    reverse(all(V));
    for(int i=0; i<N; i++){
        if(B.empty()||B.back().first>-V[i]){
            B.push_back({-V[i], N-1-i});
        }
    }
    reverse(all(B));
    cout << dnc(0, A.size()-1, 0, B.size()-1);
    return 0;
}