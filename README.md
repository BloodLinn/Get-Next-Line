# Get Next Line

This project implements the `get_next_line` function in C, which reads a file line by line. Each call to the function returns the next line from the specified file descriptor. This utility is commonly used in C coding schools such as 42 and is a great exercise for managing memory, buffers, and file I/O in C.

## Features

- Returns one line per call from a file descriptor
- Handles memory allocation and prevents leaks
- Supports multiple file descriptors simultaneously
- No line length limitation (limited only by available memory)

## Usage

1. Function prototype:
    ```c
    char *get_next_line(int fd);
    ```

2. Call the function with a file descriptor (`fd`). It returns a pointer to a string containing the next line, or `NULL` if there are no more lines or an error occurs.

### Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## Compilation

You can compile the project using:
```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```
> Note: You can change the value of `BUFFER_SIZE` as needed.

## Files

- `get_next_line.c` — Main function implementation
- `get_next_line_utils.c` — Utility/helper functions
- `get_next_line.h` — Header file with function prototypes

## Requirements

- Standard C libraries
- POSIX-compliant operating system (Linux, macOS, etc.)

## License

This project is licensed under the MIT License.

---

Feel free to open an issue or submit a pull request for suggestions, bug reports, or contributions.
