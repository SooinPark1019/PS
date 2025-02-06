#include <bits/stdc++.h>
//#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

//const int INF=1e18;

using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<pair<string, int>> S[105];
    int N;
    cin >> N;
    int total=0;
    for(int i=0; i<N; i++){
        int l;
        cin >> l;
        total+=l;
        for(int j=0; j<l; j++){
            string A, T;
            int flag=0;
            string temp;
            cin >> temp;
            for(auto c : temp){
                if(c=='=') flag=1;
                else if(flag==0) A+=c;
                else T+=c;
            }
            int a=stoll(T);
            S[i].push({A, a});
        }
    }
    map<string, int> M;
    int K;
    cin >> K;
    for(int i=0; i<K; i++){
        string s;
        int a;
        cin >> s >> a;
        M[s]=a;
    }
    vector<int> ans;
    while(1){
        int curstack=0;
        while(curstack<N){
            if(!S[curstack].empty()&&(M[S[curstack].top().first]==-1||M[S[curstack].top().first]==S[curstack].top().second)){
                M[S[curstack].top().first]=-1;
                ans.push_back(curstack+1);
                S[curstack].pop();
                break;
            }
            curstack++;
        }
        if(curstack==N) break;
    }
    if(ans.size()<total) cout << "No";
    else{
        cout << "Yes\n";
        reverse(all(ans));
        for(auto i : ans) cout << i << " ";
    }
}
