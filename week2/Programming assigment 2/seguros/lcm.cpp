#include <iostream>

long long lcm_naive(long long int a, long long int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long int gcd_fast(long long int a,long long int b){
  if(a%b == 0) return a;

  long long int prev;
  while(b != 0){
    prev = a%b;
    a = b;
    b = prev;
  }
  return a;
}
long long int lcm_fast(long long int a, long long int b ){
    long long int gcd =gcd_fast(a,b);
    long long int lcm = a*(b/gcd);
    return lcm;
}

int main() {
  long long int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
