# Chapter 7: Basic types

C's basic (built-in) types:

- `int`: long, short, signed, unsigned
- `float`: double, long double
- `char`

`typedef` can be used to define new types.

## Integer types

Whole numbers, that can either be *signed* or *unsigned*.

Integers are typically stored in either 16 bits or 32 bits. A signed integer will use the left-most  bit (the **sign bit**) to store 0 (positive) or 1 (negative). Therefore the largest 16-bit signed integer is 0111111111111111 in binary (32,767 or 2^15 - 1). Similarly for 32 bit: 2,147,483,647 (2^31 - 1).

A signed integer is the default.

An integer can be either short or long; the default is unspecified depends on the machine.

Specifiers can be combined (E.g. `long unsigned int`), and the order does not matter, and the word `int` is optional.

Macros that define the smallest and largest values of various integer types can be found in `<limits.h>` header, part of the standard library.

Don't use long integers indiscriminately, as it may take more time to operate with them than for smaller integers.

### Integer constants

Integers can be written in decimal (base 10), octal (base 8), or hexadecimal (base 16). This does not affect the way numbers are stored (Which is always binary). Octal numbers must begin with a `0`, and hexadecimal must begin with `0x`.

The compiler will treat integer constants as an ordinary integer if it falls within the rang eof the `int` type, and as a long integer otherwise. To force the compiler to see a long integer, just use the letter `L` or `l`: `15L`, `0377L`, `0x7fffL`. Similarly, use a `U` or `u` to indicate unsigned. These can both be used.

Note that calls to `scanf` and `printf` may need to change conversion specifiers to handle the different type (e.g. `%u`, `%o`, `%o`, `%x`). The prefix `h` can be used to read or write a short integer (e.g. `%hd`), and `l` for long integers.

## Floating types

There are three floating types, according to the precision.

- float (suitable when the amount of precision isn't critical, e.g. temperature to 1 decimal place)
- double (greater precision -- enough for most; the default)
- long double (rarely used)

Each floating-point value stores information in three parts: the sign, an exponent, and a fraction. The number of bits reserved for the exponents determines how large or small numbers can be, and the number of bits in the fraction determines the precision.

The format specifiers for reading and writing floating-point numbers are `%e`, `%f`, and `%g`. A `l` prefix must be used for reading double (e.g. `%lf`).

## Character types

`char`

Character sets: ASCII (7- or 8-bit), EBCDIC, and Unicode (16-bit — 65,536 characters can be represented)

Character constants are enclosed in single-quotes, not double-quotes.

They key to working with character types is to understand that C treats characters as small integers. For example, ASCII character codes range from 0000000 to 1111111 (0 to 127 in binary). 'a' is 97, and 'A is 65'.

When a character appears in a computation, **C simple uses the integer value**. Therefore, this snippet can be used to convert lower-case characters into upper-case:

```c
if ('a' <= ch && ch <= 'z') {
  ch = ch - 'a' + 'A';
}
```

*Note that this kind of code is brittle and may not be portable, as it depends on the machine-dependent character set being used.*

So generally it's much better to rely on the standard library:

```c
#include <ctype.h>
ch = toupper(ch);
```

### Reading and writing characters

`%c`

```c
scanf("%c", &ch); // Does not skip whitespaces
scanf(" %c", &ch); // Skips 0+ whitespaces
printf("%c", ch);
```

`getchar` and `putchar` can also be used to read and write single-characters, as in the following construction:

```c
// Skips blanks
while (getchar() == ' ')) {
  // Do nothing
};
```


## The `sizeof` operator

This operator allows a program to determine how much memory is required to store values of a particular type.

`sizeof (x);` produces an unsigned integer representing the number of bytes required to store a value belonging to `x`.

Take care when printing the output of `sizeof`, because the type of the returned value is implementation defined. It is typically safe to cast it to an unisgned long integer before printing it:

```c
printf("SIze of int: %lu\n", (unsigned long) sizeof(int));)
```

## Type conversion

Generally, computers do not do arithmetic with mixed-size operands (e.g. a 16-bit integer and a 32 bit integer). C, however, allows the basic types to be used in mixed expressions, using type conversions. The 16-bit integer will be converted to 32-bits in order to do the requested arithmetic. These conversions are done *implicitly*. They can also be done explicitly, using the **cast** operator: e.g. `float e;` or `frac = f - (int) f;`

C regards `(type-name)` as a unary operator, and so it has higher precedence than a binary operation. That is, these two statements are equivalent:

```c
q = (float) a / b;
q = ((float) a) / b;
```

Implicit type casting is also done in function calls (arguments), when the return type doesn't match the result of the expression being returned, and also during assignment.

### Avoiding overflow

Explicit casts are dometimes needed to avoid overflow:

```c
long int i;
int j = 1000;

i = j * j; // **WRONG**/
```

This is wrong because the result of multiplying two integers is another integer, not a long integer, and 1000 * 1000 is too big to be an `int`.

```c
long int i;
int j = 1000;

i = (long int) j * j;
```

This type cast converts `j` to a long integer type, forcing the other `j` to be converted as well, and storing the output in a long integer.

Note that `(long int) (j * j)` would not work because the overflow would have already happened before type casting.

## Type definitions

`typedef`

This allows you to define types that can be used in the same places as the built-in types:

```c
typedef int Bool;

Bool flag; // equiv. to `int flag;`
```

`Bool` is literally treated as a synonym for `int`.

This can be used to make programs more understandable (for some definition of understandable):

```c
typedef float Dollars;

Dollars cash_in, cash_out;
```

Now if `Dollars` should really be treated as a `double`, that change only needs to be made in one place.
