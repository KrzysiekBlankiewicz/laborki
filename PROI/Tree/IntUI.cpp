
#include "Tree.h"
#include <iostream>

using namespace std;

const int ZEROINASCII = 48;

class IntUI
{
    Tree<int>* drzewo;
public:
    IntUI(){
        drzewo = new Tree<int>;
    }
    ~IntUI(){
        delete drzewo;
    }
    void startProgram()
    {
        string contin = "help";
        while(contin != "end"){
            try{
                if(contin == "help"){
                    help();
                }
                else if(contin == "dodaj_element"){
                    dodaj();
                }
                else if(contin == "dodaj_ciag"){
                    dodajCiag();
                }
                else if(contin == "usun_element"){
                    usun();
                }
                else if(contin == "znajdz_element"){
                    znajdz();
                }
                else if(contin == "pokaz_drzewo"){
                    pokaz();
                }
                else if(contin == "wyczysc_drzewo"){
                    czysc();
                }
                else cout << "Bledna instrukcja, ale..." << endl;
            }
            catch(Exept& e){
                cout << endl << e.what() << endl;
            }
            cout << endl << "Slucham...";
            cin >> contin;
            cout << endl;
        }
    }
private:
    void help(){
                cout << "-----------------------------------------------------" << endl;
                cout << "Wprowadź...		 ...aby:" << endl;
                cout << "	end 			zakończyć" << endl;
                cout << "	dodaj_element	dodać element do drzea" << endl;
                cout << "	dodaj_ciag	    dodać wiele elementów" << endl;
                cout << "	usun_element	usunąć element z drzewa" << endl;
                cout << "	znajdz_element	wyświetlić ścieżkę do elementu" << endl;
                cout << "	pokaz_drzewo	wyswietlić całe drzewo" << endl;
                cout << "	wyczysc_drzewo	usunąć wszystkie elementy z drzewa" << endl;
                //cout << "	zapisz_drzewo	zapisac ostatni zakup do pliku" << endl;
                cout << "-----------------------------------------------------" << endl;
    }

    void dodaj(){
        drzewo->insert(askForInt());
    }
    void dodajCiag(){
        string s = askForString();
        for(unsigned i = 0; i < s.length(); i++){
            drzewo->insert((int)s[i] - ZEROINASCII);
        }
    }
    void usun(){
        drzewo->erase(askForInt());
    }
    void pokaz(){
        drzewo->show();
    }
    void czysc(){
        drzewo->clear();
    }
    void znajdz(){
        drzewo->find(askForInt());
    }
    int askForInt(){
        int x;
        cout << "Poproszę o liczbę" << endl;
        if(!(cin >> x)){
            cin.clear();
            throw Exept("Błąd danych");
        }
        return x;
    }
    string askForString(){
        string x;
        cout << "Poproszę o ciąg liczb" << endl;
        if(!(cin >> x)){
            cin.clear();
            throw Exept("Błąd danych");
        }
        return x;
    }
};

/*using namespace std;
#include <string>
#include <iostream>
#include "IntUI.h"

IntUI::IntUI()
{
    drzewo = new Tree<int>;
}

IntUI::~IntUI()
{
    delete drzewo;
}

void IntUI::startProgram()
{
    string contin = "help";
    while(contin != end){
        if(contin == "help"){
			help();
		}
		else if(contin == "dodaj_element"){
			dodaj();
		}
		else if(contin == "usun_element"){
			usun();
		}
		else if(contin == "znajdz_element"){
			znajdz();
		}
		else if(contin == "pokaz_drzewo"){
			pokaz();
		}
		else if(contin == "wyczysc_drzewo"){
			czysc();
		}
		else cout << "Bledna instrukcja, ale..." << endl;
        
		cout << endl << "Slucham...";
		cin >> contin;
		cout << endl;
    }
}

void IntUI::help(){
            cout << "-----------------------------------------------------" << endl;
			cout << "Wprowadź...		 ...aby:" << endl;
			cout << "	end 			zakończyć" << endl;
			cout << "	dodaj_element	dodać element do drzea" << endl;
			cout << "	usun_element	usunąć element z drzewa" << endl;
			cout << "	znajdz_element	wyświetlić ścieżkę do elementu" << endl;
			cout << "	pokaz_drzewo	wyswietlić całe drzewo" << endl;
			cout << "	wyczysc_drzewo	usunąć wszystkie elementy z drzewa" << endl;
			//cout << "	zapisz_drzewo	zapisac ostatni zakup do pliku" << endl;
			cout << "-----------------------------------------------------" << endl;
}

void IntUI::dodaj(){
    drzewo->insert(askForInt());
}
void IntUI::usun(){
    drzewo->erase(askForInt());
}
void IntUI::pokaz(){
    drzewo->show();
}
void IntUI::czysc(){
    drzewo->clear();
}
void IntUI::znajdz(){
    drzewo->find(askForInt());
}

int IntUI::askForInt(){
    int x;
    cout << "Poproszę o liczbę" << endl;
    cin >> x;
    return x;
}*/
