#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int value)
{
	int len;
	int sign;
	int temp;
	char *number;

	len = 0;
	sign = 0;
	temp = value;
	if (value == 0)
		return ("0");
	if (value == -2147483648)
		return ("-2147483648");
	if (value < 0)
	{
		sign = 1;
		value *= -1;
	}
	while (temp)
	{
		len++;
		temp /= 10;
	}
	len += sign;
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (sign == 1)
		number[0] = '-';
	number[len] = '\0';
	while (len-- > sign)
	{
		number[len] = value % 10 + '0';
		value /= 10;
	}
	return (number);
}