#include <stdio.h>

int main()
{
    int onlukSayi = 0, val = 0, kalan, ikili;

    scanf("%d", &ikili);

    while (ikili != 0) // 1001
    {
        kalan = ikili % 10;
        ikili /= 10;
        int tmp = 1;

        for (int i = 0; i < val; i++)
        {
            tmp *= 2;
        }
        onlukSayi += kalan * tmp;
        ++val;
    }

    printf("%d\n", onlukSayi);

    return 0;
}