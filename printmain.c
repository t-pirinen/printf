
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main()
{
	char			character = 'x';

	char			*string = "hello world";

	char			*pointer = string;

	int				digit = 1234;

	unsigned int	unsigned_digit = UINT32_MAX;

	unsigned int	hex = 0x15aefc25;

	unsigned int	HEX = 0x15AEFC25;


	   printf("%c\n", character);
	ft_printf("%c\n", character);

	   printf("%s\n", string);
	ft_printf("%s\n", string);

	   printf("%p\n", pointer);
	ft_printf("%p\n", pointer);
	   printf("%p\n", pointer);
	ft_printf("%p\n", pointer);

	   printf("%d\n", digit);
	ft_printf("%d\n", digit);
	   printf("%d\n", INT32_MIN);
	ft_printf("%d\n", INT32_MIN);
	   printf("%d\n", INT32_MAX);
	ft_printf("%d\n", INT32_MAX);
	   printf("%d\n", -2147483649);
	ft_printf("%d\n", -2147483649);
	   printf("%d\n", 2147483648);
	ft_printf("%d\n", 2147483648);

	   printf("%u\n", unsigned_digit);
	ft_printf("%u\n", unsigned_digit);
	
	   printf("%x\n", hex);
	ft_printf("%x\n", hex);

	   printf("%X\n", HEX);
	ft_printf("%X\n", HEX);

	   printf("%%\n"); // PERCENT SIGN
	ft_printf("%%\n"); // PERCENT SIGN

	   printf("%c %s %p %d %u %x %X %%\n", character, string, pointer, digit, unsigned_digit, hex, HEX);
	ft_printf("%c %s %p %d %u %x %X %%\n", character, string, pointer, digit, unsigned_digit, hex, HEX);

	   printf("%r\n");
	ft_printf("%r\n");

}