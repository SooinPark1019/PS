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
int minX=1e18, maxX=-1e18;
int takingBallDisFromleft[500005];
int takingBallDisFromRight[500005];
int ballcnt[500005];
int ballcntleft[500005];
int ballcntright[500005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        minX=min(minX, a);
        maxX=max(maxX, a);
        ballcnt[a]++;
    }
    int curballs=0;
    takingBallDisFromleft[minX]=ballcnt[minX];
    for(int i=minX+1; i<=maxX; i++){
        curballs+=ballcnt[i-1];
        ballcntleft[i]=curballs;
        takingBallDisFromleft[i]=takingBallDisFromleft[i-1]+curballs+1+ballcnt[i];
    }
    curballs=0;
    takingBallDisFromRight[maxX]=ballcnt[maxX];
    for(int i=maxX-1; i>=minX; i--){
        curballs+=ballcnt[i+1];
        ballcntright[i]=curballs;
        takingBallDisFromRight[i]=takingBallDisFromRight[i+1]+curballs+1+ballcnt[i];
    }
    int Q;
    cin >> Q;
    while(Q--){
        int S, G, T;
        cin >> S >> G >> T;
        
        int dis1=0, dis2=0;

        dis1+=abs(S-minX);
        //cout << dis1 << "\n";
        if(G<minX){
            dis1+=maxX-minX;
            dis1+=takingBallDisFromRight[minX];
            dis1+=(N+1)*(minX-G);
        }
        else if(G<=maxX){
            dis1+=takingBallDisFromleft[G];
            dis1+=(2*ballcntleft[G]+1)*(maxX-G);
            dis1+=takingBallDisFromRight[G];
            dis1-=ballcnt[G];
        }
        else{
            dis1+=takingBallDisFromleft[maxX];
            dis1+=(G-maxX)*(N+1);
        }

        dis2+=abs(S-maxX);
        if(G>maxX){
            dis2+=maxX-minX;
            dis2+=takingBallDisFromleft[maxX];
            dis2+=(N+1)*(G-maxX);
        }
        else if(minX<=G){
            dis2+=takingBallDisFromRight[G];
            dis2+=(2*ballcntright[G]+1)*(G-minX);
            dis2+=takingBallDisFromleft[G];
            dis2-=ballcnt[G];
        }
        else{
            dis2+=takingBallDisFromRight[minX];
            dis2+=(N+1)*(minX-G);
        }
        //cout << dis1 << " " << dis2 << "\n";
        if(min(dis1, dis2)<=T) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
