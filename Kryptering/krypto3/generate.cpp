#include<Eigen/Dense>
#include<fstream>

using namespace std;
using namespace Eigen;

int main(){
  Matrix2i A;

  Matrix2i inverse;
  int determinant;
  bool invertible;

  ofstream output;
  output.open("determinant.txt");

  for(int max = 2; max <= 30; max++){
    output << "Modulu" << endl << max << endl;
    for(int i = 0; i < max; i++){
      A(0,0) = i;
      for(int n = 0; n < max; n++){
	A(0,1) = n;
	for(int m = 0; m < max; m++){
	  A(1,0) = m;
	  for(int j = 0; j < max; j++){
	    A(1,1) = j;
  	    
	    A.computeInverseAndDetWithCheck(inverse, determinant, invertible);

	    output << determinant << endl;

	  }
	}
      }
    }
  }

  output << "Modulu" << endl << 0 << endl;

  output.close();

  return 0;
}
