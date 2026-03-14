#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >> n;
   int nilai[n];
   int total = 0;
   float avg;
   for(int i = 0; i < n; i++){
      cout << "Masukkan nilai mahasiswa ke-" << i+1 << " : ";
      cin >> nilai[i];
      total += nilai[i];
   }
   avg = total / n;
   cout << endl;
   cout << "Total nilai : " << total << endl;
   cout << "Rata=rata : " << avg <<  endl;
   return 0;
}