#include "../include/ublas.hpp"
#include <iostream>
#include <boost/numeric/ublas/matrix_proxy.hpp>

namespace ublas = boost::numeric::ublas;

int main()
{
    ublas::vector<double> v( 10 );
    ublas::matrix<double> m( 5, 10 );
    v(1) = 27;
    ublas::matrix_row<ublas::matrix<double> > r( m, 0 );
    r = v;
    std::cout<<m<<std::endl;
    return 0;
}
/*
using namespace boost::numeric::ublas;

int main() {
matrix<double> mat(2000,6);
vector<double> v1row(6);
vector<double> v2row(6);
matrix<double> result(6,6);

fill(mat, 0);
fill(v1row, 0);
fill(v2row, 0);
fill(result, 0);

v1row(0) = 1;
v2row(1) = 1;
mat(0,0) = 0;
mat(0,1) = 1;
mat(0,2) = 2;
mat(0,3) = 3;
mat(0,4) = 4;
mat(0,5) = 5;
matrix_row<matrix<double> > row(mat,0);

result = outer_prod(row,row);
std::cout << result << std::endl;
}
*/
