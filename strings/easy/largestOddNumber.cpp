#include<iostream>
#include<string>
using namespace std;

// stoi() is used to conver string -> int, it will automatically handle leading spaces and +/- signs

// to_string() is used to convert int -> string

/**
 * Start from end -> if any odd num encountered from last is will make the entire num largest
 */
string largestOddNumber(string num) {
    for(int i = num.size() - 1; i >= 0; i--) {
        if((num[i] - '0') % 2 == 1) {
            return num.substr(0, i + 1);
        }
    }

    return "";
}

int main() {
    string num = "354710";
    cout << largestOddNumber(num);
}