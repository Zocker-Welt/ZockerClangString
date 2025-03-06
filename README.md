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
append(myStr, otherStr)    // return: void       arg(s): String*, String*
at(myStr, idx)             // return: char       arg(s): String*, int
slice(myStr, idx1, idx2)   // return: String*    arg(s): String*, int, int
pop(myStr, idx)            // return: String*    arg(s): String*, int
```

# Attributes
```C
myStr->data                // string value
myStr->length              // string length
```

# Notice
maximum length is 2047
```C
free(myStr)                // Be a good human pls
```

# Example
```C
#include "string.c"

int main() {
    String* str = string("Father?.. ");
    printf("%s", str->data);
    append(str, string("Bye."));

    return 0;
}
```
