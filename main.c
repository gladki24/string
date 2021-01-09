#include <stdio.h>
#include "flowerpot_string.h"

// TODO Delete
int main() {
    f_string string1 = construct_f_string("ewA");
    reverse(&string1);
    printf("%s", string1.value);

    return 0;
}
