# minishell

A minimal Unix shell implemented in C as part of the 42 curriculum.
The project focuses on process creation, signal handling, parsing, and file descriptor management, closely replicating the behavior of **bash** for a defined subset of features.

---

## Features

- Interactive prompt with command history
- Execution of binaries using `$PATH`
- Built-in commands:
  - `echo` (with `-n`)
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- Environment variable expansion (`$VAR`, `$?`)
- Single and double quotes handling
- Input/output redirections:
  - `<`, `>`, `>>`
- Pipes (`|`)
- Signal handling:
  - `Ctrl-C`
  - `Ctrl-D`
  - `Ctrl-\`
- Proper exit status propagation

---

## What This Project Demonstrates

- Parsing and tokenization of user input
- Process control with `fork`, `execve`, `wait`
- Pipe and redirection handling using file descriptors
- Signal management with `signal` / `sigaction`
- Memory management without leaks
- Writing modular, maintainable C code under strict constraints

---

## Technologies

- Language: **C**
- Standard: **C99**
- Libraries:
  - `readline`
  - standard POSIX system calls
- Platform: Linux / macOS

---

## Build & Run

### Requirements
- `gcc`
- `make`
- `readline` development library

### Compilation
```bash
make
```

### Run
```bash
./minishell
```

### Clean
```bash
make clean
make fclean
```

---

## Usage Example

```bash
minishell$ echo "Hello $USER"
Hello aiturria

minishell$ ls -l | grep minishell > output.txt
```

---

## Limitations

- Does not support:
  - wildcards (`*`)
  - logical operators (`&&`, `||`)
  - subshells
- Behavior matches **bash** only for the features required by the subject

---

## Testing

- Manual testing against `bash`
- Memory checked with:
```bash
valgrind --leak-check=full ./minishell
```
- AddressSanitizer used during development

---

## Project Structure

```
minishell/
├── src/
│   ├── parser/
│   ├── executor/
│   ├── libft/
├── include/
├── Makefile
└── README.md
```

---

## License

This project is for educational purposes as part of the 42 curriculum.
