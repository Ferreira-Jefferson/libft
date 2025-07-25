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
library/
├── modules/
│   ├── allocation/       # Memory allocation functions
│   ├── character/        # Character classification and conversion
│   ├── conversion/       # String/number conversion functions
│   ├── list/             # Linked list functions
│   ├── memory/           # Memory manipulation functions
│   ├── output/           # Output functions
│   └── string/           # String manipulation functions
├── libft.h               # Main header file
├── Makefile              # Build script
```

## Functions

The library includes re-implementations of the following standard C functions and more:

- **Memory:** `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`, `calloc`, `strdup`
- **String:** `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strnstr`, `strncmp`, `strjoin`, `strtrim`, `split`, `substr`, `strmapi`, `striteri`
- **Character:** `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower`, `isspace`, `isupper`, `islower`
- **Conversion:** `atoi`, `itoa`
- **Output:** `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`, `putchar`
- **Linked List:** `lstnew`, `lstadd_front`, `lstadd_back`, `lstsize`, `lstlast`, `lstdelone`, `lstclear`, `lstiter`, `lstmap`

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

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

*Project developed as part of the 42 School curriculum.*
