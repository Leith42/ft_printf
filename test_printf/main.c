#include "test.h"
#include "test2.h"
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int s = 8111;

	printf("%+9d\n", s);
	ft_printf("%+9d\n", s);
	return 0;
}
