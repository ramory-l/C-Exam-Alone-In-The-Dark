#include <stdio.h>
#include <stdlib.h>

int	ft_operate(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	if (c == '/')
	{
		if (b == 0)
			return (-2147483648);
		return (a / b);
	}
	if (c == '%')
	{
		if (b == 0)
			return (-2147483648);
		return (a % b);
	}
	return (-2147483648);
}

int	ft_isop(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int	ft_isnum(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	return (0);
}

void	rpn_calc(char *argv, int *stack)
{
	int i;
	int top;

	i = 0;
	top = -1;
	while (argv[i])
	{
		if (ft_isnum(&argv[i]))
		{
			top++;
			stack[top] = atoi(&argv[i]);
			while (argv[i] != ' ' && argv[i])
				i++;
		}
		if (ft_isop(argv[i]))
		{
			if (top > 0)
			{
				if ((stack[top - 1] = ft_operate(stack[top - 1], stack[top], argv[i])) == -2147483648)
				{
					printf("Error\n");
					return ;
				}
				top--;
			}
			else
			{
				printf("Error\n");
				return ;
			}
		}
		i++;
	}
	if (!top)
		printf("%d\n", stack[top]);
	else
		printf("Error\n");
}

int	main(int argc, char *argv[])
{
	int stack[512];

	if (argc == 2)
		rpn_calc(argv[1], stack);
	else
		printf("Error\n");
	return (0);
}