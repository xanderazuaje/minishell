#ifndef BUILTINS_H
# define BUILTINS_H

#include "../minishell.h"

void exec_builtin(char **args, char **env);

//void do_cd(char **args);
void do_pwd(void);
void do_exit(char **args);
void do_env(char **envp);

#endif