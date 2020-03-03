/*this is the program to distribute 3 digits of the entered number by order 
using space between them*/

#include <iostream>
using namespace std;

int main () {
int numb, digit1, digit2, digit3;

cout <<  "Enter the number that has three digits:" << endl;
cin >> numb;

digit3=numb%10;
digit2=(numb/10)%10;
digit1=numb/100;

cout << " digit1, digit2, digit3 "<< endl;

return 0;
}
