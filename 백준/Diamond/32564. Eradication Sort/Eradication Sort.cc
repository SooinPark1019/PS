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

struct line{
    ll a, b;
    long double s;
};

long double cross(line A, line B){
    return (double)(B.b-A.b)/(A.a-B.a);
}

vector<vector<line>> seg(4*1000005);
int curpos[4000005];

void update(int node, int start, int end, int index, int a, int b){
    if(index<start||index>end) return;
    line temp={a, b, 0};
    while(seg[node].size()!=0&&cross(temp, seg[node][seg[node].size()-1])<=seg[node][seg[node].size()-1].s){
        if(curpos[node]==seg[node].size()){
            curpos[node]--;
        }
        seg[node].pop_back();
    }
    if(seg[node].size()!=0){
        //cout << temp.a << " " << temp.b << " " << seg[node][seg[node].size()-1].a << " " << seg[node][seg[node].size()-1].b << "\n";
        temp.s=cross(temp, seg[node][seg[node].size()-1]);
    } 
    //cout << temp.s << "\n";
    seg[node].push_back(temp);
    if(start!=end){
        int mid=(start+end)>>1;
        update(node*2, start, mid, index, a, b);
        update(node*2+1, mid+1, end, index, a, b);
    }
}

int query(int node, int start, int end, int left, int right, int x){
    //cout << "start : " << start << " " << " end : " << end << " left : " << left << " right : " << right << "\n"; 
    if(left>end||right<start) return 0;
    if(left<=start&&end<=right){
        if(seg[node].size()==0) return 0;
        while(curpos[node]+1<seg[node].size()&&seg[node][curpos[node]+1].s<x){
            //cout << "x : " << x << " " << seg[node][curpos[node]+1].s << " " << seg[node][curpos[node]+1].a << " " << seg[node][curpos[node]+1].a << "\n";
            curpos[node]++;
        }
        //if(curpos[node]+1<seg[node].size())cout << "x : " << x << " " << seg[node][curpos[node]+1].s << "\n";
        //cout << seg[node].size() << " " << curpos[node] << " " << seg[node][curpos[node]].a << " " << seg[node][curpos[node]].b << "\n";
        return seg[node][curpos[node]].a*x+seg[node][curpos[node]].b;
    }
    int mid=(start+end)>>1;
    return min(query(node*2, start, mid, left, right, x), query(node*2+1, mid+1, end, left, right, x));
}
int DP[1000005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int ans=1e18;

    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        DP[i]=query(1, 0, 1000000, 0, a, i-1)+(i-1)*(i-1);
        ans=min(ans, DP[i]+(N-i)*(N-i));
        //cout << "i : " << DP[i] << "\n";
        update(1, 0, 1000000, a, -2*i, DP[i]+i*i);
        //cout << -2*i << " " << DP[i]+i*i << "\n";
    }

    cout << ans;

    return 0;
}
