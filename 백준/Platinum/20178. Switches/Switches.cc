#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

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

int N;

pair<vector<int>, vector<int>> reduce(vector<vector<int>>& b, vector<int>& x, vector<vector<int>>& index){
    vector<int> ret(N, 0);
    for(int i=0; i<x.size(); i++){
        if(x[i]==1&&index[i].size()>0){
            for(int j=0; j<x.size(); j++){
                ret[j]^=index[i][j];
                x[j]^=b[i][j];
            }
        }
    }
    return {x, ret};
}

bool add(vector<vector<int>>& b, vector<int>& x, vector<vector<int>>& index, int curidx){
    pair<vector<int>, vector<int>> pv=reduce(b, x, index);
    pv.second[curidx]^=1;
    for(int i=0; i<x.size(); i++){
        if(x[i]==1){
            b[i]=pv.first;
            index[i]=pv.second;
            return true;
        }
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vector<vector<int>> b(N);
    vector<vector<int>> index(N);
    int flag=0;
    for(int i=0; i<N; i++){
        vector<int> temp;
        for(int j=0; j<N; j++){
            int a;
            cin >> a;
            temp.push_back(a);
        }
        if(!add(b, temp, index, i)){
            flag=1;
        }
    }
    /*cout << "b : \n";
    for(auto v : b){
        for(auto i : v) cout << i << " ";
        cout << "\n";
    }
    cout << "index : \n";
    for(auto v : index){
        for(auto i : v) cout << i << " ";
        cout << "\n";
    }*/
    if(flag==1){
        cout << -1;
        return 0;
    }
    for(int i=0; i<N; i++){
        vector<int> ans(N, 0);
        vector<int> temp(N, 0);
        temp[i]=1;
        for(int j=0; j<N; j++){
            if(temp[j]==1){
                for(int k=0; k<N; k++){
                    ans[k]^=index[j][k];
                    temp[k]^=b[j][k];
                }
            }
        }
        for(int i=0; i<N; i++){
            if(ans[i]==1){
                cout << i+1 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
