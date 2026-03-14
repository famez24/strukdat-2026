#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   int nilai[n];
   for(int i = 0; i < n; i++){
      cout << "Masukkan nilai ke-" << i+1 << " : ";
      cin >> nilai[i];
   }
   cout << endl;
   cout << "Data yang dimasukkan: " << endl;
   for(int i = 0; i < n; i++){
      cout << nilai[i] << endl;
   }
   return 0;
}