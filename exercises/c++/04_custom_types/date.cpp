#include <vector>
#include <iostream>
#include <string>



enum months {Jan=0, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dic};

std::vector<std::string> v_months {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

std::vector<int>days {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31,};


class Date {

private:
    int _day;
    months _month;
    int  _year;


public:

    Date() : _day{1}, _month{Jan}, _year{1} {};

    Date(int day, months month, int year) : _day{day}, _month{month}, _year{year} {};

    int day() const {return _day;}

    std::string month() const {return v_months[_month];}

    int year() const { return _year;}

    void print() {
        std::cout << day() << "/" << month() << "/" << year() << std::endl;
    }

    void add_days(const unsigned int n) {
        int j = n;
        while (j>0){
            _day++;
            if (_day > days[_month]){
                _day = 1;
                if (_month < 12) {
                    _month = months(_month+1);
                }
                else {
                    _month = Jan;
                    _year++;
                }
            }
            j--;
        }

    }

};

bool operator==(const Date& lhs, const Date& rhs){
    if (lhs.day() == rhs.day()){
        if (lhs.month() == rhs.month()) {
            if (lhs.year() == rhs.year()) {
                return true;
            }
        }
    }
    return false;
};


bool operator!=(const Date& lhs, const Date& rhs){
    if (lhs == rhs)
        return false;
    else
        return true;
};

std::ostream& operator<<(std::ostream& os, const Date& d){
    os << d.day() << d.month() << d.year() << std::endl;
};


int main() {
    Date test;
    Date birthday{7,May,1991};
    birthday.print();
    test.print();
    if(test==birthday)
        std::cout << "equal" << std::endl;
    if (test!=birthday)
        std::cout << "different" << std::endl;
    std::cout << birthday;
    std::cout << birthday.day() << birthday.month() << birthday.year() << std::endl;
    test.add_days(3650);
    test.print();
    return 0;
}
