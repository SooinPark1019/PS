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

set<int> S1, S2;
int cntA[100005];
int cntB[100005];
int DPA[1000005];
int DPB[1000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;
    if(A==B){
        for(int i=0; i<=100000; i++){
            S1.insert(i);
            S2.insert(i);
        }
        for(int i=0; i<=1000000; i++){
            if(i<=A){
                DPA[i]=i;
            }
            else{
                cntA[DPB[i-A-1]]--;
                if(cntA[DPB[i-A-1]]==0) S1.insert(DPB[i-A-1]);
                DPA[i]=*S1.begin();
            }   
            if(i<=B){
                DPB[i]=i;
            }
            else{
                cntB[DPA[i-B-1]]--;
                if(cntB[DPA[i-B-1]]==0) S2.insert(DPA[i-B-1]);
                DPB[i]=*S2.begin();
            }
            cntA[DPB[i]]++;
            if(cntA[DPB[i]]==1) S1.erase(DPB[i]);
            cntB[DPA[i]]++;
            if(cntB[DPA[i]]==1) S2.erase(DPA[i]);
        }
    
        int ans=0;
    
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            //cout << DPA[a] << " ";
            ans^=DPA[a];
        }
        //cout << "\n";
        if(ans==0) cout << "Varys";
        else cout << "Petyr";
    }
    else{
        vector<int> V;
        int temp=0;
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            if(a>min(A, B)) V.push_back(a);
            else{
                temp^=a;
            }
        }
        if(V.size()>1){
            if(A>B) cout << "Petyr";
            else cout << "Varys";
        }
        else if(V.size()==1){
            if(V[0]-A<=temp&&V[0]!=temp) cout << "Petyr";
            else if(A>B) cout << "Petyr";
            else cout << "Varys";
        }
        else{
            if(temp!=0) cout << "Petyr";
            else cout << "Varys";
        }
    }
    return 0;
}
