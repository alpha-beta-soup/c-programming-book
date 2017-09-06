// Checks if braces are balanced, using a stack defined in global scope

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int Bool;

void stack_overflow(void);
void stack_underflow(void);
void unmatched(void);
void make_empty(void);
Bool is_empty(void);
Bool is_full(void);
void push(char);
int pop(void);

int contents[STACK_SIZE];   // External
int *top_ptr = &contents[0];

int main() {
  char c;
  printf("Enter parentheses and/or braces: ");
  do {
    c = getchar();
    Bool matched = TRUE;
    switch (c) {
      case '{': case '(': case '[': push(c); break;
      case '}': matched = pop() == '{'; break;
      case ')': matched = pop() == '('; break;
      case ']': matched = pop() == '['; break;
    }
    if (!matched) {
      unmatched();
    }
  } while (c != '\n' && c != EOF);
  if (!is_empty()) {
    unmatched();
  }
  printf("Parentheses/braces are nested properly\n");
  exit(EXIT_SUCCESS);
}

void stack_overflow(void) {
  printf("Stack overflow\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void) {
  printf("Stack underflow\n");
  unmatched();
}

void unmatched(void) {
  printf("Parentheses are not nested correctly\n");
  exit(EXIT_FAILURE);
}

void make_empty(void) {
  top_ptr = &contents[0];
}

Bool is_empty(void) {
  return top_ptr == &contents[0];
}

Bool is_full(void) {
  // return top == STACK_SIZE;
  return top_ptr == &contents[STACK_SIZE];
}

void push(char c) {
  if (is_full()) {
    stack_overflow();
  } else {
    *top_ptr++ = c;
  }
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
  }
  return *--top_ptr;
}
