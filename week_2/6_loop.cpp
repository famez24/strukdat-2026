#include <iostream>
using namespace std;
int main(){
   int rows;
   cin >> rows;
   int angka = 1;
   for(int i = 0; i < rows; i++){
      for(int j = 0; j < i+1; j++){
         cout << angka << " ";
         angka++;
      }
      cout << "\n";
   }
   return 0;
}
