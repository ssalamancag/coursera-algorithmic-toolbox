#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int left, int right, int x) {
  int l = left, r = right, middle = 0; 
  if(r >= l){
    middle =  (l + (r - l) / 2);
    //std::cout<<middle<<" "<<a[middle]<<"\n";
    if( x ==  a[middle]){
      return middle;
    }else if (x < a[middle]){
      return binary_search(a, l, middle -1, x);
    }else{
      return binary_search(a, middle + 1, r, x );
    }
  }else{
    return -1;
  }

}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cout << binary_search(a, 0, n -1 , b[i]) << " ";
  }
}
