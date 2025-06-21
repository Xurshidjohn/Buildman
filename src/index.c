#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *soz = "";

struct Line {
    char key[100];
    char command[300];
};


void get_config_keys() {
    char *configCodes = malloc(sizeof(char) * 1000);

    FILE * file = fopen("build.config", "r");
    int i =0;
    int key_i = 0;
    char key_val[100];
    int temp = 0;
    char ch;
    while((ch = fgetc(file)) != EOF) {
        if(ch == '[') {
            temp = 1;
            key_val[0] = '\0';
            key_i = 0;
            i++;
            continue;
        }

        if(ch == ']') {
            key_val[key_i] = '\0';
            printf("%s\n", key_val);
            key_val[0] = '\0';
            temp = 0;
            i++;
            continue;
        }
        if (temp == 1) {
            key_val[key_i++] = ch;
        }
        i++;
    }
}

struct Line lines[100];

int main(int argc, char const *argv[])
{  
    get_config_keys();
    return 0;
}