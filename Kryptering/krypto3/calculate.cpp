#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int findGCD (int num1, int num2)
{
  if(num2 < 0){
    num2 *= -1; 
  }

  int k, gcd;
  if (num2 == 0){
    gcd = num1;
    return gcd;
  }
  else{
    k = num1 / num2;
    gcd = findGCD (num2, num1 - k * num2);
  }
}

int main()
{
  string line;
  int modulu = 0;
  int determinant;

  ifstream input ("determinant.txt");

  int tested = 0;
  int success = 0;
  int tempTested = 0;
  int tempSuccess = 0;

  if(input.is_open()){
    while(input.good()){
      getline(input, line);
    
      if(line == "Modulu"){
	cout << "Modulu: " << modulu << endl;
	cout << "Tested keys: " << tempTested << endl;
	cout << "Functional keys: " << tempSuccess << endl;
	cout << "Percentage: " << ((float)tempSuccess / (float)tempTested)*100 << endl;

	tested += tempTested;
	success += tempSuccess;

	tempTested = 0;
	tempSuccess = 0;

	getline(input, line);
	modulu = atoi(line.c_str());
      }
      else{
	determinant = atoi(line.c_str());
	int m = findGCD(modulu, determinant);

	tempTested++;
	if(m == 1){
	  tempSuccess++;
	}
      }
    }
    input.close();

    cout << endl << "Tested matrixes: " << tested << endl;
    cout << "Functional keys: " << success << endl;
    cout << "Percentage: " << ((float)success/(float)tested)*100 << endl;
  }
  else{
    cout << "File not found" << endl;
  }

  return 0;
}
