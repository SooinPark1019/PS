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

class UnionFind{
    private:
        vector<int> p, rank, setSize;
    public:
        UnionFind(int N){
            p.assign(N, 0);
            for(int i=0; i<N; i++) p[i]=i;
            rank.assign(N, 0);
            setSize.assign(N, 1);
        };
        int findset(int i){
            return(p[i]==i) ? i : (p[i]=findset(p[i]));
        }
        bool isSameSet(int i, int j){
        return findset(i) == findset(j);
        }
        int SizeOfSet(int i){
            return setSize[findset(i)];
        }
        void UnionSet(int i, int j){
        if(isSameSet(i, j)) return;
        int x=findset(i);
        int y=findset(j);
        if(rank[x]>rank[y]) swap(y,x);
        p[x] = y;
        if(rank[x]==rank[y]) rank[y]++;
        setSize[y]+=setSize[x];
        }
    };

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        string S, T;
        cin >> S >> T;

        if(S==T){
            cout << 0 << "\n";
            continue;
        }

        UnionFind UF(52);
        vector<int> to(52, -1);
        vector<int> indegree(52);
        int flag=0;
        for(int i=0; i<S.length(); i++){
            int a, b;
            if(S[i]<'a') a=S[i]-'A';
            else a=S[i]-'a'+26;
            if(T[i]<'a') b=T[i]-'A';
            else b=T[i]-'a'+26;
            assert(a<52&&b<52);
            if(to[a]==-1) to[a]=b;
            else if(to[a]!=b) flag=1;
        }
        if(flag){
            cout << -1 << "\n";
            continue;
        }
        vector<int> temp=to;
        sort(all(temp));
        for(int i=0; i<52; i++){
            if(temp[i]!=i){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout << -1 << "\n";
            continue;
        }
        int ans=0;
        for(int i=0; i<52; i++){
            if(to[i]!=-1){
                if(to[i]!=i) ans++;
                indegree[to[i]]++;
                UF.UnionSet(i, to[i]);
            }
        }
        vector<int> check(52);
        for(int i=0; i<52; i++){
            int a=UF.findset(i);
            if(check[a]) continue;
            check[a]++;
            if(UF.SizeOfSet(a)==1) continue;
            int iscycle=1;
            for(int j=0; j<52; j++){    
                if(UF.isSameSet(a, j)&&indegree[j]!=1){
                    iscycle=0;
                    break;
                }
            }
            if(iscycle) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
