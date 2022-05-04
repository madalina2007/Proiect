#include <stdlib.h>
#include <stdio.h>

int random()
{
	int mic = 0, mare = 99,x;
	x = (rand() % (mare - mic + 1)) + mic;
	return x;
}

int main()
{
	int optiune, matrice[100][100], i, j, n, m, sumap = 0, sumas = 0, minimp = 1001, maximp = -99, minims = 1001, maxims = -99;
	srand(time(0));
	do
	{
		printf("Operatii asupra matricilor.\n");
		printf("0. Iesire.\n");
		printf("1. Generare matrice aleatoriu.\n");
		printf("2. Calcularea sumei elementelor aflate pe diagonala principala.\n");
		printf("3. Calcularea sumei elementelor aflate pe diagonala secundara.\n");
		printf("4. Aflarea minimului si maximului elementelor aflate sub diagonala principala.\n");
		printf("5. Aflarea minimului si maximului elementelor aflate sub diagonala secundara.\n");
		printf("\n");
		printf("Optiunea: ");
		scanf("%d", &optiune);
		switch (optiune)
		{
			case 0: printf("Iesire din program.\n");
					printf("\n");
					break;

			case 1: printf("Numarul de linii: ");
					scanf("%d", &n);
					printf("Numarul de coloane: ");
					scanf("%d", &m);

					for (i = 1; i <= n; i++)
						for (j = 1; j <= m; j++)
							matrice[i][j] = random();
					printf("Matricea a fost generata cu succes.\n");

					printf("\n");
					printf("Matricea:\n");
					for (i = 1; i <= n; i++)
					{
						for (j = 1; j <= m; j++)
							printf("%d ", matrice[i][j]);
						printf("\n");
					}
					printf("\n");
					break;

			case 2: for (i = 1; i <= n; i++)
						for (j = 1; j <= m; j++)
							if (i == j)
								sumap = sumap + matrice[i][j];

					printf("Suma elementelor de pe diagonala principala este: %d.\n", sumap);
					printf("\n");
					break;

			case 3: for (i = 1; i <= n; i++)
						sumas = sumas + matrice[i][n - i + 1];

					printf("Suma elementelor de pe diagonala secundara este: %d.\n", sumas);
					printf("\n");
					break;

			case 4: for (i = 1; i <= n; i++)
					{
						for (j = 1; j <= m; j++)
						{
							if (i > j)
							{
								if (matrice[i][j] < minimp)
									minimp = matrice[i][j];
								if (matrice[i][j] > maximp)
									maximp = matrice[i][j];
							}
						}
					}

					printf("Minimul elementelor de sub diagonala principala este %d.\n", minimp);
					printf("Maximul elementelor de sub diagonala principala este %d.\n", maximp);
					printf("\n");
					break;

			case 5: for (i = 1; i <= n; i++)
					{
						for (j = 1; j <= m; j++)
						{
							if (j>n-i+1)
							{
								if (matrice[i][j] < minims)
									minims = matrice[i][j];
								if (matrice[i][j] > maxims)
									maxims = matrice[i][j];
							}
						}
					}

					printf("Minimul elementelor de sub diagonala secundara este %d.\n", minims);
					printf("Maximul elementelor de sub diagonala secundara este %d.\n", maxims);
					printf("\n");
					break;

			default: printf("Optiunea nu este corecta.\n");
					 printf("\n");
					 break;
		}
	} while (optiune != 0);
	return 0;
}