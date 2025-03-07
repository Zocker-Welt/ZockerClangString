#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 2048

typedef struct String {
    char data[MAX_STRING_LENGTH];
    int length;
} String;

void StringLengthError() {
    fprintf(stderr, "String limit (%d) exceeded\n", MAX_STRING_LENGTH);
    exit(1);
}

void IndexError() {
    fprintf(stderr, "Index out of range\n");
    exit(1);
}

void String_init(String* self, char* data) {
    int length = strlen(data);
    if (length == 0) {
        length = 1;
    }
    self->length = 0;
    self->data[0] = '\0';
    if (!(length > 0 && length < 2048)) StringLengthError;
    strncpy(self->data, data, length);
    self->data[length] = '\0';
    self->length = length;
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

String* plus(String* data1, String* data2) {
    String* result = data1;
    if (!(data1->length + data2->length < 2048)) StringLengthError();
    strncat(result->data, data2->data, data2->length);
    result->length += data2->length;
}

String* mul(String* data1, int n) {
    String* result = empty();
    for (int i = 0; i < n; i++) {
        result = plus(result, data1);
    }
    return result;
}

char at(String* self, int idx) {
    if (idx < 0 || idx >= self->length) IndexError();
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
    if (idx1 < 0 || idx1 > self->length) IndexError();
    if (idx2 < 0 || idx2 > self->length) IndexError();
    if (idx1 > idx2) IndexError();
    String* result = empty();
    for (int i = idx1; i < idx2; i++) {
        result = plus(result, string(char_end(self->data[i])));
    }
    return result;
}

String* pop(String* self, int idx) {
    if (idx < 0 || idx >= self->length) IndexError();
    String* result = empty();
    result = plus(result, slice(self, 0, idx));
    result = plus(result, slice(self, idx + 1, self->length));
    return result;
}

void sprint(String* data) {
    printf("%s", data->data);
}
