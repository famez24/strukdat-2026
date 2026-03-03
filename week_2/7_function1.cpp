#include <iostream>
using namespace std;
void vowel_or_consonant(char x){
   if(x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o' ||
   x == 'A' || x == 'I' || x == 'U' || x == 'E' || x == 'O'){
      cout << "Vowel" << endl;
   }
   else{
      cout << "Consonant" << endl;
   }
}
int main(){
   vowel_or_consonant('c');
   vowel_or_consonant('E');
   return 0;
}
