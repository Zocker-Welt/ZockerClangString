# The Basics

Include the string file
```c
#include "string.c"
```
Create an empty string
```c
#include "string.c"

int main() {
    String s = empty();

    return 0;
}
```

# Functions
```c
str(myText)                   // return: String      arg(s): char*
empty()                       // return: String      arg(S): void
concat(myStr, otherStr)       // return: String      arg(s): String, String
slice(myStr, idx1, idx2)      // return: String      arg(s): String, size_t, size_t
at(myStr, idx)                // return: char*       arg(s): String, int
compare(myStr, otherStr)      // return: int         arg(s): String, String
sprint(myStr)                 // return: void        arg(s): String
free_string(myStr)            // return: void        arg(s): String
```

# Notice
```c
#include "string.c"

int main() {
    String s = str("Hello, world!");

    // To get/set a char in a String to something you can use at
    at(s, 0) = 'S';
    char chr = at(s, 0);

    // But you can also do it like this
    s.data[0] = 'H';
    chr = s.data[0];

    free_string(&s);

    return 0;
}
```
