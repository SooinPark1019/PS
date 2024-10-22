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

int ans[1005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> V;
    int maxelem=0;
    int sum=0;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
        maxelem=max(maxelem, a);
        sum+=a;
    }
    int sqrtn=sqrt(sum);
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    for(int i=maxelem; i<=min(sum, sqrtn); i++){
        PQ.push({i+1, i});
    }

    int cur_prefix=0;
    vector<int> prefix;
    for(int i=0; i<N; i++){
        cur_prefix+=V[i];
        prefix.push_back(cur_prefix);
        //cout << V[i] << "\n";
        while(!PQ.empty()&&PQ.top().first<=cur_prefix){
            ans[PQ.top().second]++;
            pii A=PQ.top();
            PQ.pop();
            A.first=cur_prefix+A.second-V[i]+1;
            PQ.push(A);
        }
    }
    int Q;
    cin >> Q;
    while(Q--){
        int a;
        cin >> a;
        if(a<maxelem) cout << "Impossible\n";
        else if(a<=sqrtn) cout << ans[a]+1 << "\n";
        else{
            int ans=0;
            int curpos=0;
            while(curpos<N){
                int left=curpos;
                int right=N-1;
                int nextpos=curpos;
                while(left<=right){
                    int mid=(left+right)/2;
                    int b=prefix[mid];
                    if(curpos>0) b-=prefix[curpos-1];
                    if(b<=a){
                        nextpos=max(ans, mid);
                        left=mid+1;
                    }
                    else right=mid-1;
                }
                curpos=nextpos+1;
                ans++;
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}