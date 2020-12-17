#include <unistd.h>

int main (int argc, char **argv)
{
	int used[127] = {0}, i =3, j = 0;

	if (argc == 3)
	{
		while (--i > 0)
		{
			while (argv[i][j])
			{
				if (used[(int)argv[i][j]] == 2 && i == 1)
					write(1, &argv[i][j], 1);
				used[(int)argv[i][j++]] = i;
			}
			j = 0;
		}
	}
	write (1, "\n", 1);
	return (0);
}