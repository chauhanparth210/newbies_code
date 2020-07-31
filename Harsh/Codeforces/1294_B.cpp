//https://codeforces.com/problemset/problem/1294/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;

    while(test--){
        int n;
        cin >> n;
        vector<pair<int, int> > v;

        int x, y;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }
        sort(v.begin(), v.end());

        string path = "";
        int count = 0, last_len = 0;
        int prv_x = 0, prv_y = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= v[i].first - prv_x; j++){
                path = path + 'R';
            }
            
            for(int j = 1; j <= v[i].second - prv_y; j++){
                path = path + 'U';
            }

            if(v[i].first-prv_x + v[i].second-prv_y == path.size()-last_len){
                count++;
                last_len = path.size();
            }

            prv_x = v[i].first;
            if(prv_y < v[i].second)
                prv_y = v[i].second;
                        
        }

       // cout << count << endl;

        if(count == n)
            cout << "YES\n" << path << endl;
        else 
            cout << "NO\n";
    }

    return 0;
}