#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
ifstream y_corr("yaw");
ifstream p_corr("pitch");
ifstream r_corr("roll");
ifstream y_act("../data/psi");
ifstream p_act("../data/theta");
ifstream r_act("../data/phi");
long i = 0;
double y_error = 0.0;
double p_error = 0.0;
double r_error = 0.0;
double corr;
double act;
while (!y_corr.eof() && !y_act.eof()) {
i++;
y_corr >> corr;
y_act >> act;
y_error = y_error + (corr-act)*(corr-act);
}
i = 0;
while (!p_corr.eof() && !p_act.eof()) {
i++;
p_corr >> corr;
p_act >> act;
p_error = p_error + (corr-act)*(corr-act);
}
i = 0;
while (!r_corr.eof() && !r_act.eof()) {
i++;
r_corr >> corr;
r_act >> act;
r_error = r_error + (corr-act)*(corr-act);
}
cout << "RMS error: [ " << sqrt(y_error/i) << ", " << sqrt(p_error/i) << ", " << sqrt(r_error/i) << " ]\n";
cout << " MS error: [ " <<      y_error/i  << ", " <<      p_error/i  << ", " <<      r_error/i  << " ]\n";
}
