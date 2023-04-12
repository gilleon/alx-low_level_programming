#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _stringCompare - compare two strings
 * @string1: the first string argv
 * @string2: the second string argv
 * @numb: the max number of bytes to compare
 *
 * Return: 0 if the first numb bytes of string1 and string2 are equal, else 0
 */
int _stringCompare(const char *string1, const char *string2, size_t numb)
{
	for ( ; numb && *string1 && *string2; --numb, ++string1, ++string2)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
	}
	if (numb)
	{
		if (*string1)
			return (1);
		if (*string2)
			return (-1);
	}
	return (0);
}

/**
 * _closeFile - close a file descriptor exception
 * @fd: the file descriptor to close
 */
void _closeFile(int fd)
{
	if (close(fd) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close fd\n", 22);
	exit(98);
}

/**
 * _readFile - read from a file exception
 * @fd: the file descriptor to read from
 * @butter: the buffer to write to
 * @counter: the number of bytes to read
 */
void _readFile(int fd, char *butter, size_t counter)
{
	if (read(fd, butter, counter) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	_closeFile(fd);
	exit(98);
}

/**
 * elf_magic - print ELF magic
 * @buffer: the ELF header argv
 */
void elf_magic(const unsigned char *buffer)
{
	unsigned int i;

	if (_stringCompare((const char *) buffer, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}

	printf("ELF Header:\n  Magic:   ");

	for (i = 0; i < 16; ++i)
		printf("%02x%c", buffer[i], i < 15 ? ' ' : '\n');
}

/**
 * elf_class - print ELF class
 * @buffer: the ELF header
 *
 * Return: bit mode (32 or 64)
 */
size_t elf_class(const unsigned char *buffer)
{
	printf("  %-34s ", "Class:");

	if (buffer[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buffer[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buffer[EI_CLASS]);
	return (32);
}

/**
 * elf_data - print ELF data
 * @buffer: the ELF header
 *
 * Return: 1 if big endian, otherwise 0
 */
int elf_data(const unsigned char *buffer)
{
	printf("  %-34s ", "Data:");

	if (buffer[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buffer[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

/**
 * elf_version - print ELF version
 * @buffer: the ELF header
 */
void elf_version(const unsigned char *buffer)
{
	printf("  %-34s %u", "Version:", buffer[EI_VERSION]);

	if (buffer[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * elf_sabi - print ELF OS/ABI
 * @buffer: the ELF header
 */
void elf_sabi(const unsigned char *buffer)
{
	const char *os_table[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf("  %-34s ", "OS/ABI:");

	if (buffer[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}

/**
 * elf_abivers - print ELF ABI version
 * @buffer: the ELF header
 */
void elf_abivers(const unsigned char *buffer)
{
	printf("  %-34s %u\n", "ABI Version:", buffer[EI_ABIVERSION]);
}

/**
 * elf_type - print ELF type
 * @buffer: the ELF header
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_type(const unsigned char *buffer, int big_endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type;

	printf("  %-34s ", "Type:");

	if (big_endian)
		type = 0x100 * buffer[16] + buffer[17];
	else
		type = 0x100 * buffer[17] + buffer[16];

	if (type < 5)
		printf("%s\n", type_table[type]);
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else if (type >= ET_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * elf_start - print entry point address
 * @buffer: string containing the entry point address
 * @bit_mode: bit mode (32 or 64)
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_start(const unsigned char *buffer, size_t bit_mode, int big_endian)
{
	int address_size = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");

	if (big_endian)
	{
		while (address_size && !*(buffer))
			--address_size, ++buffer;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += address_size;

		while (address_size && !*(--buffer))
			--address_size;

		printf("%x", *buffer & 0xff);

		while (--address_size > 0)
			printf("%02x", *(--buffer) & 0xff);
	}

	printf("\n");
}

/**
 * main - copy a file's contents to another file
 * @count: the argument count
 * @val: the argument values
 *
 * Return: Always 0
 */
int main(int count, const char *val[])
{
	unsigned char buffer[18];
	unsigned int bit_mode;
	int big_endian;
	int fd;

	if (count != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(val[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
		exit(98);
	}

	_readFile(fd, (char *) buffer, 18);

	elf_magic(buffer);
	bit_mode = elf_class(buffer);
	big_endian = elf_data(buffer);
	elf_version(buffer);
	elf_sabi(buffer);
	elf_abivers(buffer);
	elf_type(buffer, big_endian);

	lseek(fd, 24, SEEK_SET);
	_readFile(fd, (char *) buffer, bit_mode / 8);

	elf_start(buffer, bit_mode, big_endian);

	_closeFile(fd);

	return (0);
}
