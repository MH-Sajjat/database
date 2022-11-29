#include<iostream>
#include<fstream>
using namespace std;

int main() {
  ifstream fileRead;
  string fname;
  cout << "Enter filename: ";
  cin >> fname;
  fileRead.open(fname);
  if (!fileRead) {
    cout << "File does not exist\n";
  } else {
    string temp;
    while (!fileRead.eof()) {
      getline(fileRead, temp);
      cout << temp << endl;
    }
  }
  fileRead.close();
  return 0;
}
