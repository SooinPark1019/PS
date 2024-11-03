#include <bits/stdc++.h>

using namespace std;


int ans;
int N, M;
set<int> buttons;

void sol(string str){
    for(auto i : buttons){
        string temp = str + to_string(i);
        int a=abs(N-stoi(temp))+temp.length();
        ans=min(ans, a);

        if(temp.length() < 6) sol(temp);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> M;
    ans=abs(100-N);
    for(int i=0; i<10; i++){
        buttons.insert(i);
    }
    for(int i=0; i<M; i++){
        int a;
        cin >> a;
        buttons.erase(a);
    }

    if(M<10) sol("");
    cout << ans;
}
