#include <iostream>
#include "reverse_array.h"



int main() {
    int n, *ia;
    double *da;
    std::cout << "Enter array size: ";

    std::cin >> n;
    ia = new_array<int>(n);
    da = new_array<double>(n);
    reverse_print(ia,n);
    reverse_print(da,n);
    delete [] ia;
    delete [] da;

    return 0;


}



template <typename T>
T* new_array(const int n){
    T* arr{new T[n]};
    std::cout << "Insert array elements" << std::endl;
    for (int i{0}; i <n; i++)
        std::cin >> arr[i];
    std::cout << "Insertion done." << std::endl;
    return arr;
}


template <typename T>
void reverse_print(T* arr, int size){
    for (int i{size-1}; i>=0; i--)
        std::cout << i << ": " << arr[i] << std::endl;
}
