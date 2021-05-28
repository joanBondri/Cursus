#include "printf.h"

t_bool	is_valid_flags(char c)
{
	if (ft_isdigit(c) || c == '-' || c == '*' ||
			c == '.')
		return (TRUE);
	return (FALSE);
}

t_bool	is_convert_letter(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x' || c == 'X'
			|| c == '%')
		return (TRUE);
	return (FALSE);
}
