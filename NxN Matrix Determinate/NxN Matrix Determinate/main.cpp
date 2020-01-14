#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


void display(vector<vector<int>> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << endl;
    for (int j = 0; j < a.size(); j++) {
      cout << setw(3) << a[i][j] << " ";
    }
  }
  cout << endl;
}


int det2x2(vector<vector<int>> &a) {
  return ((a[0][0] * a[1][1]) - (a[0][1] * a[1][0]));
}


int nxnSolve(vector<vector<int>> &a) {
  int det = 0;
  bool pos = true;
  if (a.size() == 2) {
    return det2x2(a);
  }
  else {
    vector<vector<int>> temp(a.size() - 1, vector<int>(a.size() - 1));
    // goes over top row of numbers, and recursively calls this function until its a 2x2 in which det2x2 will be called.
    for (int i = 0; i < a.size(); i++) {

      // Fills smaller temp vector because of row operations.
      for (int j = 1; j < a.size(); j++) {
        vector<int> tempnums;
        for (int k = 0; k < a.size(); k++) {
          if (k != i) {
            tempnums.push_back(a[j][k]);
          }
        }
        temp[j - 1] = tempnums;
        tempnums.clear();
      }

      // Adds up determinate for each number in row 0, recursively calls function again for each matrix until 2x2.
      if (pos) {
        det += a[0][i] * nxnSolve(temp);
      }
      else {
        det += -1 * a[0][i] * nxnSolve(temp);
      }

      pos = !pos;
    }
  }

  return det;
}


int main() {

  vector<vector<int>> test(4, vector<int>(4));

  test[0][0] = 3;
  test[0][1] = 2;
  test[0][2] = -1;
  test[0][3] = 4;

  test[1][0] = 2;
  test[1][1] = 1;
  test[1][2] = 5;
  test[1][3] = 7;

  test[2][0] = 0;
  test[2][1] = 5;
  test[2][2] = 2;
  test[2][3] = -6;

  test[3][0] = -1;
  test[3][1] = 2;
  test[3][2] = 1;
  test[3][3] = 0;

  display(test);

  cout << "Det = " << nxnSolve(test) << endl;


  // https://www.youtube.com/watch?v=SlEzaXXlrHw 5x5 matrix example with answer.
  vector<vector<int>> fivebyfive(5, vector<int>(5));

  fivebyfive[0][0] = 3;
  fivebyfive[0][1] = 0;
  fivebyfive[0][2] = 0;
  fivebyfive[0][3] = 3;
  fivebyfive[0][4] = 0;

  fivebyfive[1][0] = -3;
  fivebyfive[1][1] = 0;
  fivebyfive[1][2] = -2;
  fivebyfive[1][3] = 0;
  fivebyfive[1][4] = 0;

  fivebyfive[2][0] = 0;
  fivebyfive[2][1] = -1;
  fivebyfive[2][2] = 0;
  fivebyfive[2][3] = 0;
  fivebyfive[2][4] = -3;

  fivebyfive[3][0] = 0;
  fivebyfive[3][1] = 0;
  fivebyfive[3][2] = 0;
  fivebyfive[3][3] = 3;
  fivebyfive[3][4] = 3;

  fivebyfive[4][0] = 0;
  fivebyfive[4][1] = -1;
  fivebyfive[4][2] = 2;
  fivebyfive[4][3] = 0;
  fivebyfive[4][4] = 1;



  display(fivebyfive);

  cout << "Det = " << nxnSolve(fivebyfive);

  return 0;
}