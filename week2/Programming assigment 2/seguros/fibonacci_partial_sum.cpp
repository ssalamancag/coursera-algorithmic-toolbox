#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
long long fibonacci_fast(long long n) {
    int criba[n+1];
    criba[0] = 0;
    criba[1] = 1;
    for (int i = 2; i <= n; i++){
        criba[i] = criba[i-1]+criba[i-2];
    }
    return criba[n];
}

int getSumFibonacci(long long m, long long n){
    int start = ((m + 1) % 60);
    int end = ((n + 2) % 60);
    if(m == n) return fibonacci_fast(n)%10;
    
    return ( fibonacci_fast(end) - fibonacci_fast(start))%10;
}
int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << getSumFibonacci(from, to) << '\n';
}
