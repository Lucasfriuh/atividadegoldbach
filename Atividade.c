#include <stdio.h>

int ehprimo(int num)
{
    if (num <= 1)
        return 0;
    if (num <= 3)
        return 1;
    if (num % 2 == 0 || num % 3 == 0)
        return 0;

    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }

    return 1;
}

void goldbach_conjectura(int n)
{
    if (n <= 2 || n % 2 != 0)
    {
        printf("A conjectura de Goldbach se aplica apenas a numeros pares maiores que 2.\n");
        return;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (ehprimo(i) && ehprimo(n - i))
        {
            printf("%d + %d\n", i, n - i);
            return;
        }
    }
}

int main()
{
    int n;
    printf("Digite um numero par maior que 2: ");
    scanf("%d", &n);

    goldbach_conjectura(n);

    return 0;
}
