//
// Created by Seweryn on 24.12.2020.
//

#ifndef STRING_FLOWERPOT_STRING_H

#include <stdio.h> // TODO remove
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define STRING_FLOWERPOT_STRING_H

/**
 * standard c-style string
 */
typedef char *c_string;

/**
 * opaque for c-style string
 */
typedef struct f_string {
    c_string value;
    unsigned int size;
} f_string;

/**
 * construct f_string structure
 * @return f_string
 */
f_string construct_f_string(c_string);

/**
 * free member of f_string structure
 */
void destruct_f_string(f_string*);

/**
 * make deep copy of f_string
 * @return copy of f_string
 */
f_string copy_f_string(f_string);

/**
 * remove whitespaces from left side of string
 * @param string string to modify
 */
void left_trim(f_string* string);

/**
 * remove whitespaces from right side of string
 * @param string string to modify
 */
void right_trim(f_string* string);

/**
 * remove whitespaces from left and right sides of string
 */
 void trim(f_string* string);

 /**
  * transform string chars to lower case
  * @param string to transform
  */
 void to_lower_case(f_string* string);

 /**
  * transform string chars to upper case
  * @param string to transform
  */
 void to_upper_case(f_string* string);

 /**
  * reverse chars order
  * @param string to transfer
  */
 void reverse(f_string* string);

#endif //STRING_FLOWERPOT_STRING_H
