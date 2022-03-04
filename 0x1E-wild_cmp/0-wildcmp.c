#include "holberton.h"

/**
 * wildcmp - compares two strings
 * @a1: string to compare against
 * @a2: string to compare
 *
 * Return: 1 if identical, 0 otherwise
 */
int wildcmp(char *a1, char *a2)
{
	if (*a1 == *a2 && *a1 != '\0')
	{
		return (wildcmp(a1 + 1, a2 + 1));
	}
	if (*a1 == *a2)
	{
		return (1);
	}
	if (*a2 == '*' && *(a2 + 1) != *a1 && *(a2 + 1) != '*')
	{
		return (wildcmp(a1 + 1, a2));
	}
	if (*a2 == '*' && *(a2 + 1) != *a1 && *(a2 + 1) == '*')
	{
		return (wildcmp(a1, a2 + 1));
	}
	if (*a2 == '*' && wildcmp(a1, a2 + 1) == 0)
	{
		return (wildcmp(a1 + 1, a2));
	}
	if (*a2 == '*' && wildcmp(a1, a2 + 1) == 1)
	{
		return (1);
	}
	return (0);
}
