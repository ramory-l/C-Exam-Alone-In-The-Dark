#include <unistd.h>

int		ft_match(char b1, char b2)
{
	if (b1 == '(' && b2 == ')')
		return (1);
	if (b1 == '{' && b2 == '}')
		return (1);
	if (b1 == '[' && b2 == ']')
		return (1);
	return (0);
}

int	brackets(char *argv, char *stack)
{
	int i;
	int top;

	i = 0;
	top = -1;
	while (argv[i])
	{
		if (argv[i] == '(' || argv[i] == '{' || argv[i] == '[')
		{
			top++;
			stack[top] = argv[i];
		}
		if (argv[i] == ')' || argv[i] == '}' || argv[i] == ']')
		{
			if (!stack[top])
				return (0);
			else if (ft_match(stack[top], argv[i]))
			{
				stack[top] = 0;
				top--;
			}
			else
				return (0);
		}
		i++;
	}
	if (stack[0] == 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int i;
	char stack[512];

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (brackets(argv[i], stack))
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}