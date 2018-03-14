#include<stdio.h>
#include<math.h>

int factorial(int v)//liczy v!
{
    int f = 1;
    while(v != 1)
    {
        f = f*v;
        v = v-1;
    }d
    return f;
}

double generateFactor(double n, int x)//generuje kolejne czynniki
{
	double f = 0;
	if(x < 17) f = pow(n, x)/factorial(x);// factorial(17) oraz kilka nastêpnych z nieznanychmi przyczyn dawa³o liczbê ujemn¹. Dlatego x<17.
	if((x-1)%4 == 0);
	else f = -f;
    return f;
}

int checkAcc(double _f, double _e)//sprawdza, czy potrzeba liczyæ jeszcze dokladniej
{
	if(fabs(_f) > _e) return 1;
	else return 0;
}

double countSin(double n, double e)
{
	double sin = 0;//obliczany sinus
	double f;//czynnik
	int i = 1;//interator
	while(1)
	{
		f = generateFactor(n, i);
        if(checkAcc(f, e))
		{
			sin = sin + f;
		}
		else break;
		i = i+2;

	}
	return sin;
}

int main()
{
    int z = 1;// z daje mozliwosc policzenia kilku sinusow
    while(z == 1)
    {
        double x;
        double e;
        puts("Poproszê o liczbê z przedzia³u (-3.14, 3.14) (policzê z niej sin)...\n");
        scanf("%lf", &x);
        if(x < -3.14 || x > 3.14)
        {
          puts("Prosi³em o konkretny zakres. Trzeba bêdzie zaczynaæ od nowa...");
          return 0;
        }
        puts("... oraz o ¿¹dan¹ dok³adnoœæ jako liczbê zmiennoprzecinkow¹.\n");
        scanf("%lf", &e);
        printf("sin(x) = %f\n", countSin(x, e));
        puts("Czy ¿yczy³by Pan sobie policzyæ jeszcze jednego sinusika (Jesli tak, to proszê o 1, nie to o 0)?\n");
        scanf("%d", &z);
    }

}
