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
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
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

int calc_dis(int a, vector<int>& Kset){
    auto it=lower_bound(all(Kset), a);
    int temp=1e18;
    if(it!=Kset.end()){
        temp=min(temp, (*it-a)*(*it-a));
    }
    if(it!=Kset.begin()){
        it--;
        temp=min(temp, (*it-a)*(*it-a));
    }
    return temp;
}
    
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N, M;
        cin >> N >> M;
        UnionFind UF(N+1);
        vector<int> oneset, Nset;
        for(int i=0; i<M; i++){
            int a, b;
            cin >> a >> b;
            UF.UnionSet(a, b);
        }
        for(int i=1; i<=N; i++){
            if(UF.isSameSet(1, i)) oneset.push_back(i);
            if(UF.isSameSet(N, i)) Nset.push_back(i);
        }
        vector<int> disfromone(N+1, 1e18), disfromN(N+1, 1e18);
        for(int i=1; i<=N; i++){
            disfromone[UF.findset(i)]=min(disfromone[UF.findset(i)], calc_dis(i, oneset));
            disfromN[UF.findset(i)]=min(disfromN[UF.findset(i)], calc_dis(i, Nset));
        }

        int ans=1e18;
        for(int i=1; i<=N; i++){
            ans=min(ans, disfromone[UF.findset(i)]+disfromN[UF.findset(i)]);
        }
        cout << ans << "\n";
    }

    return 0;
}
