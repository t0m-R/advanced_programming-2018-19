#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

void print_no_reps(std::vector<std::string> words){
    std::sort( words.begin(), words.end());
    std::cout<< words.at(0)<<std::endl;
    for (int i=1; i< words.size(); i++){
        if (words.at(i).compare(words.at(i-1)))
            std::cout << words.at(i) << std::endl;
        }
    }

int main() {
    std::string word;
    std::vector<std::string> words;
    std::cout << "Enter sequence of repeated words: " << std::endl;
    while(std::cin >> word)
        words.push_back(word);
    print_no_reps(words);
    return 0;
}
