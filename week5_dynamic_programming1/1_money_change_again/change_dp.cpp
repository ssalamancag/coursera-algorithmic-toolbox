#include <iostream>
#include <algorithm>

using std::min;

int get_change(int m) {
  int a[m+1];
  a[0] = 0;
  for(int i = 1; i <= m; i++){
    if(i < 3) a[i] = a[i-1] + 1;
    if(i < 4) a[i] = min(a[i - 1], a[i - 3]) + 1;
    if(i >= 4) a[i] = min(a[i - 1], min(a[i - 3], a[i - 4])) + 1; 
  }
  return a[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
