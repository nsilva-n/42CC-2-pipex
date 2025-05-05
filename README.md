# pipex

*Oh fearless navigator of streams, prepare thyself to traverse the turbulent waters of pipes and redirections, where commands flow like rivers and outputs are caught like treasures in nets!*

Within this repository lies **pipex**, a challenge to master the art of inter-process communication, weaving together the inputs and outputs of commands into a harmonious symphony of pipes and redirections.

---

## Prelude

*Oh valiant mariner of code, embark on the voyage of `pipex`, a tale of commands chained by the bonds of pipes!*

In this project, you shall emulate the behavior of the shell pipeline (`|`) and redirections (`<`, `>`), crafting a program that captures the essence of Unix command orchestration.

---

## Table of Contents

- [The Quest](#the-quest)
- [Features](#features)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Command Syntax](#command-syntax)
- [Error Handling](#error-handling)
- [Testing](#testing)
- [Acknowledgments](#acknowledgments)

---

## The Quest

*Set sail, O noble coder, on this odyssey through the seas of standard input, output, and error!*

Your mission is to implement a program, `pipex`, that emulates the following shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

Your task is to:
1. Redirect the content of `file1` as input to `cmd1`.
2. Pipe the output of `cmd1` as input to `cmd2`.
3. Redirect the output of `cmd2` into `file2`.

This project beckons you to wield the powers of process creation, pipes, and file descriptors with precision and mastery.

---

## Features

*Witness the wonders of pipex:*

- **Piping Commands**: Link the output of one command to the input of another with the elegance of Unix pipes.
- **File Redirections**: Redirect input and output seamlessly to and from files.
- **Process Control**: Spawn child processes to execute commands independently.
- **Error Handling**: Gracefully handle errors from system calls and invalid inputs.

---

## Requirements

*To embark on this journey, gather these provisions:*

- **Compiler**: GCC or Clang.
- **Libraries**: Standard C library (`<unistd.h>`, `<fcntl.h>`, `<sys/wait.h>`).
- **Makefile**: Automate your build process with targets `all`, `clean`, `fclean`, and `re`.

---

## Getting Started

*Hoist the sails and prepare for launch!*

Clone this repository and navigate to the `pipex` directory:
```bash
git clone https://github.com/nsilva-n/42CC-2-pipex.git
cd 42CC-2-pipex
make
```

Run your program with:
```bash
./pipex <file1> <cmd1> <cmd2> <file2>
```

Example:
```bash
./pipex input.txt "grep foo" "wc -l" output.txt
```

The above command will:
1. Read content from `input.txt`.
2. Pass it to `grep foo` to search for lines containing "foo".
3. Pipe the output to `wc -l` to count the lines.
4. Write the final result to `output.txt`.

---

## Command Syntax

🎵 *Master the syntax of `pipex` to command the flow of data:* 🎵

### Arguments
- `<file1>`: The input file.
- `<cmd1>`: The first command to execute.
- `<cmd2>`: The second command to execute.
- `<file2>`: The output file.

### Example Workflow
The command:
```bash
./pipex input.txt "ls -l" "grep pipex" output.txt
```
will:
1. List the files in the current directory (`ls -l`).
2. Filter the output for lines containing "pipex" (`grep pipex`).
3. Write the result to `output.txt`.

---

## Error Handling

🎵 *Navigate the treacherous waters of errors with care and vigilance:* 🎵

- **Invalid Arguments**: Display a usage message if the number of arguments is incorrect.
- **File Errors**: Handle errors when opening, reading, or writing files.
- **Command Errors**: Handle errors if a command cannot be executed or found.
- **System Call Errors**: Check the return values of all system calls and handle errors appropriately.

---

## Testing

🎵 *Test thy creation against the trials of the pipeline!* 🎵  

### Basic Tests
Test simple pipelines:
```bash
./pipex input.txt "cat" "wc -w" output.txt
```

### Edge Cases
- Empty input files.
- Commands with no output.
- Files with restricted permissions.

### Debugging
Use tools like `valgrind` to ensure no memory leaks or invalid accesses:
```bash
valgrind --leak-check=full ./pipex input.txt "ls -l" "grep pipex" output.txt
```

### Comparisons
Compare the output of `pipex` with the equivalent shell command:
```bash
< input.txt ls -l | grep pipex > output.txt
```

---

## Acknowledgments

*With eternal gratitude to the creators of Unix, the 42 curriculum, and the pioneers of process control, we dedicate this work.*

May your journey through the pipelines of `pipex` lead you to mastery over the streams of data and the orchestration of commands.
