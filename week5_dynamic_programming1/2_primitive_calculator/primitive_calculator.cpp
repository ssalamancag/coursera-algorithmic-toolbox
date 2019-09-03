#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  int a[n+1];
 /* while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  */
  //if(n == 1) sequence.push_back(1);
  a[1] = 0;
  for(int i = 2; i <= n; i++){
    int v = 0;
    if( i % 2 == 0 && i % 3 == 0){
      a[i] = min( a[i / 2], a[i / 3]) + 1;
     // v = (a[i] == a[i / 3])? i/3 : i/2;
      //sequence.push_back(v);
    }else if(i % 3 == 0){
      a[i] = min( a[i - 1], a[i / 3]) + 1;
      //v = (a[i] == a[i / 3])? i/3 : i-1;
      //sequence.push_back(v);
    }else if(i % 2 == 0){
      a[i] = min( a[i - 1], a[i / 2]) + 1;
     // v = (a[i] == a[i / 2])? i/2 : i-1;
      //sequence.push_back(v);
    }else{
      a[i] = a[i - 1] + 1;
      //sequence.push_back(i - 1);      
    }
  }
  int v = 0;
  while(n>=1){
    sequence.push_back(n);
    if( n % 2 == 0 && n % 3 == 0 ){
      n = (a[n/2]<a[n/3])? n/2:n/3;
    }else if(n %3 ==0){
      n = (a[n/3]< a[n-1])? n/3:n-1;
    }else if( n  % 2 == 0){
      n = (a[n/2]< a[n-1] )?n/2:n-1;
    }else{
      n = n-1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
