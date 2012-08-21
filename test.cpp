#include <stdio.h>
#include <math.h>

#include "mvtnorm.h"
void check(const double correct,
           const double ret,
           const double error) {
  double diff = fabs(correct - ret);
    if (diff > error) {
      fprintf(stderr, "[ERROR] diff = %g\n", diff);
    } else {
      printf("[CORRECT] ret = %g\n", ret);
    }
}
int main(int argc, char *argv[])
{
  // int n = 2;
  // double upper[2] = {0, 1.414};
  // double corr[1] = {0.0};
  const double eps = 1e-6; 
  {
    int n = 2;
    double upper[2] = {1.0, 1.0};
    double corr[1] = {0.0};

    // test
    // P(X < {1, 1}) where
    // X ~ MVN( {0, 0}, {1, 0; 0 1} )
    const double correct = 0.707861;    
    double error;
    double ret = pmvnorm_P(2, upper, corr, &error);
    //printf("ret = %g\n", ret);
    check(correct, ret, eps);

    // test
    // P(X > {1, 1}) where
    // X ~ MVN( {0, 0}, {1, 0; 0 1} )
    const double correct2 = 0.02517149;
    ret = pmvnorm_Q(2, upper, corr, &error);
    // printf("ret = %g\n", ret);
    check(correct2, ret, eps);
  }
  {
    // test
    // P(X < {1, 4, 2}) where
    // X ~ MVN( {0, 0}, {1,
    //                   3/5,      1, 
    //                   1/3,  11/15,   1} )
    int m = 3;
    double sigma[] = {3.0/5, 1.0/3, 11.0/15};
    double upper[] = {1.0, 4.0, 2.0};
    double error;
    double ret = pmvnorm_P(3, upper, sigma, &error);
    const double correct = 0.8279846;
    check(correct, ret, eps);
  };

  return 0;
}
