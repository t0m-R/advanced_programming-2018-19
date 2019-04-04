#include <array>
#include <iostream>


template <std::size_t size>
void print_array(std::array<int, size> &a);


template <std::size_t size>
void transpose(std::array<int, size> &source, std::array<int, size> &dest, std::size_t row, std::size_t col);


int main() {

const std::size_t row{10}, col{10};
std::array<int, row*col> arr1{};
int f{1};
for ( auto &x : arr1 ) {
        x += f;
        f++;
    }
std::array<int, col*row> arr2{};
print_array(arr1);
transpose(arr1, arr2, row, col);
print_array(arr2);
return 0;
}




template <std::size_t size>
void print_array(std::array<int, size> &a) {
    for (auto x : a)
        std::cout << x << " " ;
    std::cout << std::endl;

}

template <std::size_t size>
void transpose(std::array<int, size> &source, std::array<int, size> &dest, std::size_t row, std::size_t col) {
    for (int i=0; i<row; i++)
        for (int j=0;j<col; j++)
            dest[i*col+j] = source[j*row+i];
}
