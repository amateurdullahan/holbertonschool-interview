#include "palindrome.h"

/**
  * is_palindrome - checks if integer is palindrome
  *
  * @n: integer to check
  *
  * Return: 1 if palindrome else 0
  */

int is_palindrome(unsigned long n)
{
    unsigned long int rem = 0;
    unsigned long int rev = 0;
    unsigned long int temp = n;

	if (n < 10)
	{
		return (1);
	}
	while (temp != 0)
	{
		rem = temp % 10;
		rev = rev * 10 + rem;
		temp /= 10;
	}
	if (rev == n)
	{
		return (1);
	}

	return (0);
}
