#include "sandpiles.h"

/**
 * sandpiles_sum - sum of two sandpiles
 * @grid1: Left grid
 * @grid2: Right grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (!check_stability(grid1))
	{
		printf("=\n");
		print_gridd(grid1);
		tumble(grid1);
	}
}


/**
 * check_stability - checks if grid is stable
 * @grid: grid to check
 * Return: true if stable, false if not
 */

bool check_stability(int grid[3][3])
{
	bool is_stable = true;
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				is_stable = false;
				break;
			}
		}
	}

	return (is_stable);
}

/**
 * print_gridd - Print 3x3 grid
 * @grid: 3x3 grid
 */

void print_gridd(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * tumble - tumbles a sandpile grid
 * @grid: grid to tumble
 */

void tumble(int grid[3][3])
{
	int array[9][2];
	int i, j, arr_i = 0, arr_j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				array[arr_i][0] = i;
				array[arr_i][1] = j;
				arr_i++;
			}
		}
	}
	for (arr_j = 0; arr_j < arr_i; arr_j++)
	{
		i = array[arr_j][0];
		j = array[arr_j][1];
		grid[i][j] -= 4;
		if (i != 0)
		{
			grid[i - 1][j] += 1;
		}
		if (i != 2)
		{
			grid[i + 1][j] += 1;
		}
		if (j != 0)
		{
			grid[i][j - 1] += 1;
		}
		if (j != 2)
		{
			grid[i][j + 1] += 1;
		}
	}
}
