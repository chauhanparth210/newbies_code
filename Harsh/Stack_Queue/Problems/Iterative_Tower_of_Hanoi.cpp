#include<bits/stdc++.h>
using namespace std;

void Iterative_Tower_of_Hanoi(int n){
    
    char move[n+1][3]; // store next movement of i'th disk
    for(int i = n; i > 0; i--){
        if((i-n) % 2 == 0){
            move[i][0] = 'A';
            move[i][1] = 'B';
            move[i][2] = 'C';
        }
        else{
            move[i][0] = 'A';
            move[i][1] = 'C';
            move[i][2] = 'B';
        }
    }

    int f_pos[n+1][2];
    f_pos[0][0] = 1; 
    f_pos[0][1] = 1;
    for(int i = 2; i <= n; i++){
        f_pos[i][1] = 4 * 1l * pow(2, i-2);  // distance between 2 consicutive i
        f_pos[i][0] = pow(2, i-1);           // first occurance of i
    }
/*
            iteration no.             moved disk
    1, 3, 5, 7, 9, 11, 13, 15...    -   1
    2, 6, 10, 14, 18, 22, 26...     -   2
    4, 12, 20, 28...                -   3
    8, 24...                        -   4
    16...                           -   5 

*/

    long total = pow(2, n);
    for(long i = 1; i < total; i++){
        if(i % 2 == 1){
            cout << "Move " << 1 << " from " << move[1][0] << " to " << move[1][2] << endl;
            swap(move[1][0], move[1][1]);
            swap(move[1][0], move[1][2]); // A B C -> C A B
            //cout << move[1][0] << " " << move[1][1] << " " << move[1][2] << endl;
        }
        else{
            int idx = -1;
            for(int j = 2; j <= n; j++){
                if((i - f_pos[j][0]) % f_pos[j][1] == 0){
                    idx = j;
                    break;
                }
            }
            cout << "Move " << idx << " from " << move[idx][0] << " to " << move[idx][2] << endl;
            swap(move[idx][0], move[idx][1]);
            swap(move[idx][0], move[idx][2]);   // A B C -> C A B
        }
    }

    return;
}


int main(){
    
    int n;
    cin >> n;

    Iterative_Tower_of_Hanoi(n);

    return 0;
}