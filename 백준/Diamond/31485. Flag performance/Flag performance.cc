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

map<vector<int>, int> DP;
int fac[35];
int bino[35][35];

int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        ll temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}

void fill_DP(int N, int K){
    vector<int> temp(N+1);
    temp[1]=N;
    DP[temp]=1;
    while(K--){
        //cout << "K : " << K << endl;
        //cout << endl;
        map<vector<int>, int> cal;
        for(auto p : DP){
            vector<int> part=p.first;
            int cnt=p.second;
            /*for(auto i : part) cout << i << " ";
            cout << "\n";
            cout << p.second << endl;
            cout << endl;*/
            for(int i=1; i<=N; i++){
                if(part[i]==0) continue;
                for(int j=i; j<=N; j++){
                    if(part[j]==0) continue; 
                    if(i==j&&part[i]>1){
                        int a=part[i]*(part[i]-1)/2;
                        a*=i;
                        a*=i;
                        part[i]-=2;
                        part[i*2]++;
                        cal[part]+=a*cnt%mod;
                        cal[part]%=mod;
                        part[i]+=2;
                        part[i*2]--;
                    }
                    else if(i!=j){
                        int a=part[i]*part[j];
                        a*=i;
                        a*=j;
                        part[i]--;
                        part[j]--;
                        part[i+j]++;
                        cal[part]+=a*cnt%mod;
                        cal[part]%=mod;
                        part[i]++;
                        part[j]++;
                        part[i+j]--;
                    }
                }
                for(int j=1; j<=i/2; j++){
                    int a;
                    if(2*j==i) a=part[i]*i/2;
                    else a=part[i]*i;
                    part[i]--;
                    part[j]++;
                    part[i-j]++;
                    cal[part]+=a*cnt%mod;
                    cal[part]%=mod;
                    part[i]++;
                    part[j]--;
                    part[i-j]--;
                }
            }
        }
        swap(DP, cal);
    }
}

vector<int> decompose(vector<int>& query, int N){
    vector<int> res(N+1);
    vector<int> vis(N+1);
    for(int i=1; i<=N; i++){
        if(vis[i]==1) continue;
        vis[i]=1;
        int cur=query[i];
        int sz=1;
        while(cur!=i){
            vis[cur]=1;
            cur=query[cur];
            sz++;
        }
        res[sz]++;
    }
    return res;
}

int cal_number(vector<int>& V, int N){
    int res=1;
    for(int i=1; i<=N; i++){
        for(int j=0; j<V[i]; j++){
            res*=bino[N][i]*fac[i-1]%mod;
            res%=mod;
            N-=i;
        }
        res*=fastmul(fac[V[i]], mod-2);
        res%=mod;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, T;
    cin >> N >> K >> T;
    fill_DP(N, K);
    fac[0]=1;
    for(int i=1; i<=N; i++){
        fac[i]=fac[i-1]*i%mod;
    }
    for(int i=1; i<=N; i++){
        for(int j=0; j<=i; j++){
            if(j==0||i==j) bino[i][j]=1;
            else{
                bino[i][j]=bino[i-1][j]+bino[i-1][j-1];
                bino[i][j]%=mod;
            }
        }
    }
    /*cout << "DP : " << endl;
    cout << endl;
    for(auto p : DP){
        vector<int> part=p.first;
        int cnt=p.second;
        for(auto i : part) cout << i << " ";
        cout << "\n";
        cout << p.second << endl;
        cout << endl;
    }*/
    while(T--){
        vector<int> query(N+1);
        for(int i=1; i<=N; i++){
            cin >> query[i];
        }
        vector<int> cycle=decompose(query, N);
        /*cout << "original" << endl;
        for(int i=1; i<=N; i++) cout << query[i] << " ";
        cout << endl;*/
        /*cout << "decomposed" << endl;
        for(int i=1; i<=N; i++) cout << cycle[i] << " ";
        cout << endl;*/
        int a=cal_number(cycle, N);
        //cout << "number of case : " << a << endl;
        cout << DP[cycle]*fastmul(a, mod-2)%mod << "\n";
    }

    return 0;
}