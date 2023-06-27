#include <stdio.h>
#include <string.h>

void reverseString(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseWords(char* str) {
    int length = strlen(str);
    int start = 0;
    int end = 0;

    while (end <= length) {
        if (str[end] == ' ' || str[end] == '\0') {
            reverseString(str, start, end - 1);
            start = end + 1;
        }
        end++;
    }

    reverseString(str, 0, length - 1);
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    reverseWords(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
