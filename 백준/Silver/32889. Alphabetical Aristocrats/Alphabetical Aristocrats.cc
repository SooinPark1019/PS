#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;  
    vector<pair<string, int>> V;
    vector<string> T;

    cin.ignore();

    for(int i=0; i<N; i++){
        //cout << "i : " << i << endl;
        string S;
        getline(cin, S);
        //cout << S << "\n";
        T.push_back(S);
        int index=0;
        for(int i=0; i<S.length(); i++){
            if(S[i]>='A'&&S[i]<='Z'){
                index=i;
                break;
            }
        }
        //cout << index << endl;
        V.push_back({S.substr(index, S.length()-index+1), i});
    }
    sort(all(V));
    for(auto s : V) cout << T[s.second] << "\n";
}