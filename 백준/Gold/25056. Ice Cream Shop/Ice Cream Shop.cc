#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

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
const ll mod = 998244353;
const ll MAX = 1e5+5;

int N, M;
vector<int> huts;
vector<int> sellers;

int sol(int i){
    vector<int> temp;
    int curpos=sellers[i]/100+1;
    //cout << "curpos : " << curpos << "\n";
    while(curpos<N&&curpos*100<sellers[i+1]){
        temp.push_back(huts[curpos]);
        curpos++;
    }
    if(temp.size()==0) return 0;
    int a;
    if(temp.size()%2!=0){
        a=(temp.size()+1)/2;
    }
    else{
        int x=100-sellers[i]%100;
        int y=sellers[i+1]-(curpos-1)*100;
        if(x+y>100) a=temp.size()/2+1;
        else a=temp.size()/2;
    }
    //cout << "a: " << a << "\n";
    int ret=0;
    int cur=0;
    for(int i=0; i<a; i++) ret+=temp[i];
    cur=ret;
    for(int i=a; i<temp.size(); i++){
        cur+=temp[i];
        cur-=temp[i-a];
        ret=max(ret, cur);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        huts.push_back(a);
    }
    for(int i=0; i<M; i++){
        int a;
        cin >> a;
        sellers.push_back(a);
    }

    sort(all(sellers));

    int ans=0;
    int curpos=0;
    while(curpos<N&&curpos*100<sellers[0]){
        ans+=huts[curpos];
        curpos++;
    }

    for(int i=0; i<M-1; i++){
        ans=max(ans, sol(i));
    }

    int temp=0;
    curpos=sellers.back()/100+1;
    while(curpos<N){
        temp+=huts[curpos];
        curpos++;
    }
    ans=max(ans, temp);

    cout << ans;

    return 0;
}
