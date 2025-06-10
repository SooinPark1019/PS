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
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
/*#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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
*/
int N;
int Fenwick[1505][1505];
int arr[1505][1505];
int DP[1505][1505];

void update(int index, int value, int FenwickIndex){
    //cout << "index : " << index << " value : " << value << "\n";
    while(index<=N){
        Fenwick[FenwickIndex][index]+=value;
        index+=index&(-index);
    }
    return;
}

int sum_query(int index, int FenwickIndex){
    int ret=0;
    while(index>0){
        ret+=Fenwick[FenwickIndex][index];
        index-=index&(-index);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }

    int ans=0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            DP[i][j]=arr[i][j]+max(DP[i-1][j], DP[i][j-1]);
            ans+=DP[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            update(j, DP[i][j]-DP[i][j-1], i);
        }
    }

    cout << ans << "\n";

    for(int i=1; i<=N; i++){
        char c;
        int x, y;
        cin >> c >> x >> y;
        int weight;
        if(c=='U') weight=1;
        else weight=-1;
        int pointer1=y, pointer2=y;
        int initx=x;
        while(x<=N){
            while(pointer2<N){
                int a=sum_query(pointer2+1, x-1);
                int b=sum_query(pointer2, x);
                //cout << "a : " << a << " b : " << b << "\n";
                if(c=='U'){
                    if(b<a) break;
                }
                else{
                    if(b<=a) break;
                }
                pointer2++;
            }
            while(pointer1<=pointer2&&x>initx&&pointer1>1){
                int a=sum_query(pointer1, x-1);
                int b=sum_query(pointer1-1, x);
                //cout << "a : " << a << " b : " << b << "\n";
                if(c=='U'){
                    if(a>b) break;
                }
                if(c=='D'){
                    if(a>=b) break;
                }
                pointer1++;
            }
            if(pointer1>pointer2) break;
            //cout << "x : " << x << " pointer1 : " << pointer1 << " pointer2 : " << pointer2 << "\n";
            ans+=weight*(pointer2-pointer1+1);
            update(pointer1, weight, x);
            if(pointer2+1<=N) update(pointer2+1, -weight, x);
            x++;
        }
        cout << ans << "\n";
    }

    return 0;
}