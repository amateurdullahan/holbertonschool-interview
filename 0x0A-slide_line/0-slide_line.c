#include "slide_line.h"

/**
  * slide_line - slide line
  * @line: line to slide
  * @size: size of line
  * @direction: left or right
  *
  * Return: 1 success, 0 failure
  */

int slide_line(int *line, size_t size, int direction)
{
	int linesize = size;

	if (line == NULL)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		shift_left(line, linesize);
		merge_left(line, linesize);
		shift_left(line, linesize);
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		shift_right(line, linesize);
		merge_right(line, linesize);
		shift_right(line, linesize);
		return (1);
	}
	return (0);
}

/**
  * shift_left - shift left
  * @line: line
  * @size: size
  */

void shift_left(int *line, int size)
{
	int i, idx;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == 0)
		{
			idx = i + 1;
			while (line[idx] == 0 && idx < size - 1)
			{
				idx += 1;
			}
			line[i] = line[idx];
			line[idx] = 0;
		}
	}
}

/**
  * merge_left - combine left
  * @line: line
  * @size: size
  */

void merge_left(int *line, int size)
{
	int i;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}
}

/**
  * shift_right - shift right
  * @line: line
  * @size: size
  */

void shift_right(int *line, int size)
{
	int i, idx;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == 0)
		{
			idx = i - 1;
			while (line[idx] == 0 && idx > 0)
				idx -= 1;
			line[i] = line[idx];
			line[idx] = 0;
		}
	}
}

/**
  * merge_right - combine right
  * @line: line
  * @size: size
  */

void merge_right(int *line, int size)
{
	int i;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}
}
