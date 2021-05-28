#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	//printf("|%-23p| %lli\n", NULL, (long long int)NULL);
	int		*p;
	char	*s = "";
	char	*s1 = "i";
	char	*s2 = "f";
	char	*s3 = "y";
	
	printf("pointer %d\n", sizeof(s));
	printf("long int %d\n", sizeof(long int));
	printf("long long int %d\n", sizeof(long long int));
	
	/*
	printf("%p \n", p);
	printf("%p\n", s);
	printf("%23p\n", s1);
	printf("%p\n", s2);
	printf("%p\n", s3);
	*/

	/*
	printf("0 : |%s|\n", "01234567890123456789");
	printf("1 : |%010.5s|\n", "01234567890123456789");
	printf("2 : |%-7.*s|\n", 2, "01234567890123456789");
	printf("3 : |%06.5s|\n", "01234567890123456789");
	printf("4 : |%010.0s|\n","01234567890123456789");
	printf("5 : |%.10s|\n", "01234567890123456789");
	printf("6 : |%0*.*s|\n", 7, 8, "01234567890123456789");
	printf("7 : |%0*.*s|\n", 8, 7, "01234567890123456789");
	printf("8 : |%.*s|\n", 12, "01234567890123456789");
	*/

	/*
	printf("|1 : %x|\n", 16);
	printf("|2 : %12x|\n", -54);
	printf("|3 : %0x|\n", 2147483647);
	printf("|4 : %-12x|\n", 54);
	printf("|5 : %-12.4x|\n", 54);
	printf("|6 : %12.4x|\n", 54);
	printf("|7 : %012.4x|\n", 54);
	printf("|8 : %12.13x|\n", 54);
	return (0);
	*/
}


