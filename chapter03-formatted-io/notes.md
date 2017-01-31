# Chapter 3: Formatted Input/Output

## The `printf` function

- `printf("%6d,%4d", 86, 1040);` → `    86,1040`
- `printf("%12.5f", 30.253);` → `    30.25300`
  - 12 characters overall, with 5 after the decimal point
- `printf("%12.5e", 30.253);` → ` 3.02530e+01`
  - 12 characters overall (including exponent), with 5 after the decimal point
- `printf("%-6.2g", .0000009979);` → `1e-06 `
  - 6 characters overall, either e (exponent) or f (fixed decimal) form, with 2 characters after the decimal point (i.e. ≤0.000001)

## The `scanf` function

### `scanf` format strings equivalency

- `%d` vs. ` %d`: Equivalent, because a white-space character in format string matches *any* number of white-space characters in the input string (including none).
- `%d-%d-%d` vs. `%d -%d -%d`: Equivalent: the same logic applies as in the first.
- `%f` vs. `%f `: Capture same values (a single float), but `%f` requires a number to be input and the user to hit enter. e.g: `34.05⏎`, while the second would require the user to actually enter a whitespace character, and would keep being prompted until they did so (but this input would then not even be captured).
- `%f,%f` vs. `%f, %f`: Equivalent: the same logic applies as in the first.

# Exercise 7

`scanf("%d%f%d", &i, &x, &j);``

Assume `i` & `j` are int variables and `x` is a float variable.

If a user enters:
`10.3 5 6`

The values of `i`, `x` and `j` would be:

`i = 10`: `scanf` reads the `1` and `0` then encounters the `.`, since an integer variable cannot contain a decimal point, `10` is stored into `i`, and the `.` is placed back into the input string, leaving it with:

`.3 5 6`

`x = 0.3`: since the next variable is a float (`x`) and thus can contain decimal points, `scanf` reads the `.`, then the `3`, then the ` `, then finally the `5`. Since the `5` character came after a white-space character, it is put back into the input string. This leaves `.3` to be placed in the float variable. As no value is provided before the decimal point it is given the value `0.3`.

`5 6`

`j = 5`: `scanf` reads the `5`, then the ` `, and finally the `6`. As `6` is preceded by a white-space character, it's placed back into the input string, leaving just the value of `5` to be assigned to `j`.

`6`
As no more variables remain to capture the input, `6` can only be accessed with another `scanf` call.

# Exercise 8

`scanf("%d%f%d", &x, &i, &y);`

Assume `i` is an int variable and `x` and `y` are float variables.

if a user enters:
`12.3 45.6 789`

The values of `i`, `x` and `j` would be:

`x = 12.3`:  `scanf` reads `1`, `2`, `.` (since `x` is a float variable `scanf` continues), `3`, ` ` and `4`. Since `4` is preceded by a white-space character it is put back into the input string, leaving us with `12.3` to be assigned to `x`.

`45.6 789`

`i = 45`: `scanf` reads `4`, `5`, `.`. Since `i` is an integer variable, it cannot contains decimals. The `.` is put back in the input string, and `i` is assigned the value `45`.

`.6 789`

`y = 0.6`: `scanf` reads '.' (since `x` is a float variable `scanf` continues), `6`, ` `, `7`. Since `7` is preceded by a white-space character, it is put back into the input string. `y` is give the value `.6` (0.6).

`789`
As no more variables remain to capture the input, `789` can only be accessed with another `scanf` call.
