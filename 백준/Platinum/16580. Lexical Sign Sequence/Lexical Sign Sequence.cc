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
const int MAX = 1e5+5;

struct st{
    int l, r, HP;
};

bool compare(st A, st B){
    return A.l<B.l;
}

int N, K;
int prefill[MAX];
int prefix0[MAX];
int prefix[MAX];
vector<st> V;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> prefill[i];
        prefix[i]=prefix[i-1]+prefill[i];
        prefix0[i]=prefix0[i-1]+(prefill[i]==0);
    }
    for(int i=0; i<K; i++){
        int l, r, c;
        cin >> l >> r >> c;
        int sumval=prefix[r]-prefix[l-1];
        int zerocnt=prefix0[r]-prefix0[l-1];
        //cout << sumval << " " << zerocnt << "\n";
        if(sumval+zerocnt<c){
            cout << "Impossible";
            return 0;
        }
        int HP=(sumval+zerocnt-c)/2;
        //cout << HP << "\n";
        V.push_back({l, r, HP});
    }

    sort(all(V), compare);

    int cnt=0;
    int pointer=0;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    for(int i=1; i<=N; i++){
        while(!PQ.empty()&&PQ.top().second<i){
            PQ.pop();
        }
        while(pointer<K&&V[pointer].l==i){
            PQ.push({V[pointer].HP+cnt, V[pointer].r});
            pointer++;
        }
        if(prefill[i]==0){
            if(PQ.empty()||PQ.top().first>cnt){
                cnt++;
                prefill[i]=-1;
            }
            else prefill[i]=1;
        }
        cout << prefill[i] << " ";
    }
    
    return 0;
}