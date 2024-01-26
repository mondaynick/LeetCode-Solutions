/*
  給定一數x，求其平方根

  利用牛頓法，令f(xn) = xn ^ 2 - x，則f'(xn) = 2 * xn，因此要求x的平方根相當於求f(xn) = 0之解，
  因為m = ( f(xn) - f(xn+1) ) / ( xn - xn+1 ) 又 m = f'(xn) 且 f(xn+1) = 0
  => m * xn - m * xn+1 = f(xn)
  => m * xn+1 = m * xn - f(xn)
  => xn+1 = ( xn + ( x / xn ) ) / 2
 */

class Solution {
public:
    int mySqrt(int x) {
        long temp = x;
        while (temp * temp > x) {
            temp = (temp + x / temp) / 2;
        }
        return temp;
    }
};
