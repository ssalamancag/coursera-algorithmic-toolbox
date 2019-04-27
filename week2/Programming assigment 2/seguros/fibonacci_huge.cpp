#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
int pisanoPeriod(long long m){
    int a = 0, b = 1;
    int c = a+b, i = 0;
    while(true){
        a = b;
        b = c;
        i++;
        if(a == 0 && b == 1){
            return i;
        }
        c = (a + b)%m; 
    }
    return -1;
}
long long int getFibonacci(long long  n, long long  m){
    long pisano = pisanoPeriod(m);
    long  index = n%pisano;
   // printf("%d, %ld \n", pisano, index);
    long  criba[index + 1];
    criba[0] = 0;
    criba[1] = 1;
    for (long i = 2; i <= index; i++){
        criba[i] = (criba[i-1]+criba[i-2])%m;
    }
    //printf("%ld \n", criba[index]);
    return criba[index];

}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    //std::cout<<pisanoPeriod	(10);
    printf("%ld", getFibonacci(n,m));
   // std::cout << pisanoPeriod(m);
    
}
