#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0;
  n += m/10;
  //printf("%d\n", n);
  int res = m % 10;
  n += res/5;
  //printf("%d\n",n);
  n += res%5;
  
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
