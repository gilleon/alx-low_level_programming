#include <unistd.h>
#include "main.h"

int _putchar(char c)
{
	write(1, &c, 1);
}
