#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
//#define int long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
/*#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int indexa = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(indexa);
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
결국 문제를 다시 생각하면
조건을 만족하는 substring의 개수를 세라는 건데
무조건 투포인터 느낌일 거다
왼쪽을 고정했다고 치면
가능한 오른쪽인덱스는 [i...]로 나타날 것이므로
맨 왼쪽부터 투포인터 느낌으로 세어가면 될듯

아 이러면 안되네
그러면 쓰리 포인터는 어떨까

어차피 안되는 거의 상한도 마찬가지잖아
아 이게 쓰리 포인터가 아닌가
첫포인터가 오른쪽으로 한칸 이동했다고 치자
세번째 포인터가 항상 단조적으로 증가하지 않을 수가 있나?

원래 3개가 등장하는 게 두개가 있고 4개가 등장하는게 하나가 있는데
3개가 등장하는 게 하나로 되는데 3개에서 4개로 되는게 그전에 있다면
앞으로 가지네
이런

처음부터 다시 풀어야겠는데

아 그리고 애초에
됐다가 안됐다가 될수도 있네
그냥 처음부터 틀린 풀이였다

다시 생각을 해보자

원소의 상한이 N이라는 게 큰 힌트긴 하다
각 원소에 대해서
레이지 연산을 한다?

일단 펜윅트리를 K개 만들자
각 원소에 대해 i번 펜윅트리에는
해당 원소부터 i-1칸 앞에 있는 같은 원소~해당 원소부터 i칸 앞에 있는 원소 [,) 의 형태로 업데이트를 해주고
이제 이게 모든 K에 대해서 차있는 애의 개수를 구해줘야 하는데

얘네의 교집합을 구해주는 걸 이제 어떻게 할까
다 차 있는 애들의 개수...

min(seg[1], seg[2], ... seg[k])가 0이 아닌 애들의 개수
자 만약 K=1이라고 하자
어떻게 할래?

제곱근 분할?
루트번보다 조금 나오는 애들이랑
루트번보다 많이 나오는 애들로 나눈다?
루트번보다 많이 나오는 애들은 루트개밖에 없음

처음의 컨셉을 시작해보자
시작점을 고정하고 가능한 끝점의 개수를 세는 것

루트번보다 조금 나오는 애들을 일단 어떻게 처리할까?

일단 나이브한 해법부터 다시 생각해보자
나이브한 해법은 왼쪽점을 고정한 후
오른쪽으로 가면서 해당 시점에서 valid한지를 확인하는 건데
처음에는 일단 각 지점의 카운트를 쭉 구해놓고
그다음에 왼쪽점을 오른쪽으로 한칸씩 옮겨가야 한다

결국 어떤 점을 '벗어나면' 해당 원소에 대해서 구간들에 갱신이 이루어진다고 볼 수도 있을듯
*/

int pointer[100005];
vector<int> indexa[100005];
int cnt[5][100005];

int N, K;

int check(int cur){
    for(int i=1; i<=K; i++){
        if(cnt[i][cur]==0) return 0;
    }
    return 1;
}
ll cur=0;
ll ans=0;
void sol(int num, int pointer, int val){
    for(int i=0; i<K; i++){
        if(pointer+i+1>=indexa[num].size()) break;
        for(int j=indexa[num][pointer+i]; j<indexa[num][pointer+i+1]; j++){
            int a=check(j);
            cnt[i+1][j]+=val;
            int b=check(j);
            if(a==1&&b==0) cur--;
            if(a==0&&b==1) cur++;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        indexa[a].push_back(i);
        V.push_back(a);
    }
    for(int i=1; i<=N; i++){
        indexa[i].push_back(N);
    }

    for(int i=1; i<=N; i++){
        sol(i, pointer[i], 1);
    }
    ans+=cur;
    for(int i=0; i<N; i++){
        sol(V[i], pointer[V[i]], -1);
        pointer[V[i]]++;
        sol(V[i], pointer[V[i]], 1);
        ans+=cur;
    }

    cout << ans;

    return 0;
}
