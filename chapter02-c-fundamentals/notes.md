# Chapter 2: C Fundamentals

## Compiling and linking

1. **Preprocessing** (obeys directives, which start with `#`: adds and makes changes)
2. **Compiling** (translates into object code (machine instructions))
3. **Linking** (combines object code with other code need to produce an executable program, such as library functions like `printf`)

### GNU C Compiler (GCC)

The `-Wall` option causes `gcc` to check the program more thoroughly.

```sh
gcc -Wall -o pun pun.c
```

---

## Exercises

> Consider the following program:

> ```c
> # include <stdio.h>
>
> int main()
> {
>   printf("Parkison's Law:\nWork expands so as to fill the time\navailable for its completion.\n");
>   return 0;
> }
> ```

The directives are the lines beginning with `#` (i.e. `#include <stdio.h>`).

The statements are everything inside the `main` function (they end with `;`).

---

`dweight3.c` condenses `dweight.c` by replace the assignments with initialisers, and calculating a value when it is used rather than first assigning it to a variable.

---

`volume.c`

When the fraction 4/3 is written as `4.0/3.0` floating point division is performed (result is 1.333...).

When the fraction 4/3 is written as `4/3` integer division is performed (result is 1).

---

`no-init.c`

Three variables are declared but not initialised. They seem to be initialised automatically to 0 by the compiler. (The book suggests they should be apparently random values.)

---

### Illegal C identifiers:

- `100_bottles` - illegal because it begins with a number
- `_100_bottles` - legal
- `one_hundred_bottles` - legal
- `bottles_by_the_hundred` - legal

---

### Keywords

- `for` - yes
- `If` - no (but `if` is)
- `main` - no
- `printf` - no
- `while`- yes

---

### Tokens

The statement `a=(3*q-p*p)/3;` has 14 tokens (every character in this case). However if any of the identifiers (`a`, `q`, or `p`) were more than one character long, there would still be 14 tokens. (A token is not a character).

This would be easier to read as `a = (3 * q - p * p) / 3;`, however the white space has no semantic meaning.
