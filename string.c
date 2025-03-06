#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String {
    char data[2048];
    int length;
} String;

void String_init(String* self, char* data) {
    int length = strlen(data);
    if (length == 0) {
        length = 1;
    }
    self->length = 0;
    self->data[0] = '\0';
    if (length > 0 && length < 2048) {
        strncpy(self->data, data, length);
        self->data[length] = '\0';
        self->length = length;
    }
    else {
        fprintf(stderr, "String limit (2048) exceeded\n");
    }
}

String* string(char* data) {
    String* self = malloc(sizeof(String));
    String_init(self, data);
    return self;
}

String* empty() {
    String* self = malloc(sizeof(String));
    String_init(self, "");
    return self;
}

void append(String* self, char* data) {
    int length = strlen(data);
    if (self->length + length < 2048) {
        strncat(self->data, data, length);
        self->length += length;
    }
    else {
        fprintf(stderr, "String limit (2048) exceeded\n");
    }
}

char at(String* self, int idx) {
    return self->data[idx];
}

char* char_end(char chr) {
    char* temp = malloc(2 * sizeof(char));
    temp[0] = chr;
    temp[1] = '\0';
    return temp;
}

char* charptr_end(char* _str) {
    char* temp = malloc((strlen(_str) + 1) * sizeof(char));
    strcpy(temp, _str);
    return temp;
}

String* slice(String* self, int idx1, int idx2) {
    String* result = empty();
    for (int i = idx1; i < idx2; i++) {
        append(result, char_end(self->data[i]));
    }
    return result;
}

String* pop(String* self, int idx) {
    String* result = empty();
    append(result, slice(self, 0, idx)->data);
    append(result, slice(self, idx + 1, self->length)->data);
    return result;
}
