#include <iostream>
using namespace std;
int isPrime(int n){
   if(n <= 1){
      return 0;
   }
   for(int i = 2; i < n; i++){
      if(n % i == 0){
         return 0;
      }
   }
   return 1;
}
void findPrime(int a, int b){
   int prime = 0;
   for(int i = a; i <= b; i++){
      if(isPrime(i)){
         cout << i << " ";
         prime = 1;
      }
   }
   if(!prime){
      cout << "No prime numbers found in the given range.";
   }
}

int main(){
   int l = 10, r = 30;
   findPrime(l, r);
   return 0;
}
