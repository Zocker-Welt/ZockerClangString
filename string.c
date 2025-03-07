#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define at *String_at
#define S(...) str(__VA_ARGS__)

typedef struct {
    char* data;
    size_t length;
} String;

String str(char* s) {
    String new_str;
    new_str.length = strlen(s);
    new_str.data = malloc(new_str.length + 1);
    strcpy(new_str.data, s);
    return new_str;
}

String empty() {
    String new_str;
    new_str.length = 0;
    new_str.data = malloc(1);
    new_str.data[0] = '\0';
    return new_str;
}

void sprint(String s) {
    printf("%s\n", s.data);
}

void free_string(String* s) {
    free(s->data);
    s->data = NULL;
    s->length = 0;
}

String concat(String s1, String s2) {
    String new_str;
    new_str.length = s1.length + s2.length;
    new_str.data = malloc(new_str.length + 1);
    strcpy(new_str.data, s1.data);
    strcat(new_str.data, s2.data);
    return new_str;
}

String slice(String s, size_t start, size_t end) {
    if (start > s.length || end > s.length || start > end) {
        String new_str;
        new_str.length = 0;
        new_str.data = malloc(1);
        new_str.data[0] = '\0';
        return new_str;
    }

    String new_str;
    new_str.length = end - start;
    new_str.data = malloc(new_str.length + 1);
    strncpy(new_str.data, s.data + start, new_str.length);
    new_str.data[new_str.length] = '\0';
    return new_str;
}

char* String_at(String s, int index) {
    if (index < 0 || (size_t)index >= s.length) return NULL;
    return s.data + (size_t)index;
}

int compare(String s1, String s2) {
    return strcmp(s1.data, s2.data);
}
