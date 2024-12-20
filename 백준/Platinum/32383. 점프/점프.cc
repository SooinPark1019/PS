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
const int MAXN = 5e5+5;
const int D = 20;

int child[500005][2];

int ans=0;
vector<int> A;
int N;

int sol(int cur_node){
    int ret=0;
    if(cur_node==-1) return ret;
    ret++;
    int left=sol(child[cur_node][0]);
    int right=sol(child[cur_node][1]);
    
    if(child[cur_node][0]!=-1){
        ans+=(A[cur_node]-A[child[cur_node][0]])*(A[cur_node]-A[child[cur_node][0]])%mod*(N-left)%mod*left%mod;
        //cout << ans << "\n";
        ans%=mod;
    }
    if(child[cur_node][1]!=-1){
        ans+=(A[cur_node]-A[child[cur_node][1]])*(A[cur_node]-A[child[cur_node][1]])%mod*(N-right)%mod*right%mod;
        //cout << ans << "\n";
        ans%=mod;
    }

    ret+=right+left;
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
        child[i][0]=-1;
        child[i][1]=-1;
    }

    stack<int> S;
    int root;

    for(int i=0; i<N; i++){
        while(!S.empty()&&A[S.top()]<A[i]){
            child[i][0]=S.top();
            S.pop();
        }
        if(S.empty()) root=i;
        else{
            child[S.top()][1]=i;
        }
        S.push(i);
    }
    sol(root);
    cout << ans;

    return 0;
}