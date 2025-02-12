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

int DPfromleft[3005][3005][2];
int DPfromright[3005][3005][2];
int N, L;
vector<int> V;
vector<pii> X;
int prefix[3005];
int suffix[3005];

void fill_DP(int DP[3005][3005][2]){
    for(int i=X.size()-2; i>0; i--){
        for(int j=1; j+i<X.size(); j++){
            //cout << "l : " << j << " r : " << i+j << " DP : " << DP[j][i+j][0] << " " << DP[j][i+j][1] << "\n";
            if(DP[j][i+j][0]!=1e18){
                //cout << (prefix[j]+suffix[i+j+1])*abs(X[j].first-X[j+1].first) << "\n";
                DP[j+1][i+j][0]=min(DP[j+1][i+j][0], DP[j][i+j][0]+(prefix[j]+suffix[i+j+1]+1)*abs(X[j].first-X[j+1].first));
                DP[j+1][i+j][1]=min(DP[j+1][i+j][1], DP[j][i+j][0]+(prefix[j]+suffix[i+j+1]+1)*abs(X[j].first-X[i+j].first));
            }
            if(DP[j][i+j][1]!=1e18){
                //cout << (prefix[j-1]+suffix[i+j])*abs(X[j].first-X[j+1].first) << "\n";
                DP[j][i+j-1][0]=min(DP[j][i+j-1][0], DP[j][i+j][1]+(prefix[j-1]+suffix[i+j]+1)*abs(X[i+j].first-X[j].first));
                DP[j][i+j-1][1]=min(DP[j][i+j-1][1], DP[j][i+j][1]+(prefix[j-1]+suffix[i+j]+1)*abs(X[i+j].first-X[i+j-1].first));
            }
        }
    }
}

int bestFromLeft[500005];
int bestFromRight[500005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> N >> L;

    
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    sort(all(V));
    X.push_back({-1, 0});

    for(int i=0; i<N; i++){
        if(X.back().first!=V[i]) X.push_back({V[i], 1});
        else X.back().second++;
    }
    if(X.size()<3000){
        //for(auto i : V) cout << i << " ";
        //cout << "\n";

        for(int i=1; i<X.size(); i++){
            prefix[i]+=X[i].second+prefix[i-1];
        }
        for(int i=X.size()-1; i>0; i--){
            suffix[i]+=X[i].second+suffix[i+1];
        }

        for(int i=0; i<=X.size(); i++){
            for(int j=0; j<=X.size(); j++){
                for(int k=0; k<2; k++){
                    DPfromleft[i][j][k]=1e18;
                    DPfromright[i][j][k]=1e18;
                }
            }
        }

        DPfromleft[1][X.size()-1][0]=0;
        DPfromright[1][X.size()-1][1]=0;

        fill_DP(DPfromleft);
        fill_DP(DPfromright);

        int curpointer=0;
        for(int i=0; i<=L; i++){
            while(curpointer<X.size()-1&&(N+1)*abs(X[curpointer].first-i)+DPfromleft[curpointer][curpointer][0]>=(N+1)*abs(X[curpointer+1].first-i)+DPfromleft[curpointer+1][curpointer+1][0]){
                curpointer++;
            }
            //cout << curpointer << endl;
            bestFromLeft[i]=abs(X[curpointer].first-i)*(N+1)+DPfromleft[curpointer][curpointer][0];
        }
        curpointer=X.size()-1;
        for(int i=L; i>=0; i--){
            while(curpointer>1&&(N+1)*abs(X[curpointer].first-i)+DPfromright[curpointer][curpointer][0]>=(N+1)*abs(X[curpointer-1].first-i)+DPfromright[curpointer-1][curpointer-1][0]){
                curpointer--;
            }
            bestFromRight[i]=(N+1)*abs(X[curpointer].first-i)+DPfromright[curpointer][curpointer][0];
        }

        int Q;
        cin >> Q;

        while(Q--){
            int S, G, T;
            cin >> S >> G >> T;
            int ans=1e18;
            ans=min(ans, abs(S-V[0])+bestFromLeft[G]);
            ans=min(ans, abs(S-V[N-1])+bestFromRight[G]);
            ans+=N;
            //cout << ans << "\n";
            if(ans<=T) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    else{
        int Q;
        cin >> Q;
        while(Q--){
            int S, G, T;
            cin >> S >> G >> T;
            cout << "No\n";
        }
    }

    return 0;
}
