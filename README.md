# Minishell

Minishell is a simple shell implementation in C, designed to mimic the behavior of a Unix shell. It supports various shell features such as command execution, environment variable management, and more.

## Features

- Command execution with support for pipes and redirections.
- Built-in commands: `cd`, `echo`, `env`, `exit`, `export`, `pwd`, `unset`.
- Environment variable management.
- Signal handling for interactive use.
- Error handling for common shell errors.

## Setup

1. **Clone the repository:**
   ```bash
   git clone https://github.com/jguigli/minishell.git
   cd minishell
   ```

2. **Build the project:**
   - Ensure you have `make` and a C compiler installed.
   - Run the following command to compile the project:
     ```bash
     make
     ```

3. **Dependencies:**
   - The project uses `libft` and `gnl` (get_next_line) libraries. Ensure these are available in the specified paths or adjust the `Makefile` accordingly.

## Usage

- **Run the shell:**
  ```bash
  ./minishell
  ```

- **Execute commands:**
  - Use standard shell syntax to execute commands.
  - Example: `ls -la | grep minishell`

- **Built-in commands:**
  - `cd [directory]`: Change the current directory.
  - `echo [string]`: Display a line of text.
  - `env`: Display the environment variables.
  - `exit`: Exit the shell.
  - `export [name]=[value]`: Set an environment variable.
  - `pwd`: Print the current working directory.
  - `unset [name]`: Remove an environment variable.

