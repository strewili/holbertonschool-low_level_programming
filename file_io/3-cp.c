#include "main.h"

/**
 * close_file - closes file descriptor
 * @fd: file descriptor
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * error_read - prints read error
 * @file: file name
 */
void error_read(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}

/**
 * error_write - prints write error
 * @file: file name
 */
void error_write(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}

/**
 * open_files - opens source and destination files
 * @argv: argument vector
 * @file_from: source file descriptor
 * @file_to: destination file descriptor
 */
void open_files(char *argv[], int *file_from, int *file_to)
{
	*file_from = open(argv[1], O_RDONLY);
	if (*file_from == -1)
		error_read(argv[1]);

	*file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (*file_to == -1)
	{
		close_file(*file_from);
		error_write(argv[2]);
	}
}

/**
 * copy_file - copies content from one file to another
 * @file_from: source file descriptor
 * @file_to: destination file descriptor
 * @argv: argument vector
 */
void copy_file(int file_from, int file_to, char *argv[])
{
	ssize_t r, w;
	char buffer[1024];

	while ((r = read(file_from, buffer, 1024)) > 0)
	{
		w = write(file_to, buffer, r);
		if (w == -1 || w != r)
		{
			close_file(file_from);
			close_file(file_to);
			error_write(argv[2]);
		}
	}

	if (r == -1)
	{
		close_file(file_from);
		close_file(file_to);
		error_read(argv[1]);
	}
}

/**
 * main - copies content from one file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	open_files(argv, &file_from, &file_to);
	copy_file(file_from, file_to, argv);

	close_file(file_from);
	close_file(file_to);

	return (0);
}
