# The Basics

Include the string file
```c
#include "string.c"
```
Create an empty string
```c
#include "string.c"

int main() {
    String* myStr = empty();

    return 0;
}
```

# Functions
```c
empty();                   // return: String*    arg(s): void
string(myText);            // return: String*    arg(s): char*
at(myStr, idx)             // return: char*      arg(s): String*, int
slice(myStr, idx1, idx2)   // return: String*    arg(s): String*, int, int
pop(myStr, idx)            // return: String*    arg(s): String*, int
plus(myStr, otherStr)      // return String*     arg(s): String*, String*
mul(myStr, myNum)          // return String*     arg(s): String*, int
sprint(myStr)              // return: void       arg(s): String*
```

# Attributes
```c
myStr->data                // string value
myStr->length              // string length
```

# Notice
maximum length is 2047
```c
free(myStr)                // Be a good human pls
```

# Example
at() function
```c
#include "string.c"

#define String String*
#define str string

int main() {
    String a = str("Hello!");

    at(a, 0) = 's'; // sello!
    char c = at(a, 0); // s

    sprint(a);
    printf("\n%c", c);

    free(a);

    return 0;
}
```
