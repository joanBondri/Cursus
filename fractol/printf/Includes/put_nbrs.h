#ifndef PUT_NBRS_H
# define PUT_NBRS_H
# include "basic_elem.h"

void	put_unbr(unsigned int n);
void	put_hexa(unsigned int n, char (*char_hexa)(unsigned int));
char	get_upper_hexa(unsigned int n);
char	get_lower_hexa(unsigned int n);
void	put_nbr(int n);

#endif
