#include<stdio.h>
#include<math.h>

int factorial(int v)
{
    int f = 1;
    while(v != 1)
    {
        f = f*v;
        v = v--;
    }
    return f;
}
double countSin(double n, double e)
{
    double sin = 0;//obliczany sinus
    //double sinAd;
    double a = 0;//zmienna pomocnicza
    double r = 1;//zmienna pomocnicza
    int zmiennaDoZmienianiaZnaku = 1;
    while(1)
    {
        r = r + 2;
        a = pow(n, r)/factorial(r);//obliczam kolejny człon
        printf("%f\n",  a);
        int i;
        for(i = 1; i <= 2; i++ )//if(a > e)//sprawdzam dokładność
        {
            sin = sin + a * zmiennaDoZmienianiaZnaku;

        //else break;
        zmiennaDoZmienianiaZnaku = -zmiennaDoZmienianiaZnaku;
        }
        break;
    }
    return sin;
}

int main()
{
    double z = 0;
    /*while(z == 0)
        puts("Poproszę o x(policzę z niego sin) oraz e(to żądana dokładność) rozdzielone spacją.\n");
        int x, p;
        scanf("%d %d\n", &x, &p);
        printf("sin(x) = %d\n", countSin(x, p));*/
    int t;
    printf("%d",  t = countSin(3.14, 0.4));

}
