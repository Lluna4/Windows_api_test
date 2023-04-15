#ifndef LIB
# define LIB
#include <Windows.h>
#include <iostream>
#include <vector>

struct usuario
{
	char* nombre;
	char* apellido;
	char* dni;
	char* direccion;
};

void ft_swap(char** a, char** b)
{
	char* buff;

	buff = *a;
	*a = *b;
	*b = buff;
}

static int	ft_intlen(int n)
{
	int	ret;

	ret = 1;
	while (n >= 10)
	{
		ret++;
		n = n / 10;
	}
	return (ret);
}

static char* ft_make_ret(int n, int sign)
{
	int		len;
	char* ret;

	len = ft_intlen(n) + sign;
	ret = (char*)calloc(len + 1, sizeof(char));
	if (!ret)
		return (0);
	len--;
	while (len >= 0)
	{
		ret[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (sign == 1)
		ret[0] = '-';
	return (ret);
}

char* ft_itoa(int n)
{
	char* ret;
	int		sign;

	sign = 0;
	if (n == -2147483648)
	{
		ret = (char*)malloc(12 * sizeof(char));
		if (!ret)
			return (0);
		memcpy(ret, "-2147483648", 12);
		return (ret);
	}
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	return (ft_make_ret(n, sign));
}
#endif