#include "main.h"

#define MAXSIZE 1024
#define SE STDERR_FILENO

/**
 * main -  copies the content of a file to another file
 * @argv: argument count
 * @args: arguments as strings
 * Return: 0 when successful
 */
int main(int argv, char *args[])
{
	int input_fd, output_fd, istatus, ostatus;
	char buf[MAXSIZE];
	mode_t mode;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	if (argv != 3)
		dprintf(SE, "Usage: cp file_from file_to\n"), exit(97);
	input_fd = open(args[1], O_RDONLY);
	if (input_fd == -1)
		dprintf(SE, "Error: Can't read from file %s\n", args[1]), exit(98);
	output_fd = open(args[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (output_fd == -1)
		dprintf(SE, "Error: Can't write to %s\n", args[2]), exit(99);
	do {
		istatus = read(input_fd, buf, MAXSIZE);
		if (istatus == -1)
		{
			dprintf(SE, "Error: Can't read from file %s\n", args[1]), exit(98);
		}
		if (istatus > 0)
		{
			ostatus = write(output_fd, buf, (ssize_t) istatus);
			if (ostatus == -1)
			{
				dprintf(SE, "Error: Can't write to %s\n", args[2]), exit(99);
			}
		}
	} while (istatus > 0);
	istatus = close(input_fd);
	if (istatus == -1)
	{
		dprintf(SE, "Error: Can't close fd %d\n", input_fd), exit(100);
	}
	ostatus = close(output_fd);
	if (ostatus == -1)
	{
		dprintf(SE, "Error: Can't close fd %d\n", output_fd), exit(100);
	}
	return (0);
}
