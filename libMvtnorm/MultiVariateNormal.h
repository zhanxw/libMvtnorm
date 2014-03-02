#ifndef _MULTIVARIATENORMAL_H_
#define _MULTIVARIATENORMAL_H_

#include "mvtnorm.h"

class MultiVariateNormal{
 public:
  int pmvnorm(Vector& lower,
              Vector& upper,
              Vector& mean,
              Matrix& cov,
              double* result);
 private:
  std::vector<double> lower;
  std::vector<double> upper;
  std::vector<int> infin;
  std::vector<double> delta;
};

#endif /* _MULTIVARIATENORMAL_H_ */
