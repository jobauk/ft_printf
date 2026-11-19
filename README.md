*This project has been created as part of the 42 curriculum by jaukes*

## Description

The goal of this project is to implement a version of `printf` with support for the following format specifiers:
 - `%c` -> single character
 - `%s` -> C string
 - `%p` -> pointer in hexadecimal format
 - `%d` -> integer in base 10
 - `%i` -> alias for `%d`
 - `%u` -> unsigned integer in base 10
 - `%x` -> unsigned integer in base 16
 - `%X` -> unsigned integer in base 16 (uppercase)
 - `%%` -> `%` literal

## Instructions

To compile the library (libftprintf.a) run:
```sh
make
```

To compile a binary (e.g. for testing) run:
```sh
make build
```

To compile and run a binary run:
```sh
make run
```

To compile a binary and open it in the debugger (gdb/lldb) run:
```sh
make debug
```

## Resources
I solely used the man pages. No AI was used.

## Implementation
The main pipeline looks something like this:

- Walk input string
    1. If current character is not `%` just print it and continue.
    2. If it is a format specifier (%) parse the complete format (including flags, precision, etc) using `parse_spec` into the `t_spec` struct.
        1. Find the format function based on the conversion specifier and call it.
        2. The format function pulls an argument from the `va_list` using the appropriate type. Then, based on the format options, emits a sequence of tokens that represent the the final output. For example:
            ```sh
            [Repeat('0', 5), Span("1234", 4)]
            ```
    3. This is then passed to a writer that emits the actual characters represented by the stream of tokens. This writer keeps track of written characters and occurred errors internally. 

- If the writer encountered an error return `-1` otherwise return the amount of bytes written.


**Undefined Behaviour**\
Using an incorrect/malformed format specifier is undefined behaviour and will yield weird results. An exapmle of an incorect format specifier is a `%` without a conversion specifier.
The users is trusted to supply arguments of the correct type as defined by their conversion specifier. Failing to do so will result in undefined behaviour.
