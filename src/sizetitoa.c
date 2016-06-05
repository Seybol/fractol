#include "fractol.h"

static void	ft_fill_size_t(size_t n, int sign, char *str)
{
	int i;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
}

static int	ft_nlength_size_t(size_t nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

char		*ft_itoa_size_t(size_t n)
{
	int		sign;
	char	*str;

	sign = 1;
	str = ft_strnew(ft_nlength_size_t(n));
	if (str == NULL)
		return (NULL);
	ft_fill_size_t(n, sign, str);
	ft_strrev(str);
	return (str);
}
