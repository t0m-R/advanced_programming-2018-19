#include <iostream>
#include <cmath>
#include "primes.h"

int * get_primes(int n) {
    int * primes{new int[n]};
    primes[0] = 2;
    int e{0};
    for ( int i{3}; e < n; i++) {
        if (is_prime(i)){
            primes[e] = i;
            e++;
        }
    }
    return primes;
}

bool is_prime(const int n){
    for (int i=2; i<n; i++){
        if (n%i==0) {return false;}
    }
    return true;
}

void sieve(int n) {
    bool * ia {new bool[n]};
    for (int i{0}; i<n; i++)
    { ia[i] = true; };
    for (int s{2}; s<std::sqrt(n); s++){
        if (ia[s-2]){
            for (int j{s*s}; j<n; j+=s){
                ia[j-2] = false;
            }
        }
    }
    for (int i{0}; i<=n-2; i++){
        if (ia[i]){
            std::cout << i+2 << std::endl;
        }
    }
}



int main() {
    int * primes = get_primes(100);
    for (int i=0; i<100; i++)
    { std::cout << primes[i] << std::endl;}
    delete [] primes;
    int n;
    std::cout << "Enter primes treshold: ";
    std::cin >> n;
    sieve(n);
    return 0;
}
