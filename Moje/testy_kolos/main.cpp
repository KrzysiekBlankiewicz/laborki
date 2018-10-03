#include <iostream>

using namespace std;

/* int q(int n)
{
    int wynik = (n <= 1)? n:n-2*q(n-1)+q(n-2);
    if(wynik < 0) throw wynik;
    return wynik;
}

int main(int argc, char **argv)
try {
	for(int i = 0; ; ++i)
        cout << i <<":"<<q(i) << endl;
}

catch(int e)
{
    cout << "mam: " << e << endl;
} */


/*  struct S{int s;};
class C{int c;};

struct SSC: S, C {int x;};
class CCS: S, C{int x;};

int main()
{
    SSC ssc;
    CCS ccs;
    //ssc.c = 1;
    ssc.s = 2;
    ssc.x = 3;
    //ccs.c = 1;
    //ccs.s = 2;
    ccs.x = 3;
} */

/*  struct Punkt
{
    int x, y;
    Punkt(int xx = 0): x(xx), y(xx){cout << "y" << endl;};
    Punkt(int xx, int yy): x(xx), y(yy){cout << "x"<< endl;};
};

void print(Punkt e)
{
    cout << e.x << e.y << endl;     
}

int main()
{
    Punkt p1, p2;
    p1 = 12, 2;
    p2 = 67;
    print(p1);
    print(p2);
} */

/* #define P(x) cout << (x) << " "

class A{
    public: A() { P("A");};
};

class B: virtual A{
    public: B() { P("B");};
}; 

class C: A{
    public: C() { P("C");};
};

class D: B, virtual A{
    static D d;
    public: D() { P("D");};
};
D D::d;
*/
class A
{
    A(int x, double y){};
public:
    A(int xx, double yy, int z):A(xx, yy){};
};

int main() 
{
    A a(2, 3, 1);
}