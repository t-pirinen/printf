
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main()
{
	char	*s;

	s = "hello";

	printf("%s\n", s);

	ft_printf("%c\n", 'c');

	ft_printf("%s\n", s);
}