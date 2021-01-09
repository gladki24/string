//
// Created by Seweryn on 24.12.2020.
//

#include "flowerpot_string.h"

#define UP_A_ASCII_CODE 65
#define UP_Z_ASCII_CODE 90
#define LOW_A_ASCII_CODE 97
#define LOW_Z_ASCII_CODE 122

#define UPPERCASE_LOWERCASE_ASCII_POSITION 32;

f_string construct_f_string(c_string string) {
    unsigned int size = strlen(string);
    f_string newString = {
            .size = size,
            .value = malloc((size + 1) * sizeof(char))
    };

    for (unsigned int index = 0; index <= newString.size; index++) {
        newString.value[index] = string[index];
    }

    return newString;
}

void destruct_f_string(f_string* string) {
    free(string->value);
}

f_string copy_f_string(const f_string string) {
    return construct_f_string(string.value);
}

void left_trim(f_string* string) {
    unsigned int leftSideWhiteSpaces = 0;
    for (unsigned int index = 0; index < string->size; index++) {
        if (isspace(string->value[index])) {
            leftSideWhiteSpaces++;
        } else {
            break;
        }
    }

    if (leftSideWhiteSpaces == 0) {
        return;
    }

    char* value = malloc((string->size + 1) - leftSideWhiteSpaces);
    int i = 0;
    for (unsigned int index = leftSideWhiteSpaces; index <= string->size; index++) {
        value[i] = string->value[index];
        i++;
    }

    free(string->value);
    string->value = value;
    string->size = i - 1;
}

void right_trim(f_string* string) {
    int rightSideWhiteSpaces = 0;
    for (unsigned int index = string->size; index >= 0; index--) {
        if (isspace(string->value[index])) {
            rightSideWhiteSpaces++;
        } else if (string->value[index] != '\0') {
            break;
        }
    }

    if (rightSideWhiteSpaces == 0) {
        return;
    }

    c_string value = malloc((string->size + 1) - rightSideWhiteSpaces);
    for (unsigned int index = 0; index <= string->size - rightSideWhiteSpaces; index++) {
        value[index] = string->value[index];
    }
    string->size -= rightSideWhiteSpaces;
    value[string->size] = '\0';

    free(string->value);
    string->value = value;
}

void trim(f_string* string) {
    left_trim(string);
    right_trim(string);
}

void to_lower_case(f_string* string) {
    for (unsigned int index = 0; index < string->size; index++) {
        if (string->value[index] >= UP_A_ASCII_CODE && string->value[index] <= UP_Z_ASCII_CODE) {
            string->value[index] += UPPERCASE_LOWERCASE_ASCII_POSITION;
        }
    }
}

void to_upper_case(f_string* string) {
    for (unsigned int index = 0; index < string->size; index++) {
        if (string->value[index] >= LOW_A_ASCII_CODE && string->value[index] <= LOW_Z_ASCII_CODE) {
            string->value[index] -= UPPERCASE_LOWERCASE_ASCII_POSITION;
        }
    }
}

void reverse(f_string* string) {
    c_string value = malloc((string->size + 1) * sizeof(char));

    unsigned int i = string->size - 1;
    for (unsigned int index = 0; index < string->size; index++) {
        value[i] = string->value[index];
        i--;
    }

    value[string->size] = '\0';
    free(string->value);
    string->value = value;
}