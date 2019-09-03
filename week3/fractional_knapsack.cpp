#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <tuple>


using namespace std;

bool compareTuple(tuple<double, double> t1, tuple<double, double> t2){
  return get<0>(t2) < get<0>(t1);
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  // value = 0.0;
  double n = 0.0;
  double w = capacity;
  vector<tuple<double, double>> priceUnity(weights.size());

  for(int i = 0; i < weights.size(); i++){
    get<1>(priceUnity[i]) = weights[i];
    get<0>(priceUnity[i]) = (double) values[i]/weights[i];
  }
  //cout<<priceUnity<<"\n";
  sort(priceUnity.begin(), priceUnity.end(), compareTuple);
  int i = 0;
  while (w > 0 && (i != weights.size() )){
    //("w = %f ,Elemento %d, PU %f, cantidad %f\n",w ,i , get<0>(priceUnity[i]), get<1>(priceUnity[i]));
    if(get<1>(priceUnity[i]) <= w &&  get<1>(priceUnity[i])>0 ){
      //printf("Primer caso\n");
      n += (get<0>(priceUnity[i]) * get<1>(priceUnity[i]));
      w -= ( get<1>(priceUnity[i]));
      get<1>(priceUnity[i]) = 0;
    }else{
      //printf("segundo caso, n %f \n", get<0>(priceUnity[i]) * w);
      n += (get<0>(priceUnity[i]) * w);
      //printf("segundo n %f \n", n);
      w = 0;
      get<1>(priceUnity[i]) -= w;
    }
    //printf("Nuevo w = %f\n", w);
    i++;
  }
 // printf("n final %f", n);
  return n;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  printf("%.4f\n",optimal_value);
  return 0;
}
