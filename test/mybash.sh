#!/bin/bash

make
#builtin
# ./minishell ./test/builtin/echo.sh >> mybash_output.txt 2>> my_bash_erros.txt
# ./minishell ./test/builtin/export.sh 1>> mybash_output.txt 2>> my_bash_erros.txt
# ./minishell ./test/builtin/cd.sh 1>> mybash_output.txt 2>> my_bash_erros.txt
# ./minishell ./test/builtin/env.sh 1>> mybash_output.txt 2>> my_bash_erros.txt
# ./minishell ./test/builtin/exit.sh 1>> mybash_output.txt 2>> my_bash_erros.txt
# ./minishell ./test/builtin/pwd.sh 1>> mybash_output.txt 2>> my_bash_erros.txt
# ./minishell ./test/builtin/unset.sh 1>> mybash_output.txt 2>> my_bash_erros.txt
# ./minishell ./test/cmd/ls.sh 1>> mybash_output.txt 2>> my_bash_erros.txt
# ./minishell ./test/cmd/cat.sh 1>> mybash_output.txt 2>> my_bash_erros.txt
./minishell ./test/builtin/echo.sh >> mybash_output.txt 2>> my_bash_erros.txt
./minishell ./test/builtin/export.sh >> mybash_output.txt 2>> my_bash_erros.txt
./minishell ./test/builtin/cd.sh >> mybash_output.txt 2>> my_bash_erros.txt
./minishell ./test/builtin/env.sh >> mybash_output.txt 2>> my_bash_erros.txt
./minishell ./test/builtin/exit.sh >> mybash_output.txt 2>> my_bash_erros.txt
./minishell ./test/builtin/pwd.sh >> mybash_output.txt 2>> my_bash_erros.txt
./minishell ./test/builtin/unset.sh >> mybash_output.txt 2>> my_bash_erros.txt
./minishell ./test/cmd/ls.sh >> mybash_output.txt 2>> my_bash_erros.txt
./minishell ./test/cmd/cat.sh >> mybash_output.txt 2>> my_bash_erros.txt

# bash --posix ./test/builtin/echo.sh 1>> realbash_output.txt 2>> real_bash_errors.txt
# bash --posix ./test/builtin/export.sh 1>> realbash_output.txt 2>> real_bash_errors.txt
# bash --posix ./test/builtin/cd.sh 1>> realbash_output.txt 2>> real_bash_errors.txt
# bash --posix ./test/builtin/env.sh 1>> realbash_output.txt 2>> real_bash_errors.txt
# bash --posix ./test/builtin/exit.sh 1>> realbash_output.txt 2>> real_bash_errors.txt
# bash --posix ./test/builtin/pwd.sh 1>> realbash_output.txt 2>> real_bash_errors.txt
# bash --posix ./test/builtin/unset.sh 1>> realbash_output.txt 2>> real_bash_errors.txt
# bash --posix ./test/cmd/ls.sh 1>> realbash_output.txt 2>> real_bash_errors.txt
# bash --posix ./test/cmd/cat.sh 1>> realbash_output.txt 2>> real_bash_errors.txt

bash --posix ./test/builtin/echo.sh >> realbash_output.txt 2>> real_bash_errors.txt
bash --posix ./test/builtin/export.sh >> realbash_output.txt 2>> real_bash_errors.txt
bash --posix ./test/builtin/cd.sh >> realbash_output.txt 2>> real_bash_errors.txt
bash --posix ./test/builtin/env.sh >> realbash_output.txt 2>> real_bash_errors.txt
bash --posix ./test/builtin/exit.sh >> realbash_output.txt 2>> real_bash_errors.txt
bash --posix ./test/builtin/pwd.sh >> realbash_output.txt 2>> real_bash_errors.txt
bash --posix ./test/builtin/unset.sh >> realbash_output.txt 2>> real_bash_errors.txt
bash --posix ./test/cmd/ls.sh >> realbash_output.txt 2>> real_bash_errors.txt
bash --posix ./test/cmd/cat.sh >> realbash_output.txt 2>> real_bash_errors.txt

diff mybash_output.txt realbash_output.txt