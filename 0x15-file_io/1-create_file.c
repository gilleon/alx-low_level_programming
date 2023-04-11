#include "main.h"

/**
 * create_file - create a file
 * @filename: filename argv
 * @text_content: string argv
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fdesc, rstat, i;

	if (filename == NULL)
	{
		return (-1);
	}

	fdesc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fdesc == -1)
		return (-1);

	if (text_content)
	{
		for (i = 0; text_content[i] != '\0'; i++)
			;
		rstat = write(fdesc, text_content, i);
		if (rstat == -1)
			return (-1);
	}

	close(fdesc);
	return (1);
}
