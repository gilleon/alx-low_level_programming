#include "main.h"

/**
 * read_textfile - Read a text file and
 * print to POSIX stdout
 * @filename: char string arg
 * @letters: number of letters to read argv
 * Return: he actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int filedata;
	ssize_t rcount, wcount;
	char *load;

	if (filename == NULL)
		return (0);

	filedata = open(filename, O_RDWR);
	if (filedata == -1)
	{
		return (0);
	}
	
	load = malloc(sizeof(char) * letters);
	if (load == NULL)
	{
		free(load);
		return (0);
	}
	rcount = read(filedata, load, letters);
	if (rcount == -1)
	{
		return (0);
	}

	wcount = write(STDOUT_FILENO, load, rcount);
	if (wcount == -1 || rcount != wcount)
	{
		return (0);
	}
	free(load);

	close(filedata);
	return (wcount);
}
