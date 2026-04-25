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
 * error_exit - prints error message and exits
 * @code: exit code
 * @file: file name or NULL
 */
void error_exit(int code, char *file)
{
	if (code == 97)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	else if (code == 98)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	else if (code == 99)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(code);
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
		error_exit(98, argv[1]);

	*file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (*file_to == -1)
	{
		close_file(*file_from);
		error_exit(99, argv[2]);
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
			error_exit(99, argv[2]);
		}
	}

	if (r == -1)
	{
		close_file(file_from);
		close_file(file_to);
		error_exit(98, argv[1]);
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
		error_exit(97, NULL);

	open_files(argv, &file_from, &file_to);
	copy_file(file_from, file_to, argv);

	close_file(file_from);
	close_file(file_to);

	return (0);
}
