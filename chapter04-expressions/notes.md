## Arithmetic operators

- Unary
  - Unary `+` (does nothing, only emphasis)
  - Unary `-`
- Binary
  - Additive
    - `+`
    - `-`
  - Multiplicative
    - `*`
    - `/`
    - `%`

"Binary" because they require two operands.

Mixing `int` and `float` types with binary operands results in `float` output.

The `%` operator *requires* `int` operands: if not, the program won't compile.

When `/` and `%` are used with negative operands, the result is implementation-defined.

## Assignment operators

### Simple assignment

- `i = 5;`

In C, unlike many programming languages, assignment is an *operator*, not a *statement*.

It is an operation with a *side effect*.

## Increment and decrement operators

- `i = i + 1;` → `i += 1;` → `i++`

Note that these operators can be *prefix* or *postfix*:

- `++i` (pre-increment, yields i + 1, and as a side-effect increments i)
- `i++` (post-increment, yields i, and *then* increments i as a side-effect)
