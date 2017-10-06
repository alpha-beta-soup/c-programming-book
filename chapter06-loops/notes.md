# Chapter 6: Loops

Iteration statements in C:

- `while`
- `do`
- `for`

Statements used in conjunction with loops in C:

- `break`
- `continue`
- `goto`

## `while`

Used for loops whose controlling expression is tested *before* the loop body.

```c
while (i < n) { // Controlling expression
  i = i * 2; // Loop body
}
```

If the expression evaluates true (i.e. non-zero), the loop body is executed.

See programs `square.c` and `sum.c` for examples.

## `do`

Used for loops whose controlling expression is tested *after* the loop body.

The general form is `do { statement } while ( expression );`:

```c
i = 10;
do {
  printf("Count %d", i);
  --i;
} while (i < 0);
```

The braces are not necessary but are pretty darn useful, because otherwise the `while` statement will be confusing to readers.

See example `numdigit.c`

## `for`

Primarily a convenience for loops that increment or decrement counting variables, but very versatile.

General form: `for (expr1; expr2; expr3_ { statement }`.

This is actually a concise form of `while` loop:

```c
expr1;
while (expr2) {
  statement;
  expr3;
}
```

```
i = 10;
while (i > 0) {
  printf("Counting %d", i);
  i--;
}
```

```
for (i = 10; i > 0; --i) {
  printf("Counting %d", i);
}
```

Some kinds of loops may not need all (or any) for the expressions that control the loop. For example, the counting variable may already have been initialised in a separate assignment. All of the expressions may be omitted (`for (;;)` is an idiom for an infinite loop, equivalent for `while (1)`).

This empty statement is called the **null statement**.

You can also use the **comma operator** to write a `for` statement with more than one expressions where typically there is only one (e.g. initialising and/or incrementing two different variables with different purposes):

```c
for (sum = 0, i = 1; i <= N; i++) {
  sum += i;
}
```

See examples `square2.c` and `square3.c`.

## `break`

Jumps out of a loop and transfers control to the next statement after the loop.

A `break` statement only escapes one level of nesting (applicable to `do`, `for`, `while`, and `switch`).

## `continue`

Skips the remainder of a loop iteration.

## `goto`

Jumps to any statement within a function.

`break` and `goto` are really just special cases of `goto`: `break` transfers control to a point just outside of the enclosing loop, and `continue` to a point just before the end. `goto` can jump to any statement, provided that the statement has a **label**.

It is rather unusual to use a `goto`, but it can be useful to escape a deep nesting:

```c
while (...) {
  switch (...) {
    ...
    goto loop_done;
    ...
  }
}
loop_done: ...;
```

In the above, a `break` would only have returned control back inside the `while` (at the end of the `switch`).

Example
