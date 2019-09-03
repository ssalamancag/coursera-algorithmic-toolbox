#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int n) {
  std::sort(a.begin(), a.end());
  //for (std::vector<int>::iterator it=a.begin(); it!=a.end(); ++it)
    //std::cout << ' ' << *it;
  //std::cout << '\n';
  int e = a[0];
  int count = 1;
  for(int i = 1 ; i < n ; i++ ){
    if(count > n/2){
      return 1;
    }
    if(e == a[i]){
      count++;
    }else{
      e = a[i];
      count = 1;
    }
  }
  if(count > n/2){
      return 1;
    }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, n) << '\n';
}
