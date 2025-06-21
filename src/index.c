#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *soz = "[install] = `gcc main.c -o bin/app`\n[clear] = `rm bin/app`";

struct Line {
    char key[100];
    char command[300];
};

struct Line lines[100];

int main(int argc, char const *argv[])
{
    int i =0;
    int key_i = 0;
    char key_val[100];
    int temp = 0;
    while(soz[i] != '\0') {
        if(soz[i] == '[') {
            temp = 1;
            key_i = 0;
            i++;
            continue;
        }

        if(soz[i] == ']') {
            key_val[key_i] = '\0';
            temp = 0;
            i++;
            continue;
        }
        if (temp == 1) {
            key_val[key_i++] = soz[i];
        }
        i++;
    }
    return 0;
}
