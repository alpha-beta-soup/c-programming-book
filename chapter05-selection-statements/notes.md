# Selection statements

The `if` and `switch` statements allow a program to select a particular execution path from a set of alternatives.

The **conditional operator** (`?:`) is also used, to test a condition within an expression.

However before the `if` statement comes **logical expressions**: conditions that the `if` statement can test. Logical expressions are built from:
  - Relational operators (`<`, `<=`, `>`, `>=`)
  - Equality operators (`==`, `!=`)
  - Logical operators (`&&`, `||`, `!`)

## Logical operators

- Note that `i < j < k` is not the same as `i < j && j < k`, as you might expect. Only the latter expression tests whether `j` is between `i` and `k`, the first does this: `(i < j) < k` (noting that the first expression in parentheses returns `0` or `1`).


| Symbol | Meaning          |
|--------|------------------|
| `!`    | logical negation |
| `&&`   | logical *and*    |
| <code>&#124;&#124;</code>   | logical *or*     |

- `!expr` has the value `1` if `expr` has the value `0`.
- `expr1 && expr2` has the value `1` if both expressions are non-zero.
- `expr1 || expr2` has the value `1` if either (or both) expression has a non-zero value.
- In all other cases these operators produce `0`.
- `&&` and `||` do short-circuit evaluation (so be wary of using side-effects in the component expressions, as they will not occur given certain conditions).

## The `if` statement

### Idioms

- Testing whether 0 ≤ i < n: `if (0 <= i && i < n)`
- Testing whether i is outside the range (the opposite): `if (i < 0) || i >= n)`

### The "dangling if"

The `else` clause in the following snippet actually belongs to the **inner `if`**, which is not what the indentation suggests.

```c
if (y != 0)
  if (x != 0)
    result = x / y;
else
  printf("Error: y is equal to 0\n")
```

We can avoid this by using parentheses:

```c
if (y != 0) {
  if (x != 0)
    result = x / y;
} else
  printf("Error: y is equal to 0\n")
```

### The conditional operator

`expr1 ? expr2 : expr3` (ternary, because it's not binary, it is unique among operators in that it requires *three* operators). This should be read as "if expr1 then expr2 else expr3"

Note that when `expr1` and `expr2` are mixed int and float, the outcome will be float (the int converted to float).

## The `switch` statement

- "case labels": each case begins with a *constant expression* (like an ordinary expression except it can't contain variables or function calls).
