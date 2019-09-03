#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::max;

int optimal_weight(int W, const vector<int> &w) {
  int n = w.size();
  //int values[n+1][W+1];
  vector<vector<int>>  values(n + 1,vector<int>(W + 1));
  for(int i=0; i<=n; i++){
    for(int j=0; j<=W; j++){
      if(i == 0 || j == 0){
        values[i][j] =0;
      }else{
          values[i][j] = values[i-1][j-1];
        if(w[i-1] <= j){
          values[i][j] = max(values[i-1][j],values[i-1][j-w[i-1]]+w[i-1]);
        }else{
          values[i][j] = values[i-1][j];
        }
      }
    }
  }
  return values[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
