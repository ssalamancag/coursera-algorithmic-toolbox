#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::min;
using std::cout;

int edit_distance(const string &str1, const string &str2) {
  int n = str1.length();
  int m = str2.length();
  //cout<<n<<' '<<m<<"\n\n";
  int a[n + 1][m + 1] = {0};

  for(int i = 0; i <= n; i++){
    a[i][0] = i;
  }
  for(int j = 0; j <= m; j++){
    a[0][j] = j;
  }


  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      int dif = 0;
     // cout<<str1[i-1]<<" "<<str2[j-1]<<'\n';
      if(str1[i-1] != str2[j-1]){
        dif = 1;
      }
      a[i][j] = min(a[i][j-1] + 1, min(a[i-1][j] + 1, a[i-1][j-1] + dif ));
      
    }
  }
  /*
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      cout<<a[i][j]<<' ';
    }
    cout<<'\n';
  }
  */
  return a[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
