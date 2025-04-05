# _printf

A custom implementation of the standard C library function `printf`. This project is part of the Holberton School curriculum and focuses on handling formatted output using variadic functions in C.

---

## Description

`_printf` is a simplified version of the C standard `printf` function. It formats and prints data to standard output (`stdout`) according to a format string passed as the first parameter.

This function is designed to mimic the behavior of `printf` while handling a selected set of format specifiers.

---

## Prototype
```c
int _printf(const char *format, ...);


Supported Format Specifiers
Specifier	Description
%c	Prints a single character
%s	Prints a string
%%	Prints a literal percent sign
%d	Prints a signed decimal integer
%i	Prints a signed decimal integer
Return Value
The _printf function returns the number of characters printed (excluding the null byte \0 used to end strings).

If the format string is NULL, the function returns -1.

Usage Examples
_printf("Hello, %s!\n", "world");
// Output: Hello, world!

_printf("Character: %c\n", 'H');
// Output: Character: H

_printf("Percent: %%\n");
// Output: Percent: %

_printf("Number: %d\n", 123);
// Output: Number: 123


Project structure
main.h - header file that contains all the method prototyoe

_printf.c - the main logic and handles the printing function

Pchar.c - handles %c
Pstring.c - handles %s
Ppercent - handles %%
Pint.c - handles both %d and %i
print_numbers.c - is a helping methid thats help Pint.c



Authors:
Abdulrahman Alfawzan, Ibrahim Alfaleh