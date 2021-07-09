#include "menger.h"

void menger(int level)
{
	int i, i2, hole;
	int size = pow(3, level);
	char print;

	if (level == 0)
		printf("#\n");
	if (level == 1)
		printf("###\n# #\n###\n");
	if (level > 1)
	{
		for (i = 0; i < size; i++)
		{
			for (i2 = 0; i2 < size; i2++)
			{
				print = '#';
				for (hole = 1; hole < size; hole *= 3)
				{
					if ((i / hole) % 3 == 1 && (i2 / hole) % 3 == 1)
					{
						print = ' ';
					}
				}
				printf("%c", print);
			}
			printf("\n");
		}
	}
}
