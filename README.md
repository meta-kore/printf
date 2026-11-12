# printf

A from-scratch implementation of C's `printf`, written in C: `_printf(const char *format, ...)` writes formatted output to standard output and returns the number of characters printed.

```c
_printf("Hello, %s! %d%% done, 0x%X\n", "world", 50, 255);
```

## Conversion specifiers

| Specifier | Output |
|---|---|
| `%c` `%s` `%%` | Character, string, literal percent |
| `%d` `%i` | Signed decimal integer |
| `%u` `%o` `%x` `%X` | Unsigned decimal, octal, hex (lower, upper) |
| `%b` | Unsigned integer in binary |
| `%p` | Pointer address |
| `%S` | String, with non-printable characters as `\x` escapes |
| `%r` | String, reversed |
| `%R` | String, ROT13-encoded |

Flags `-` `+` `0` `#` and space, field width, precision and the `l` and `h` size modifiers are parsed before each specifier.

## Build

The functions build as a library. `main.c` is a test harness that deliberately uses bad format strings, so compile it without `-Werror`:

```sh
gcc -Wall -Wextra -Wno-format -std=gnu89 *.c -o printf-test
./printf-test
```

To use `_printf` in your own program, compile every file except `main.c` and include `main.h`.

## Layout

```
_printf.c          Entry point: walk the format string
handle_print.c     Match a specifier to its handler
get_flags.c  get_width.c  get_precision.c  get_size.c   Parse the modifiers
functions*.c       One handler per specifier
write_handlers.c   Padding and number writing
utils.c            Shared helpers
main.h             Types and prototypes
```

## Notes

A team project for ALX Africa Software Engineering.
