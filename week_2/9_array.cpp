#include <iostream>
using namespace std;

int findmin(int arr[], int n){
   int min = arr[0];
   for(int i = 0; i < n; i++){
      if(arr[i] < min){
         min = arr[i];
      }
   }
   return min;
}

int findmax(int arr[], int n){
   int max = arr[0];
   for(int i = 0; i < n; i++){
      if(arr[i] > max){
         max = arr[i];
      }
   }
   return max;
}

int main(){
   int arr[] = {12, 1234, 45, 67, 1};
   int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Minimum element of array: " << findmin(arr, n) << endl;
   cout << "Maximum element of array: " << findmax(arr, n);
   return 0;
}
