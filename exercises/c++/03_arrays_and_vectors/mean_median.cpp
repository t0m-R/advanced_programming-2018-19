#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>



int main() {

    std::vector<double> temps;
    std::ifstream infile("temperatures.txt");
    double temp;
    while (infile>>temp){
        temps.push_back(temp);
    }
    std::sort( temps.begin(), temps.end() );
    double median, mean;
    int length = temps.size();
    if (length%2 == 0) {
        median = temps[(length/2)-1];
    }
    else {
        median =temps[length/2];
    }
    for ( auto x : temps)
        mean += x;
    mean = mean / length;
    std::cout << "Median: " << median << " " << "Mean: " << mean << std::endl;
}
