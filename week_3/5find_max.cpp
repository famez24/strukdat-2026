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
   int max = nilai[0];
   for(int i = 0; i < n; i++){
      if(nilai[i] > max){
         max = nilai[i];
      }
   }
   cout << "Nilai tertinggi adalah : " << max << endl;
   return 0;
}