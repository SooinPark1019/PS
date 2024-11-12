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

vector<int> seg1(500005*4, 1e18);

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

struct student{
    int a, b, c;
};
bool compare(student A, student B){
    return A.a<B.a;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<student> V(N+1);
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        V[a].a=i;
    }
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        V[a].b=i;
    }
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        V[a].c=i;
    }

    sort(all(V), compare);

    /*for(auto i : V){
        cout << i.a << " " << i.b << " " << i.c << endl;
    }*/

    int ans=0;

    for(int i=1; i<=N; i++){
        int a=V[i].a;
        int b=V[i].b;
        int c=V[i].c;
        //cout << a << " " << b << " " << c << endl;
        if(c<min_query(1, 0, N, 0, b, seg1)){
            //cout << "!\n";
            ans++;
        }
        update(1, 0, N, b, c, seg1);
    }
    cout << ans;

    return 0;
}
