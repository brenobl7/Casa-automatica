#include <stdio.h>
#include <math.h>

int main()
{
    float a ;
    float b ;
    float c ;
    char p;
    do
    {
        //scanf do a b c
        printf("digite o A");
        scanf(" %d",&a);
        printf("digite o B");
        scanf(" %d",&b);
        printf("digite o C");
        scanf(" %d",&c);
        float delta, x, x1, x2;

        while(a == 0)
        {
            printf("a = 0, Nao esta certo");

        }


        // Cálculo do delta
        delta = pow(b, 2) - 4 * a * c;
        printf("Delta = %.4f \n", delta);

        // Cálculo das raízes
        if (delta > 0)
        {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("As raízes são: x1 = %.4f e x2 = %.4f\n", x1, x2);
        }
        else if (delta == 0)
        {
            x = (-b + sqrt(delta)) / (2 * a);
            printf("A raiz é: x = %.4f\n", x);
        }
        else
        {
            printf("As raízes são complexas:\n");
        }
        printf("quer fazer mais uma vez?(s/n)");
        scanf(" %c",&p);
//while para fechar o do
    }while(p == 's'|| p == 's');
    return 0;
}
