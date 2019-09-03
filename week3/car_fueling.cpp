#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int mOriginal = tank;
    int prev = 0, c = 0, rf = 0;
    for(int i = 0; i < stops.size(); i++){
        if((stops[i] - c) <= tank ){
            tank -= (stops[i] - c);
            prev = i;
            c = stops[i];
        }else{
            if((stops[i] - stops[prev]) > mOriginal){
                return -1;
            }
            tank = mOriginal - (stops[i] - stops[prev]);
            rf++;
            prev = i;
            c = stops[i];
        }
    }
    if(dist - c <= tank){
        return rf;
    }else{
        if(dist - stops[prev] > mOriginal){
            return -1;
        }else{
            return (rf + 1 );
        }


    }

}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
