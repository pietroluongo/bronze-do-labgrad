//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=680
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_NAME_SIZE 20
#define SOUNDEX_SIZE 5

char getSoundexChar(char c);

void printFormattedNameAndSoundex(char* name, int name_length, char* soundex);

void clearString(char *string, int size);

int main() {
    printf("         NAME                     SOUNDEX CODE\n");
    char name[MAX_NAME_SIZE];
    clearString(name, MAX_NAME_SIZE);
    while(scanf("%s", name) == 1) {
        int current_position = 0;
        char soundex_output[SOUNDEX_SIZE];
        clearString(soundex_output, SOUNDEX_SIZE);
        // First letter repeats
        soundex_output[0] = name[current_position];
        char last_soundex_char = getSoundexChar(name[current_position]);
        int name_length = strlen(name);
        int soundex_pos = 1;
        while(current_position < name_length) {
            current_position++;
            if(soundex_pos == SOUNDEX_SIZE-1)
                break;
            switch (getSoundexChar(name[current_position])) {
                case '1':
                    if (last_soundex_char == '1')
                        break;
                    last_soundex_char = '1';
                    soundex_output[soundex_pos++] = '1';
                    break;
                case '2':
                    if (last_soundex_char == '2')
                        break;
                    last_soundex_char = '2';
                    soundex_output[soundex_pos++] = '2';
                    break;
                case '3':
                    if (last_soundex_char == '3')
                        break;
                    last_soundex_char = '3';
                    soundex_output[soundex_pos++] = '3';
                    break;
                case '4':
                    if (last_soundex_char == '4')
                        break;
                    last_soundex_char = '4';
                    soundex_output[soundex_pos++] = '4';
                    break;
                case '5':
                    if (last_soundex_char == '5')
                        break;
                    last_soundex_char = '5';
                    soundex_output[soundex_pos++] = '5';
                    break;
                case '6':
                    if (last_soundex_char == '6')
                        break;
                    last_soundex_char = '6';
                    soundex_output[soundex_pos++] = '6';
                    break;
                case -1:
                    last_soundex_char = -1;
                    break;
            }
        }
        for(int i = 0; i < SOUNDEX_SIZE-1; i++) {
            if(soundex_output[i] == 0) {
                soundex_output[i] = '0';
            }
        }
        printFormattedNameAndSoundex(name, name_length, soundex_output);
        clearString(name, MAX_NAME_SIZE);
    }
    printf("                   END OF OUTPUT");
    return 0;
}

void clearString(char *string, int size) {
    memset(string, 0, size);
    return;
}

char getSoundexChar(char c) {
    switch(c) {
        case 'B':
        case 'P':
        case 'F':
        case 'V':
            return '1';
        case 'C':
        case 'S':
        case 'K':
        case 'G':
        case 'J':
        case 'Q':
        case 'X':
        case 'Z':
            return '2';
        case 'D':
        case 'T':
            return '3';
        case 'L':
            return '4';
        case 'M':
        case 'N':
            return '5';
        case 'R':
            return '6';
        default:
            return -1;
    }
}

void printFormattedNameAndSoundex(char* name, int name_length, char* soundex) {
    printf("         ");
    printf("%s", name);
    int padding = 25 - name_length;
    for(int i = 0; i < padding; i++)
        printf(" ");
    printf("%s\n", soundex);
    return;
}