#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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
    for (long long  i = 2; i <= n; i++){
        criba[i] = (criba[i-1]+criba[i-2])%10;
    }
    
    return criba[n];
}
long long int getFibonacci(long long  n){
    long pisano = 60;
    long  index = n%pisano;
   // printf("%d, %ld \n", pisano, index);
    long  criba[index + 1];
    criba[0] = 0;
    criba[1] = 1;
    for (long i = 2; i <= index; i++){
        criba[i] = (criba[i-1] + criba[i-2]) % 10;
    }
    //printf("%ld \n", criba[index]);
    return criba[index];

}

int getSumFibonacci(long long n){
    int fn = getFibonacci(n);
    int next = getFibonacci(n+1);
    return (fn * next) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << getSumFibonacci(n);
}
