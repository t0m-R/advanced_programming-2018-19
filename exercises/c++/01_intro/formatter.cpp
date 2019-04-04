/*Write a simple text formatter that breaks the lines longer than a given
number of characters. This formatter does not break words and leaves unmodified
 the lines shorter than the given threshold.*/


#include <iostream>
#include <regex>
using namespace std;

string string_formater(character_Length,)

std::string format(size_t width, std::string text)
{
    std::string result;
    while (!text.empty())
    {
        if (width >= text.size())
            return (result += std::regex_replace( text, std::regex( "^\\s+" ), "")) += '\n';

        //Avoid splitting words by checking the value of char at position n
        size_t n = width - 1;
        while (n > width / 2 && isalnum(text[n]) && isalnum(text[n - 1]))
            --n;

        //Trimming left to prettify output
        std::string left_trimmed_text = std::regex_replace( text.substr(0, n), std::regex( "^\\s+" ), "");
        (result += left_trimmed_text) += '\n';
        text.erase(0, n);
    }
    return result;
}

int main()
{
    std::cout << format(25,
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
        "sed do eiusmod tempor incididunt ut labore et dolore magna"
        "aliqua. Ut enim ad minim veniam, quis nostrud exercitation"
        "ullamco laboris nisi ut aliquip ex ea commodo consequat."
        "Duis aute irure dolor in reprehenderit in voluptate velit"
        "esse cillum dolore eu fugiat nulla pariatur. Excepteur"
        "sint occaecat cupidatat non proident, sunt in culpa"
        "qui officia deserunt mollit anim id est laborum.");
    return 0;
}
