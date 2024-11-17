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
const int MAXN = (1<<18)+5;

/*
*/

int DP[105][100005];
int previous[105][100005];
vector<int> prefix;
vector<int> V;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, A, B;
    cin >> N >> A >> B;

    int first;
    cin >> first;

    for(int i=0; i<N-1; i++){
        int a;
        cin >> a;
        if(prefix.size()==0) prefix.push_back(a);
        else prefix.push_back(prefix.back()+a);
        V.push_back(a);
    }

    DP[0][0]=1;

    for(int i=0; i<N-1; i++){
        for(int j=0; j<=A; j++){
            if(!DP[i][j]) continue;
            int curA=j;
            int curB=0;
            if(i>0) curB=prefix[i-1]-curA;
            if(curA+V[i]<=A){
                DP[i+1][curA+V[i]]=1;
                previous[i+1][curA+V[i]]=j;
            } 
            if(curB+V[i]<=B){
                DP[i+1][curA]=1;
                previous[i+1][curA]=j;
            }
        }
    }

    int flag0=0;
    int flag1=0;
    int curstatus=-1;
    for(int i=0; i<=A; i++){
        if(!DP[N-1][i]) continue;
        int a=A-i;
        int b;
        if(N==1) b=B;
        else b=B-(prefix[N-2]-i);
        if(a>=first){
            flag0=1;
            curstatus=i;
            break;
        }
        if(b>=first){
            flag1=1;
            curstatus=i;
        }
    }

    if(flag0) cout << 1 << "\n";
    else if(flag1) cout << 2 << "\n";
    else cout << -1;

    if(flag0||flag1){
        vector<int> upboard;
        vector<int> downboard;
        int curi=N-1;
        while(curi>0){
            if(curstatus==previous[curi][curstatus]){
                downboard.push_back(curi+1);
            }
            else{
                upboard.push_back(curi+1);
                curstatus=previous[curi][curstatus];
            }
            curi--;
        }
        if(flag0) upboard.push_back(1);
        else downboard.push_back(1);
        reverse(all(upboard));
        reverse(all(downboard));
        cout << upboard.size() << " ";
        for(auto i : upboard) cout << i << " ";
        cout << "\n";
        cout << downboard.size() << " ";
        for(auto i : downboard) cout << i << " ";
        cout << "\n";
    }

    return 0;
}