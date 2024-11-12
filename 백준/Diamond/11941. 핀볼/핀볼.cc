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
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/

vector<int> seg1(300005*4, 1e18);
vector<int> seg2(300005*4, 1e18);

void update(int node, int start, int end, int index, int val, vector<int>& seg){
    if(index<start||end<index) return;
    if(start==end) seg[node]=min(seg[node], val);
    else{
        int mid=(start+end)/2;
        update(node*2, start, mid, index, val, seg);
        update(node*2+1, mid+1, end, index, val, seg);
        seg[node]=min(seg[node*2], seg[node*2+1]);
    }
}

int min_query(int node, int start, int end, int left, int right, vector<int>& seg){
    if(right<start||end<left) return 1e18;
    else if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)/2;
    return min(min_query(node*2, start, mid, left, right, seg), min_query(node*2+1, mid+1, end, left, right, seg));
}

struct st{
    int a, b, c, d;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> X;
    X.push_back(1);
    X.push_back(N);
    vector<st> V;

    for(int i=0; i<M; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        V.push_back({a, b, c, d});
        X.push_back(a);
        X.push_back(b);
        X.push_back(c);
    }

    sort(all(X));
    X.erase(unique(all(X)), X.end());

    map<int, int> dict;

    for(int i=0; i<X.size(); i++){
        dict[X[i]]=i;
    }

    update(1, 0, X.size()-1, 0, 0, seg1);
    update(1, 0, X.size()-1, X.size()-1, 0, seg2);

    int ans=1e18;

    for(auto i : V){
        int a=i.a;
        int b=i.b;
        int c=i.c;
        int d=i.d;
        //cout << dict[a] << " " << dict[b] << " " << dict[c] << "\n";
        int leftcost=min_query(1, 0, X.size()-1, dict[a], dict[c], seg1);
        if(leftcost<1e18){
            update(1, 0, X.size()-1, dict[c], d+leftcost, seg1);
        } 
        int rightcost=min_query(1, 0, X.size()-1, dict[c], dict[b], seg2);
        if(rightcost<1e18){
            update(1, 0, X.size()-1, dict[c], d+rightcost, seg2);
        }
        //cout << leftcost << " " << rightcost << "\n";
        ans=min(ans, leftcost+rightcost+d);
    }

    if(ans>=1e18) cout << -1;
    else cout << ans;

    return 0;
}
