#include<bits/stdc++.h>
using namespace std;

int main(){

    int test;
    cin >> test;

    long int n;
    while(test--){
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        long int moves = 0, totalA = 0, totalB = 0;
        long int countA = 0, countB = 0;
        int i = 0, j = n-1;
        bool tern = true;

        while(i <= j){
            if(tern){
                countA = 0;
                while(countA <= countB && i <= j){
                    countA += a[i];
                    i++;
                }
                totalA += countA;
                tern = false;
                moves++;
            }
            else{
                countB = 0;
                while(countB <= countA && i <= j){
                    countB += a[j];
                    j--;
                }
                totalB += countB;
                tern = true;
                moves++;
            }
        }

        cout << moves << " " << totalA << " "  << totalB << endl;

    }

    return 0;
}