#include <bits/stdc++.h>
#define pii pair<int,int>
#define int long long

using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N, K;
        cin >> N >> K;
        multiset<int> S;
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            S.insert(a);
        }
        int ans=0;
        while(!S.empty()){
            int a=*S.begin();
            S.erase(S.begin());
            if(a>=K){
                if(!S.empty())ans++;
            }
            else if(S.empty()) break;
            else{
                auto it=S.lower_bound(K-a);
                if(it==S.begin()){
                    S.erase(prev(S.end()));
                    if(!S.empty())ans++;
                    continue;
                }
                else{
                    it--;
                    S.erase(it);
                    if(S.empty()) break;
                    S.erase(prev(S.end()));
                    if(!S.empty())ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}