#include "holberton.h"

/**
 * error_get_alias - error message for alias in get_alias.
 * @args: type array of args that is passed to the command.
 * Return: error.
 */
char *error_get_alias(char **args)
{
	int length;
	char *error;

	length = _strlen(prgname) +  _strlen(args[0]) + 14;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		return (NULL);
	}
	_strcpy(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": not found\n");
	return (error);
}
/**
 * error_env - error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *error_env(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_syntax - generic error message for syntax error.
 * @args: type array of args that is passed to the command.
 * Return: error.
 */
char *error_syntax(char **args)
{
	int count = 0;
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(count);
	if (ver_str == 0)
		return (NULL);
	length = _strlen(prgname) + _strlen(ver_str) + _strlen(args[0]) + 32;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, prgname);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": syntax error: ");
	_strcat(error, args[0]);
	_strcat(error, " unexpected\n");
	free(ver_str);
	return (error);
}
/**
 * error_permission - generic error message for permission.
 * @args: type array of args that is passed to the command.
 * Return: error.
 */
char *error_permission(char **args)
{
	int count = 0;
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(count);
	if (ver_str == 0)
		return (NULL);
	length = _strlen(prgname) + _strlen(ver_str) + _strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, prgname);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": permission denied\n");
	free(ver_str);
	return (error);
}
