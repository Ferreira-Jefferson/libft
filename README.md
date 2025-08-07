# libft

This project is part of the 42 School curriculum. It consists of re-implementing a set of standard C library functions, as well as some additional utility functions, to deepen your understanding of C programming, memory management, and data structures.

## Table of Contents
- [About](#about)
- [Project Structure](#project-structure)
- [Functions](#functions)
- [Usage](#usage)
- [Compiling](#compiling)
- [Testing](#testing)
- [License](#license)

## About

`libft` is a custom C library that replicates and extends many of the standard C library functions. The goal is to provide a solid foundation for future C projects at 42 and to gain a deeper understanding of how these functions work under the hood.

## Project Structure

The project is organized as follows:

```
.
├── *.c                   # function implementations
├── utils/*.c             # Printf utility function implementations
├── libft.h               # Main header file
├── Makefile              # Build script
```

## Functions

The library includes re-implementations of the following standard C functions and more:

### Memory Functions
- `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc`, `realloc`, `to_free`

### String Functions
- `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strnstr`, `strncmp`, `strjoin`, `strtrim`, `split`, `substr`, `strmapi`, `striteri`, `strdup`

### Character Functions
- `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower`, `isspace`

### Conversion Functions
- `atoi`, `atoi_base`, `itoa`, `itoa_base`, `convert_base`, `is_valid_base`

### Output Functions
- `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`, `putunbr_fd`

### Linked List Functions (Bonus)
- `lstnew`, `lstadd_front`, `lstadd_back`, `lstsize`, `lstlast`, `lstdelone`, `lstclear`, `lstiter`, `lstmap`

### Additional Utility Functions
- `get_next_line` - Reads a line from a file descriptor
- `ft_printf` - Formatted output conversion

### Printf Utility Functions
- `ft_print_char` - Prints a character
- `ft_print_string` - Prints a string
- `ft_print_int` - Prints an integer
- `ft_print_unsigned` - Prints an unsigned integer
- `ft_print_hex_lower` - Prints a hexadecimal number (lowercase)
- `ft_print_hex_upper` - Prints a hexadecimal number (uppercase)
- `ft_print_pointer` - Prints a pointer address
- `ft_print_percent` - Prints a percent sign

All functions are implemented according to the 42 subject requirements and follow the C99 standard.

## Usage

1. **Clone the repository:**
   ```bash
   git clone https://github.com/Ferreira-Jefferson/libft.git
   cd libft
   ```
2. **Build the library:**
   ```bash
   make
   ```
3. **Include in your project:**
   - Add `libft.h` to your source files.
   - Link the compiled `libft.a` with your project during compilation:
	 ```bash
	 gcc your_program.c -L. -lft -o your_program
	 ```

## Compiling

- To compile the library:
  ```bash
  make
  ```
- To compile with bonus functions:
  ```bash
  make bonus
  ```
- To clean object files:
  ```bash
  make clean
  ```
- To remove all binaries:
  ```bash
  make fclean
  ```
- To recompile from scratch:
  ```bash
  make re
  ```

## Testing

You can write your own test files or use available third-party testers for `libft` to validate your implementation. Make sure to test edge cases and invalid inputs.

## License

This project is licensed under the GNU General Public License v3.0 (GPLv3). See the [LICENSE](LICENSE) file for details.

---

*Project developed as part of the 42 School curriculum.*