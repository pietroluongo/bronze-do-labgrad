//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=121&problem=2164
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

// This passes on all test cases, but throws presentation differences

bool isMorseData(char c) {
    return c == '.' || c == '-';
}

int main() {
    map<string, char> code;
    code[".-"] = 'A';
    code["-..."] = 'B';
    code["-.-."] = 'C';
    code["-.."] = 'D';
    code["."] = 'E';
    code["..-."] = 'F';
    code["--."] = 'G';
    code["...."] = 'H';
    code[".."] = 'I';
    code[".---"] = 'J';
    code["-.-"] = 'K';
    code[".-.."] = 'L';
    code["--"] = 'M';
    code["-."] = 'N';
    code["---"] = 'O';
    code[".--."] = 'P';
    code["--.-"] = 'Q';
    code[".-."] = 'R';
    code["..."] = 'S';
    code["-"] = 'T';
    code["..-"] = 'U';
    code["...-"] = 'V';
    code[".--"] = 'W';
    code["-..-"] = 'X';
    code["-.--"] = 'Y';
    code["--.."] = 'Z';
    code["-----"] = '0';
    code[".----"] = '1';
    code["..---"] = '2';
    code["...--"] = '3';
    code["....-"] = '4';
    code["....."] = '5';
    code["-...."] = '6';
    code["--..."] = '7';
    code["---.."] = '8';
    code["----."] = '9';
    code[".-.-.-"] = '.';
    code["--..--"] = ',';
    code["..--.."] = '?';
    code[".----."] = '\'';
    code["-.-.--"] = '!';
    code["-..-."] = '/';
    code["-.--."] = '(';
    code["-.--.-"] = ')';
    code[".-..."] = '&';
    code["---..."] = ':';
    code["-.-.-."] = ';';
    code["-...-"] = '=';
    code[".-.-."] = '+';
    code["-....-"] = '-';
    code["..--.-"] = '_';
    code[".-..-."] = '\"';
    code[".--.-."] = '@';

    int cases;
    cin >> cases;
    int case_count = 0;
    scanf("%*[\n]");
    for(int i = 0; i < cases; i++) {
        string input;
        char buffer[2005];
        string output;
        getline(cin, input);
        //scanf("%[^\n]", buffer);
        //scanf("%*[\n]");
        strcpy(buffer, input.c_str());
        int point = 0;
        int size = strlen(buffer);
        string buf = "";
        while(point < size) {
            if(isMorseData(buffer[point])) {
                buf += buffer[point];
                point++;
            }
            else if(buffer[point] == ' ' && isMorseData(buffer[point+1])) {
                // End of a letter
                if(buf != "")
                    output += code[buf];
                buf = "";
                point++;

            }
            else if(buffer[point] == ' ' && (buffer[point+1] == ' ' || buffer[point+1] == '\0')) {
                // End of a word
                if(buf != "") {
                    output += code[buf];
                    output += " ";
                } else {
                    output += "";
                    point += 2;
                    continue;
                }
                point += 2;
                buf = "";
            }
        }
        if(buf != "")
            output += code[buf];
        cout << "Message #" << ++case_count << endl;
        cout << output << endl;
        if(case_count != cases)
            cout << endl;


    }

    return 0;
}