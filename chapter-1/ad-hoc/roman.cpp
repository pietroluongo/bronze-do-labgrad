//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=121&problem=2663
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

bool isLetter(char c);

int convertToArabic(string input);
string convertToRoman(string input);

int main() {
    char input[99];
    while(scanf("%s", input) == 1) {
        if(isLetter(input[0]))
            cout << convertToArabic(input) << endl;
        else
            cout << convertToRoman(input) << endl;
    }
    return 0;
}

// Only on uppercase
bool isLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

int convertToArabic(string input) {
    map<char, int> conversion_values;
    conversion_values['M'] = 1000;
    conversion_values['D'] = 500;
    conversion_values['C'] = 100;
    conversion_values['L'] = 50;
    conversion_values['X'] = 10;
    conversion_values['V'] = 5;
    conversion_values['I'] = 1;

    int output = 0;
    for(int i = 0; i < input.length(); i++) {
        char current_char = input.at(i);
        if(i+1 == input.length()) {
            output += conversion_values[current_char];
            break;
        }
        char next_char = input.at(i+1);
        if(conversion_values[current_char] < conversion_values[next_char]) {
            output = output + conversion_values[next_char] - conversion_values[current_char];
            i++;
        }
        else {
            output += conversion_values[current_char];
        }
    }
    return output;
}

string convertToRoman(string input) {
    int num = stoi(input);
    const vector<string> conv_str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const vector<int> conv_int = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string output = "";
    while(num > 0) {
        for(int i = 0; i < conv_int.size(); i++) {
            if(num >= conv_int[i]) {
                int q = num / conv_int[i];
                num = num % conv_int[i];
                for(int j = 0; j < q; j++) {
                    output += conv_str[i];
                }
            }
        }
    }
    return output;
}