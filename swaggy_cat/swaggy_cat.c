#include <stdio.h>
#include <unistd.h>

void	swaggy_cat(void)
{
	int		i;
	int		j;
	char	s[] = "    /\\       /\\ \n   /  \\_____/  \\ \n  /             \\ \n (   ()    ()    ) \n(                 ) \n (       Y       ) \n  \\   \\_/\\_/    / \n   \\___________/\n\n\n";

	i = 0;
	j = 0;
	while (1)
	{
		if (i == 1000000)
			i = 0;
		if (i ==  1)
		{
			if (s[j] == '\0')
				j = 0;
			write(1, &s[j], 1);
			j++;
		}
		i++;
	}
}

int		main(void)
{
	swaggy_cat();
	return (0);	
}
