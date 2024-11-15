#include <bits/stdc++.h>
#include <ios>
#define int long long
#define all(v) v.begin(), v.end()
#define pair<int, int> pii

using namespace std;

const int INF=1e18;
const int BIG=1e9;

vector<int> string_to_vector(string& S){
    vector<int> V;
    int last=0;
    for(auto i : S){
        if(i>='A'){
            if(last!=0){
                V.push_back(last);
                last=0;
            }
            V.push_back(BIG+5+i);
        }
        else{
            last*=10;
            last+=i-'0';
        }
    }
    if(last!=0){
        V.push_back(last);
    }
    return V;
}

bool compare(vector<int>& A, vector<int>& B){
    for(int i=0; i<min(A.size(), B.size()); i++){
        if(A[i]!=B[i]){
            if(A[i]>B[i]) return true;
            else return false;
        }
    }
    if(A.size()>B.size()) return true;
    else return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> V=string_to_vector(S);
    for(int i=0; i<N; i++){
        string T;
        cin >> T;
        vector<int> temp=string_to_vector(T);
        if(compare(V, temp)) cout << "-\n";
        else cout << "+\n";
    }
}