# FT_PRINTF

*This project has been created as part of the 42 curriculum by agaspary.*

## Table of Contents

- [Description](#description)
- [Instructions](#instructions)
- [Usage](#usage)
    - [Implementation Details](#implementation-details)
    - [Supported Conversions](#supported-conversions)
- [Resources](#resources)
- [Author](#author)

## Description

**ft_printf** is a project developed as part of the 42 curriculum. The goal of this project is to recreate the famous `printf()` function from the C standard library. This project provides an opportunity to learn about variadic functions in C and formatting outputs. 

This library is intended to be reused in future projects and provides:
* ✅ Reimplementation of `printf` functionality
* ✅ Handling of variadic arguments
* ✅ Compiled with strict flags: ```-Wall -Wextra -Werror```
* ✅ No buffer management (as per subject requirements)

---

## Instructions

### Compilation

The library is compiled using `cc` with the flags:
``` bash
-Wall -Wextra -Werror
```
A Makefile is provided and includes the required rules.

#### Available Makefile commands

```bash
make        # Compiles the library and creates libftprintf.a
make clean  # Removes object files
make fclean # Removes object files and libftprintf.a
make re     # Full recompilation
```
After compilation, a static library named libftprintf.a will be created at the root of the repository.

---

## Usage

### Including the library 
In your C source files, include the header:
```c
#include "ft_printf.h"
```
Compiling your program with ft_printf

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a
```

Example
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, 42!\n");
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Test string");
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```
### Implementation Details

Here is the explanation of the chosen algorithm and data structure. 

 - #### Variadic Arguments:
 The project uses the ```stdarg.h``` library macros (```va_start, va_arg, va_end```) to handle an undefined number of arguments.

 - #### Main Loop:
   The main ft_printf function iterates through the format string.
    - If a regular character is found, it is written to the standard output.

    - If a % sign is found, the function checks the next character to determine the conversion type.

- #### Dispatching:
    A dispatcher function (or switch-case logic) calls specific helper functions for each type (e.g.,```ft_print_char, ft_print_hex```, etc.).

 - #### Return Value:
    The function maintains a counter of all printed characters and returns this total length, mimicking the behavior of the original printf.

 ### Supported Conversions

 The function handles the following conversions:

| Specifier|                      Description                           |
|----------|----------------------------------------------------------- |
| ```%c``` | Prints a single character.                                 |
| ```%s``` | Prints a string (as defined by the common C convention).   |
| ```%p``` | The void pointer argument is printed in hexadecimal format.|
| ```%d``` | Prints a decimal (base 10) number.                         |
| ```%i``` | Prints an integer in base 10.                              |
| ```%u``` | Prints an unsigned decimal (base 10) number.               |
| ```%x``` | Prints a number in hexadecimal (base 16) lowercase format. |
| ```%X``` | Prints a number in hexadecimal (base 16) uppercase format. |
| ```%%``` | Prints a percent sign.                                     |

## Resources
 - man 3 printf
 - man 3 stdarg
 - 42 ft_printf subject PDF

### AI Usage
AI tools were used as a learning aid to: 

 - Clarify the usage of variadic functions (va_list, va_start, etc.).

 - Help organize and format the README.md content clearly and consistently.

 - Understand the requirements for the algorithm explanation section.

 All implementation decisions and code were written and understood by the author, in accordance with the 42 curriculum guidelines.

 ## Author

 **agaspary**

42 Yerevan

---
 ## License
This project is part of the 42 School curriculum and is intended for educational purposes only.