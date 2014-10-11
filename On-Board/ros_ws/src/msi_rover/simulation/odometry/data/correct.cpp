#include <iostream>
#include <fstream>
using namespace std;

int main(){
ifstream  in("psi");
ofstream out("cpsi");
double val;
while (!in.eof()) {
in >> val;
if (val > 3.1459) val = val - 2*3.14159;
out << val << endl;
}
}
