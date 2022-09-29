/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:28:18 by woon              #+#    #+#             */
/*   Updated: 2022/06/09 19:11:16 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define FALSE 0
# define TRUE 1

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdbool.h>

# include "../libft/libft.h"

# define SYNTAX_ERROR		"Syntax error: near unexpected token!"
# define QUOTE_ERROR 		"not valid usage of quote or double quote"
# define MALLOC_ERROR 		"Memory malloc fail!"
# define PIPE_TOKEN_ERROR	"syntax error near unexpected token `|'"
# define NEWL_TOKEN_ERROR	"syntax error near unexpected token `newline'"
// # define PIPE_ERROR 	"Pipe function is failed!"
// # define FORK_ERROR 	"Fork function is failed!"

typedef struct s_envp_list
{
	char	*key;
	char	*value;
}	t_envp_list;

typedef struct s_heredoc
{
	char	*end_string;
	char	*file_name;
}	t_heredoc;

typedef struct s_state
{
	char	**envp;
	char	**env_str;
	char	**safe_paths;
	char	*pwd;
	char	*oldpwd;
	int		exit_status;
	int		signal;
	t_list	*env;
}	t_state;

typedef enum e_node_type
{
	TYPE_IN_OVERWRITE,
	TYPE_OUT_OVERWRITE,
	TYPE_HEREDOC,
	TYPE_OUT_APPEND,
	TYPE_CMD,
	TYPE_ETC
}	t_node_type;

typedef struct s_redir
{
	t_node_type		type;
	char			*file;
	char			**inputs;
	int				index;
	bool			doub;
	struct s_redir	*left;
	struct s_redir	*next;
}				t_redir;

typedef struct s_cmd
{
	char		**tmpline;
	char		**cmdlines;
	char		*cmdline;
	char		*path;
	int			is_last;
	int			is_first;
	int			is_redir;
	int			s_doub;
	int			pid;
	int			fd;
	t_redir		*input;
	t_redir		*dinput;
	t_redir		*output;
	t_redir		*root;
}				t_cmd;

t_state	g_state;

// change_struct.c
void		change_struct(t_list *main_list);
void		after_case(char **new_cmdlines, int j, t_list **tmp);
void		change_node(t_list *main_list);
// change_type.c
void		change_type_in(t_cmd *cmd);
void		change_type_out(t_cmd *cmd);
void		change_type_heredoc(t_cmd *cmd);
void		change_type_cmd(t_cmd *cmd);
void		change_type_etc(t_cmd *cmd);
// redir_file.c
int			index_file(char *s, t_redir *tmp);
int			index_file_doub(char *s, t_redir *tmp);
// redir_utils.c
void		fill_struct(t_redir *tmp);
// redir.c
int			check_cmdline(char *s);
int			index_redir(char *s, t_cmd *cmd);
int			is_valid_redir(t_cmd *cmd);
// key.c
char		*cmp_envp(char *key);
int			index_doub(char *s, char **ret);
int			find_key(char *s, char **ret);
void		change_key(char *s, int *len, t_redir *tmp, int *skip);
// store_envp.c
void		copy_env(char **envp);
char		*get_env(char *key);
// init.c
void		init_redir(t_cmd *cmd);
t_redir		*redir(t_redir **list);
void		init_cmd(t_cmd *cmd, int i, char *s);
// signal.c
void		echoctl_on(void);
void		echoctl_off(void);
void		init_signal(void);
void		init_prompt(t_list *cmds, t_list **heredoc);
//get_input.c
int			is_valid_quote(char *line);
int			is_valid_space(char *line);
void		get_input(void);
char		*read_line(char **line, t_list *main_list, t_list **heredoc);
int			check_input(char *line);
// check_pipe.c
int			check_pipe(char *line, t_list *main_list);
int			fill_main_list(t_list *main_list, char **tmp_line);
char		*modify_line(char *line);
int			change_line(char *s, char **ret);
// parse.c
void		parse_start(t_list *main_list);
int			parse(t_cmd *cmd);
// util
void		print_malloc_error(void);
void		print_error(char *s);
char		*str_join(char *s1, char *s2, int flag);
char		**split_func(char const *s, char c);
void		ft_lstadd_back(t_list **lst, t_list *new);
// get_heredoc.c
t_list		*create_list(void *data);
t_list		*get_heredoc(t_list *exec);
// execute.c
char		*get_val_cmd(t_cmd *cmds);
void		execve_error(char *str);
void		execute_cmd(t_cmd *cmds);
void		single_cmd(t_cmd *cmds);
void		multi_cmd(t_cmd *cmds);
// here_doc.c
void		prompt_heredoc(int fd, char *end);
void		heredoc_sig_handler(int signal);
void		heredoc_signal(void);
int			run_heredoc(t_list *iter);
// pipe.c
void		fork_pipe(t_list *link, t_list *heredoc);
void		wait_all_child(t_list *head, int last_pid);
void		change_connection_pipe_child(t_list *cmd, int *p);
void		change_connection_pipe_parent(t_list *cmd, int *p);
void		pipe_setting(t_list *cmds, t_list *heredoc);
// redirection.c
void		input(char *filename, int dup_fd);
void		output(char *filename, int dup_fd, int flag);
void		here_doc(int index, int dup_fd, t_list *heredoc);
// tree.c
void		tree_traversal(t_redir *tree, t_cmd *data, \
int pipe_exist, t_list *heredoc);
void		test_print(t_list *main_list);
// builtin
void		ft_echo(t_cmd *data, int pipe_flag);
void		ft_env(t_cmd *data, int pipe_flag);
void		ft_exit(t_cmd *data, int pipe_flag);
void		ft_pwd(t_cmd *data, int pipe_flag);
void		unlink_all(t_list *heredoc);
void		ft_unset(t_cmd	*data, int pipe_flag);
void		free_list(t_list	*list);
void		ft_cd(t_cmd *data, int pipe_flag);
void		change_global_oldpwd(char *prev);
void		change_envp_pwd(void);
void		change_envp_oldpwd(void);
void		change_values(char *now);
void		change_to_old_path(char *now);
void		use_tilde(char *str, char *now);
int			go_home_dir(char *argv, char *now);
void		ft_free(void **target);
int			get_equal_index(char *str);
void		print_error_cd(char *path);
void		set_key_value(char *str, char **key, char **value, int index);
void		get_envp_change(char *key, char *value);
int			modify_argv(char **argv);
t_list		*init_list(void);
t_envp_list	*init_envp(char *key, char *value);
char		*new_key(char *str, int len, int *i);
char		*new_value(char *str, int len, int index, int *i);
void		add_key_value(t_list *envpl, t_envp_list *envp, \
char *key, char *value);
void		ft_export(t_cmd *data, int pipe_flag);
void		export_error(char *argv);

#endif
