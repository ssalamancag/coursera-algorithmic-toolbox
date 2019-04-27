#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current);
        sum += current;
    }

    return sum % 10;
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

int getSumFibonacci(long long n){
    int last = get_fibonacci_last_digit_fast((n + 2) % 60);
    if(last == 0 ){
        return 9;
    }else{
        return last- 1;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
    std::cout << getSumFibonacci(n);
}
