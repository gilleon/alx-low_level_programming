#include "main.h"

/**
 * append_text_to_file - function to add text to the end of a file
 * @filename: name of file argv
 * @text_content: string to add argv
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fdes, rstatus, i;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);

	fdes = open(filename, O_APPEND | O_WRONLY);
	if (fdes == -1)
		return (-1);

	for (i = 0; text_content[i] != '\0'; i++)
		;
	rstatus = write(fdes, text_content, i);
	if (rstatus == -1)
		return (-1);

	close(fdes);
	return (1);
}
