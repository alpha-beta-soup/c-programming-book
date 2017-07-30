# Functions

## Syntax

```c
float average(float a, float b) {
  // Computes the average of two numbers
  return (a + b) / 2;
}
```

### Return type
- `float` above
- `void` if the function does not return anything
- **Functions may not return arrays** (but they may return anything else). This is because in C *arguments are passed by value*: when a function is called, each argument is evaluated and its value assigned to the corresponding parameter.
- If the return type is omitted, compilers assume it is `int` (but will probably complain).
- Because C requires that arguments are passed by value, a function cannot return more than one value.

### Parameters
- `a` and `b` above
- Each parameter must have a type
- A function may have no parameters:
  ```c
  void print_pun(void) {
    printf("To C or not to C: that is the question");
  }
  ```
- Changes made to a parameter do not affect the value of an argument (that which is passed into a function call).

### Declarations
- Variables declared within a function body are scoped to within that function body only.

### Bodies
- May be empty:
  ```c
  void do_nothing(void) {}
  ```

### Other
- A call of a void function is a *statement*, so it is followed by a semicolon.
- However a call of a non-void function is an *expression* (but can be used as an *expression statement* just by not assigning or using the return value): `printf("Hello");` or `(void) printf("Hello");` (`printf` returns the number of characters it prints, but here we cast it to void).

## Function declarations (function prototypes)

Functions should be declared before `main`. This can be done in most (but not all) cases by placing the function above the call to `main`. But you can also use a special declaration to do this. Before the `main` definition: `return-type function-name { parameters } ;`, e.g.:

```c
float average(float a, float b); // Declaration (also known as function prototypes)

int main(){
  (void) average(1, 2);
}

float average(float a, float b){ // Definition
  // Function body
}
```

The declaration can use different parameter names to the definition (e.g. longer names than are used by the function itself), although that's pretty gross.

Function declarations can be nested, and he scoping works as you'd expect (local).

### Array arguments

- Arrays can be used as arguments.
- When an argument is a 1D array, the length can be (and is usually) left unspecified:
```c
int f(int a[]) {}
```
  - **But how will the function know how long the array is?** There is no way for the function to determine the length of an array argument. So if a function needs the length, it is supplied as an additional argument:
  ```c
  int sum(int a[], int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++) {
      sum += a[i];
    }
    return sum;
  }
  ```
  - This can actually be exploited to only have the function operate on a subset of an array.
- With a 2D array, only the length of the first dimension may be omitted: the number of columns must be specified. (This means we can't use multidimensional arrays with an arbitrary number of columns. This can be worked around using arrays of pointers.)

### Recursive functions

- Recursion is supported, but is not that common in C.
