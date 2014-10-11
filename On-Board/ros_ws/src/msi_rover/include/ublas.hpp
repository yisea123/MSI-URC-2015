#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>

namespace boost{
  namespace numeric{
    namespace ublas{
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
      template<class T>
      bool inv(const matrix<T>& input, matrix<T>& inverse)
      {
        matrix<T> A(input);
        permutation_matrix<std::size_t> pm(A.size1());
        int res = lu_factorize(A, pm);
        if (res != 0)
          return false;
        inverse.assign(identity_matrix<T> (A.size1()));
        lu_substitute(A, pm, inverse);
        return true;
      }
//////////////////////////////////////////////////////
      template<class T, class V>
      bool fill(matrix<T>& input, const V value)
      {
        for (int i = 0; i < input.size1(); i++) {
          for (int j = 0; j < input.size2(); j++) {
            input(i,j) = value;
          }
        }
        return true;
      }
//////////////////////////////////////////////////////
      template<class T, class V>
      bool fill(vector<T>& input, const V value)
      {
        for (int i = 0; i < input.size(); i++) {
          input(i) = value;
        }
        return true;
      }
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
    }
  }
}
