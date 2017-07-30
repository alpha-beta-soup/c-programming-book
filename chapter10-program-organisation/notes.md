# Chapter 10: Program organisation

- [Local variables](#locals)
- [External variables](#globals)
- [Blocks](#blocks) (compound statements containing declarations)
- [Scoping](#scope)
- [Suggested program structure](organising)

## <a name="locals"></a>Local variables

Variables declared in the body of a function are *local* to the function.

Local variables have the following properties:
- **Automatic storage duration** (*extent*): allocated when the function is called, and deallocated when the function returns. Calling a function again is no guarantee that the local variable will still have the old value.
- **Block scope**: visible throughout the function body.

Using `static` in the declaration of a local variable causes it to have **static storage duration**: a permanent storage location so that the value is retained throughout the execution of the program. A static local variable still has block scope, so it's not visible to other functions. It means data can be retained for future calls to a function (e.g. a counter of how many times a function is entered).

```c
void f(void) {
  static int i; // Won't lose its value when f returns
}
```

**Parameters** are essentially local variables; they have the same properties. The only difference between parameters and local variables is that parameters are always initialised just by being assigned values of the arguments in the function call).

## <a name="globals"></a>External variables

External (**global**) variables are variables that are declared outside of the body of any function. Functions can communicate with external variables.

Properties:

- **Static storage duration**
- **File scope**

Examples:
- [`stack.c`](./programs/stack.c) (implementation of a stack using global variables)
- [`guess.c`](./programs/guess.c) ([`guess2.c`](./programs/guess2.c) for a modification avoiding globals)

The usual caveats about global variables apply.

## <a name="blocks"></a>Blocks

Blocks also allow declarations. A function body is a block, so declarations within blocks within functions follow the same rules:
- Automatic storage (allocated and deallocated when the *block* is entered and exited)
- Block scope

This means that the same identifier may have several different meanings within the same function (but never the same block). New declarations temporarily "hide" identifiers that are already visible (due to file scope or because of declaration within a parent block). **At the end of the block, the identifier regains its old meaning.**

## <a name="scope"></a>Scope

The scope of a local variable **doesn't begin until its declaration**. Consider this example:

```c
int i = 1;

void f(void) {
  int j = i;
  int i = 2;
}
```

What is the initial value of `j`?

The declaration of j refers to the *external variable* named `i`, and therefore the initial value of `j` will be 1, and not 2.

```c
int a;

void f(int b) {
  int c;
  // In scope: a, b, c
}

void g(void) {
  int d;
  {
    int e;
    // In scope: a, d, e
  }
  // In scope: a, d
}

main(){
  int f;
  // In scope: a, f
}
```

## <a name="organising"></a>Organising a C Program

1. `#include` directives
2. `#define` directives
3. Type definitions
4. Declarations of external variables
5. prototypes for functions other than `main`
6. Definition of `main`
7. Definitions of other functions

Example: [`poker.c`]((./programs/poker.c))
