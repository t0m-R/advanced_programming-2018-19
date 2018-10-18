#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {
  int a{8}, b{7};
  int* pi{&a};

  const int* pc = &a;
  // *pc = 7; 	// error
  a = 15;  // I can obviously change a

  int* const cp = &a;
  a = b;
  *cp = 33;
  // cp = &b;   // error

  const int* const cpc = &a;  // points to a fixed memory location
  // and cannot change it
  // *cpc = 0;  // error
  // cpc = &n;  // error
  a = 99;

  int aa[4]{};
  print_sentinel(aa, 4);

  return 0;
}

template <typename T>
void print_sentinel(const T* a, const std::size_t l) {
  const T* const end{a + l};
  for (; a != end; ++a)
    std::cout << *a << std::endl;
}


#read variable from right to left to avoid confusion ( like pc (pointer to int const) and cp ( const pointer to int)
#sentinel: pointer to first element past array_size
# a[i] == *(a+i)

