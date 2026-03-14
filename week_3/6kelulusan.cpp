#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   int nilai[n];
   for(int i = 0; i < n; i++){
      cout << "Masukkan nilai mahasiswa ke-" << i+1 << " : ";
      cin >> nilai[i];
   }
   cout << endl;
   cout << "Status Kelulusan : " << endl;
   for(int i = 0; i < n; i++){
      if(nilai[i] >= 75){
         cout << "Mahasiswa " << i+1 << " : Lulus" << endl;
      }
      else{
         cout << "Mahasiswa " << i+1 << " : Tidak Lulus" << endl;
      }
   }
   return 0;
}