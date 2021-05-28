#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int		is_n(char c);
char	*create_newline(char ***line, char *x);
int		assign(char ***line, char *x);
int		recurs(int fd, char **line);
int		get_next_line(int fd, char **line);
#endif
