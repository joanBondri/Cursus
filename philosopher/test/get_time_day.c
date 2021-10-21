#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	struct timeval elapsed;

	(void)gettimeofday(&elapsed, NULL);
	printf("elapsed = %li\n", elapsed.tv_sec);
	printf("elle ont essayer = %i\n", elapsed.tv_usec);
	return (0);
}
