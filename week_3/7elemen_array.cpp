#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[3][3] = {{67, 97, 23},
                    {12, 78, 30},
                    {60, 42, 87}};

    cout << "Isi array: " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Akses elemen ke 2 pada baris ke 2: " << arr[1][1];
return 0;}
