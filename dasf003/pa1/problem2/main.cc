#include <iostream>
#include "display.h"
#include "arabians.h"

using namespace std;

int main(){
  string s;
 
  //write your code here!
  //receive user input and store it into s varaible.
  //call reverseString function to reverse string
  //call customPrint function to print string
  getline(cin,s);
  string result = cpe::reverseString(s);
  cpe::customPrint(result);
  return 0;
}
