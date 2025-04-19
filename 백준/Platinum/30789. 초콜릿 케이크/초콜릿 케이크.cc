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

int arr[200005];
int ans[200005];
int arr2[200005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> V;
    for(int i=0; i<2*N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    int piece=0;
    int total=0;
    for(int i=0; i<N; i++) piece+=V[i];
    for(int i=0; i<2*N; i++) total+=V[i];

    int pt1=0, pt2=N-1, pt3=N, pt4=2*N-1;

    for(int i=0; i<N; i++){
        int a=2*piece-total;
        //cout << "i : " << i << "---------\n";
        //cout << "a : " << a << "\n";
        if(a>0){
            int b=a/(2*M);
            int c=a%(2*M);
            //cout << "c : " << c << "\n";
            if(c>M) b++;
            ans[pt3]+=b;
            ans[pt4]+=b;
            a-=2*M*b;
        }
        else{
            int b=abs(a)/(2*M);
            int c=abs(a)%(2*M);
            if(c>M) b++;
            ans[pt1]+=b;
            ans[pt2]+=b;
            a+=2*M*b;
        }
        //cout << "a : " << a << "\n";
        arr[i]=a;
        piece+=V[N+i];
        piece-=V[i];
        pt1++;
        pt2++;
        pt3++;
        pt4++;
        pt4%=2*N;
    }
    //cout << "arr : \n";
    //for(int i=0; i<N; i++) cout << arr[i] << " ";
    //cout << "\n";

    //cout << "ans : \n";
    //for(int i=0; i<2*N; i++) cout << ans[i] << " ";
    //cout << "\n";

    int ansarg=0, res=-1;

    for(int i=0; i<N; i++){
        ansarg=max(ansarg, abs(arr[i]));
        arr2[i]=arr[i];
        //cout << arr2[i] << " ";
    }

    //cout << "\n";

    //cout << "ansarg : " << ansarg << "\n";

    multiset<int> S;

    for(int i=0; i<N; i++){
        arr2[i]-=M;
        if(arr2[i]<-M){
            arr2[i]+=2*M;
        }
        S.insert(abs(arr2[i]));
    }
    
    if(ansarg>*prev(S.end())){
        ansarg=*prev(S.end());
        res=2*N-1;
    }

    //cout << "ansarg : " << ansarg << " res : " << res << "\n";

    for(int i=0; i<2*N; i++){
        //cout << "ansarg : " << ansarg << " res : " << res << "\n";
        if(i<N){
            S.erase(S.find(abs(arr2[i])));
            arr2[i]+=2*M;
            if(arr2[i]>M){
                arr2[i]-=2*M;
            }
            S.insert(abs(arr2[i]));
            //cout << *prev(S.end()) << "\n";
            if(ansarg>*prev(S.end())){
                ansarg=*prev(S.end());
                res=i;
            }
        }
        else{
            S.erase(S.find(abs(arr2[i-N])));
            arr2[i-N]-=2*M;
            if(arr2[i-N]<-M){
                arr2[i-N]+=2*M;
            }
            S.insert(abs(arr2[i-N]));
            //cout << *prev(S.end()) << "\n";
            if(ansarg>*prev(S.end())){
                ansarg=*prev(S.end());
                res=i;
            }
        }
    }

    if(res>=0){
        ans[res]++;
        if(res<N){
            for(int i=0; i<N; i++){
                if(i<=res) arr[i]+=M;
                else arr[i]-=M;
            }
        }
        else{
            for(int i=0; i<N; i++){
                if(i<=res-N) arr[i]-=M;
                else arr[i]+=M;
            }
        }
    }

    for(int i=0; i<N; i++){
        if(arr[i]<-M){
            ans[i]++;
            ans[i+N-1]++;
            arr[i]+=2*M;
        }
        if(arr[i]>M){
            ans[N+i]++;
            ans[(2*N-1+i)%(2*N)]++;
            arr[i]-=2*M;
        }
    }

    cout << ansarg << "\n";
    for(int i=0; i<2*N; i++){
        assert(ans[i]<=1e12);
        cout << ans[i] << " ";
    }
    
    return 0;
}
