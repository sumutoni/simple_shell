#include "shell.h"

int err_no = 0;
/**
 * _itoa - converts an int to a string
 * @err_no: error count
 * @err: string to store int
 *
 * Return: string value of int
 */
char *_itoa(int err_no, char *err)
{
	char c;

	if (err_no == 0)
		*err = '0';
	if (err_no == 1)
		*err = '1';
	else
	{
		if ((err_no / 10) > 0)
		{
			c = (err_no % 10) + '0';
			err = _itoa(err_no / 10, err);
			err++;
			*err = c;
			return (err);
		}
		else
		{
			*err = (err_no + '0');
			return (err);
		}
	}
	return (err);
}
/**
 * p_error - prints error message
 * @com: entered command
 */
void p_error(char *com)
{
	int size, size1;
	char *str, *str1, *err;

	err = _calloc(sizeof(char), 10);
	err_no++;
	err = _itoa(err_no, err);
	str1 = _strcat(arg, ": ");
	str1 = _strcat(str1, err);
	str1 = _strcat(str1, ": ");
	size = strlen(str1);
	str = _strcat(com, ":");
	str = _strcat(str, " not found");
	size1 = strlen(str);
	write(1, str1, size);
	write(1, str, size1);
	_putchar('\n');
}
