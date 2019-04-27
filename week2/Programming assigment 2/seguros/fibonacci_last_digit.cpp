#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
long long get_fibonacci_last_digit_fast(long long n){
    
    int criba[n+1];
    criba[0] = 0;
    criba[1] = 1;
    if(n<2){
        return n; 
    }
    for (int i = 2; i <= n; i++){
        criba[i] = (criba[i-1]+criba[i-2])%10;
    }
    
    return criba[n];
}
int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
