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
	if(x < 17) f = pow(n, x)/factorial(x);// factorial(17) oraz kilka nast�pnych z nieznanychmi przyczyn dawa�o liczb� ujemn�. Dlatego x<17.
	if((x-1)%4 == 0);
	else f = -f;
    return f;
}

int checkAcc(double _f, double _e)//sprawdza, czy potrzeba liczy� jeszcze dokladniej
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
        puts("Poprosz� o liczb� z przedzia�u (-3.14, 3.14) (policz� z niej sin)...\n");
        scanf("%lf", &x);
        if(x < -3.14 || x > 3.14)
        {
          puts("Prosi�em o konkretny zakres. Trzeba b�dzie zaczyna� od nowa...");
          return 0;
        }
        puts("... oraz o ��dan� dok�adno�� jako liczb� zmiennoprzecinkow�.\n");
        scanf("%lf", &e);
        printf("sin(x) = %f\n", countSin(x, e));
        puts("Czy �yczy�by Pan sobie policzy� jeszcze jednego sinusika (Jesli tak, to prosz� o 1, nie to o 0)?\n");
        scanf("%d", &z);
    }

}
