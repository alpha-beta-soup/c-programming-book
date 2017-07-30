Show how to replace a continue statement by an equivalent goto statement

example: printing odd numbers

## `continue`

```c
for (i = 0; i < 10; i++) {
  if (i % 2) {
    continue;
  }
  printf("%d", i);
}
```

## `goto`

```c
for (i = 0; i < 10; i++) {
  if (i % 2) {
    goto done;
  }
  printf("%d", i);
  done:;
}
```
