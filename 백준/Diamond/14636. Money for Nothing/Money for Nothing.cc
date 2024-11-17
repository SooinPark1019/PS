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
const int D = 20;

/*
길이 K짜리 순열의 inversion count의 기댓값
KC2/2일 거 같은데

그러면 랜덤으로 바꾸는 순열 바깥쪽에서의 inversion count랑 내부는 저걸 더해서 이걸 평균내면 될 것 같다

각 원소에 대해 inversion을 구하고
현재 random으로 바꿀 대상 수열을 set으로 관리한다
어떤 수가 나가게 되면 set에 있는 해당 수보다 작은 애들의 개수 만큼 inversion에 더해주고
들어오게 되면 해당 수보다 큰애들의 개수 만큼 inversion에서 빼준다
이건 펜윅으로 해준다
*/

vector<pii> P;
vector<pii> C;

int ans=0;

void f(int s, int e, int l, int r){
    //cout << s << " " << e << " " << l << " " << r << endl;
    if(s>e) return;
    int mid=(s+e)>>1;
    int opt=-1;
    int temp=0;
    for(int i=l; i<=r; i++){
        //cout << C[i].first << " " << P[mid].first << "\n";
        //cout << P[mid].second << " " << C[i].second << "\n";
        if(C[i].first<=P[mid].first||P[mid].second>=C[i].second) continue;
        if(temp<(C[i].first-P[mid].first)*(C[i].second-P[mid].second)){
            temp=(C[i].first-P[mid].first)*(C[i].second-P[mid].second);
            opt=i;
        }
    }
    ans=max(ans, temp);
    //assert(opt!=-1);
    f(s, mid-1, l, opt);
    f(mid+1, e, opt, r);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pii> A;
    vector<pii> B;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        A.push_back({a, b});
    }
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        B.push_back({a, b});
    }

    sort(all(A));
    sort(all(B));

    for(int i=M-1; i>=0; i--){
        //cout << B[i].first << " " << B[i].second << "\n";
        if(C.size()==0||C.back().second<B[i].second){
            C.push_back(B[i]);
        }
    }

    reverse(all(C));

    //for(auto i : C) cout << i.first << " " << i.second << endl;

    int curpointer=0;

    for(int i=0; i<A.size(); i++){
        while(curpointer<C.size()&&A[i].first>=C[curpointer].first) curpointer++;
        if(curpointer==C.size()) break;
        if(C[curpointer].second<A[i].second) continue;
        if(P.size()==0||P.back().second>A[i].second){
            P.push_back(A[i]);
        }
    }

    //for(auto i : P) cout << i.first << " " << i.second << endl;
    //for(auto i : C) cout << i.first << " " << i.second << endl;
    //cout << P.size() << endl;
    f(0, (int)P.size()-1, 0, (int)C.size()-1);
    cout << ans;
    return 0;
}
