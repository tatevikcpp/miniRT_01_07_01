#include "libft.h"

float ft_atof(char *str)
{
	int 	sgn;
	int 	div;
	float 	res;

	sgn = 1;
	res = 0;
	div = 10;
	if (!str || *str == '\0')
		return (0);
	while (ft_strchr(SPACES, *str))
		str++;
	if (*str == '-')
		sgn = -1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str++ != '.')
		return (sgn * res);
	while (*str >= '0' && *str <= '9')
	{
		res += ((float)(*str++ - '0')) / div;
		div *= 10;
	}
	return (res * sgn);
}