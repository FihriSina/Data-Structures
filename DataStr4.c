#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int top = -1;
char stack[MAX_SIZE][MAX_SIZE];

void push(const char *tag) {
    if (top >= MAX_SIZE - 1) {
        exit(1); // Stack overflow
    }
    strcpy(stack[++top], tag);
}

char* pop() {
    if (top < 0) {
        exit(1); // Stack underflow
    }
    return stack[top--];
}

bool is_opening_tag(const char *tag) {
    return tag[0] == '<' && tag[1] != '/';
}

bool is_closing_tag(const char *tag) {
    return tag[0] == '<' && tag[1] == '/';
}

bool match_tags(const char *open, const char *close) {
    // Compare tags while ignoring '/' in closing tag
    return strcmp(open + 1, close + 2) == 0;
}

void check_html_code(const char *html_code) {
    char tag[MAX_SIZE];
    int i = 0;
    while (html_code[i] != '\0') {
        if (html_code[i] == '<') {
            int j = 0;
            while (html_code[i] != '>' && html_code[i] != '\0') {
                tag[j++] = html_code[i++];
            }
            if (html_code[i] == '>') {
                tag[j++] = html_code[i++];
                tag[j] = '\0';
                if (is_opening_tag(tag)) {
                    push(tag);
                } else if (is_closing_tag(tag)) {
                    if (top == -1) {
                        printf("error %s\n", tag);
                        return;
                    }
                    char *open_tag = pop();
                    if (!match_tags(open_tag, tag)) {
                        printf("error %s\n", tag);
                        return;
                    }
                }
            }
        } else {
            i++;
        }
    }
    if (top != -1) {
        printf("error %s\n", stack[top]);
    } else {
        printf("correct\n");
    }
}

int main() {
    char html_code[1000];
    fgets(html_code, sizeof(html_code), stdin);
    // Remove the newline character from the input
    html_code[strcspn(html_code, "\n")] = '\0';
    check_html_code(html_code);
    return 0;
}
