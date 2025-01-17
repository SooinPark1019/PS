#include <bits/stdc++.h>
#include <ios>
#define int long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;
    reverse(all(S));
    int ans;
    for(int i=0; i<S.length()-1; i++){
        if(S[i]<=S[i+1]){
            ans=i;
            break;
        }
    }
    cout << S.length()-ans-1;
}