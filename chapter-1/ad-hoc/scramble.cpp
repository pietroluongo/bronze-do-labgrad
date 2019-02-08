//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=424
#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX_WORD_SIZE 9999

using namespace std;

void reverse(char* string);

void print_word(char* word);

int main() {
    char word[MAX_WORD_SIZE];
    // Clear word
    memset(word, 0, 9999);
    char c;
    int counter = 0;
    while(scanf("%c", &c) == 1) {
        if(c == '\n' || c == ' ') {
            reverse(word);
            print_word(word);
            counter = 0;
            printf("%c", c);
        }
        else {
            word[counter] = c;
            counter++;
        }
    }
    reverse(word);
    print_word(word);
    return 0;
}

// Reverses the string
void reverse(char* string) {
    int len = strlen(string);
    char reversed[len+1];
    memset(reversed, 0, len+1);
    for(int i = 0; i < len; i++) {
        reversed[i] = string[len-i-1];
    }
    strcpy(string, reversed);
}

// Prints the words and clears it
void print_word(char* word) {
    printf("%s", word);
    memset(word, 0, MAX_WORD_SIZE);
}