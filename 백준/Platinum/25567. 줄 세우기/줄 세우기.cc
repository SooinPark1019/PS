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
#define sz(x) (int)x.size()

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

/*
개 어려운데

그래프가 나뉜다는 것의 의미를 생각해보자
어떤 경계를 기준으로 왼쪽에서의 최솟값이 오른쪽에서의 최댓값보다 크다면, 그 곳을 기준으로 그래프는 나뉘게 된다

왼쪽부터 값을 정해나가는 DP일 것 같긴 한데
애초부터 각 연결요소들의 구간, 최대/최소를 구해놓자
각 -1들에 대해서 DP[현재 위치][왼쪽에 있는 연결요소 개수]

다시
-1들을 각각의 연결요소라고 생각해버리자
그러면 DP[현재 위치][왼쪽에 있는 연결요소 개수]=경우의 수로 DP식을 세웠을 때
각 연결요소들의 최댓값에 대해서 이 값보다 작은 애가 나올 때까지로 점프를 뛸 수 있다
최댓값은 -1을 제외하면 연결요소 사이에는 감소할 것이다
이분탐색으로 어디로 점프할지 알 수 있고
이거를 채워나가면 될 것 같은데
여기서 연결요소 안에 들어가 있는 -1들은 어떻게 처리하지?
점프하면서 지나치는 -1들의 개수를 세서 M^개수만큼 경우의 수에 곱해주면 된다

각 연결요소마다 -1의 개수로 하고
이걸 기준으로 DP를 한다고 생각을 해버리자
최댓값을 정하면
최댓값^개수-(최댓값-1)^개수

맨 끝에 나오는 -1 어떻게 처리하지?

다시 생각해야 하나
생각해보니까 왼쪽 거를 흡수하기도 해서

연결요소 별로 나눠서 생각하는 게 맞는 거 같은데

DP[현재 연결요소의 인덱스][왼쪽 연결요소의 개수]로 놓고
왼쪽으로 합쳐지는 경우를 왼쪽에서 계산해버리는 식으로 생각하자.

연결요소들을 최대/최소의 구간으로 표현했을 때
지금까지의 최솟값보다 오른쪽에서 더 큰 게 없으면 연결요소가 나누어진다

연결요소가 한 개일 경우의 수는 두 양 끝점이 합쳐지는 경우

이렇게 접근하면 안될 것 같고
DP를 어떻게 세워야 되지?

더블 카운팅?
각 연결요소 별로 합쳐지는 경우의 수를 세가지고
이걸로 비비는 건가?

서로 인접한 애들끼리 합쳐지지 않는 경우의 수?
*/
int line[200005];
list<int> L[200005];
list<int> D[200005];
int indexa[200005];
int linenum[200005];
vector<int> prefix;

struct query{
    int type, a, b;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        for(int j=1; j<=a; j++){
            int b;
            cin >> b;
            L[i].push_back(b);
            D[i].push_back(b);
            line[b]=i;
            linenum[b]=i;
        }
    }

    vector<query> V;

    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int type, a, b;
        cin >> type >> a >> b;
        V.push_back({type, a, b});
        int la=linenum[a];
        int lb=linenum[b];
        if(type==2||la==lb) continue;
        if(L[la].size()<L[lb].size()){
            while(!L[la].empty()){
                int x=L[la].back();
                linenum[x]=lb;
                L[la].pop_back();
                L[lb].push_front(x);
            }
        }
        else{
            while(!L[lb].empty()){
                int x=L[lb].front();
                linenum[x]=la;
                L[lb].pop_front();
                L[la].push_back(x);
            }
        }
    }

    int indexcnt=0;
    for(int i=1; i<=N; i++){
        while(!L[i].empty()){
            int a=L[i].front();
            L[i].pop_front();
            indexa[a]=indexcnt;
            if(prefix.empty()) prefix.push_back(a);
            else prefix.push_back(prefix.back()+a);
            indexcnt++;
        }
    }

    for(auto q : V){
        if(q.type==1){
            int a=q.a;
            int b=q.b;
            if(line[a]==line[b]) cout << "NO\n";
            else{
                cout << "YES\n";
                int la=line[a];
                int lb=line[b];
                if(D[la].size()<D[lb].size()){
                    while(!D[la].empty()){
                        int x=D[la].back();
                        line[x]=lb;
                        D[la].pop_back();
                        D[lb].push_front(x);
                    }
                }
                else{
                    while(!D[lb].empty()){
                        int x=D[lb].front();
                        line[x]=la;
                        D[lb].pop_front();
                        D[la].push_back(x);
                    }
                }
            }
        }
        else{
            int a=q.a;
            int b=q.b;
            if(line[a]!=line[b]) cout << "-1\n";
            else{
                if(indexa[a]>indexa[b]) swap(a, b);
                int ans=prefix[indexa[b]];
                if(indexa[a]>0) ans-=prefix[indexa[a]-1];
                cout << ans << "\n";
            }
        }
    }

    return 0;
}
