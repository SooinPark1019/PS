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
const double EPS = 1e-7;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
sum(V)/sum(W)>=K
sum(V)>=K*sum(W)
sum(V)>=sum(K*W)
sum(V)-sum(K*W)>=0
sum(V-k*W)>=0
*/

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
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        B.push_back(a);
    }

    int ans=0;
    for(int i=N; i>0; i--){
        for(int j=0; j<i; j++){
            //cout << "i : " << i%N << " j : " << j << endl;
            priority_queue<pii> PQ;
            int k=i%N;
            int temp=0;
            //cout << "k : ";
            while(1){
                //cout << k << " ";
                PQ.push({A[k], B[k]});
                if(k==j) break;
                k++;
                k%=N;
            }
            //cout << endl;
            if(PQ.empty()) continue;
            int possible=M-(2*((N-i)%N)+j);
            possible=max(possible, M-(2*j+(N-i)%N));
            if(possible<=0) continue;
            //cout << "possible : " << possible << "\n";
            for(int k=0; k<possible; k++){
                temp+=PQ.top().first;
                pii c=PQ.top();
                PQ.pop();
                c.first=max(0ll, c.first-c.second);
                PQ.push(c);
            }
            //cout << temp << "\n";
            ans=max(ans, temp);
        }
    }
    cout << ans;
    return 0;
}