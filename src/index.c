#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Key {
    char value[100];
};
struct Value {
    char value[200];
};

struct Key keys[100];
struct Value values[100];
int global_key_i = 0;
int global_val_i = 0;

int get_key_index_on_array(char key[100]) {
    for (int i = 0; i < global_key_i; i++) {
        if (strcmp(keys[i].value, key) == 0) {
            return i;
            break;
        }
    }
    return -1;
}

int get_value_index_on_array(char value[100]) {
    for (int i = 0; i < global_val_i; i++) {
        if (strcmp(values[i].value, value) == 0) {
            return i;
            break;
        }
    }
    return -1;
}

void get_config_keys() {
    char *configCodes = malloc(sizeof(char) * 1000);

    FILE * file = fopen("build.lake", "r");
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
            strcpy(keys[global_key_i].value, key_val);global_key_i++;
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

void get_config_values() {
    char *configCodes = malloc(sizeof(char) * 1000);

    FILE * file = fopen("build.lake", "r");
    int i =0;
    int key_i = 0;
    char key_val[100];
    int temp = 0;
    char ch;
    while((ch = fgetc(file)) != EOF) {
        if(ch == '<') {
            temp = 1;
            key_val[0] = '\0';
            key_i = 0;
            continue;
        }

        if(ch == '>') {
            key_val[key_i] = '\0';
            // printf("%s\n", key_val);
            struct Value value1;
            strcpy(value1.value, key_val);
            values[global_val_i] = value1;
            global_val_i++;
            temp = 0;
            continue;
        }
        if (temp == 1) {
            key_val[key_i++] = ch;
        }
    }
}

int main(int argc, char const *argv[])
{  
    get_config_keys();
    get_config_values();
    // printf("%d", get_key_index_on_array("clear"));
    // printf("%d", get_value_index_on_array("rm bin/app"));

    if(argv[1]) {
        for(int i = 0;i < (sizeof(keys) / sizeof(keys[0]));i++) {
            if(strcmp(argv[1], keys[i].value) == 0) {
                system(values[i].value);
            }
        }
    }
    return 0;
}