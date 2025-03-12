#include <iostream>
#include <stdio.h>
#include "nrtelefon.h"

using namespace std;


int main()
{
    Agenda *agenda = new Agenda;
    init_agenda(agenda);

    size_t op;

    cout << "Alegeti o optiune: " << endl;
    cout << "  1. Adaugare numar in agenda" << endl;
    cout << "  2. Cautare persoana in agenda" << endl;
    cout << "  0. Iesire" << endl;

    cout << "Optiune: ";
    cin >> op;

    while (op)
    {
        switch (op)
        {
            case 0:
                break;
            case 1:
                {
                    char *nume = new char[100];
                    cout << "Nume: ";
                    cin >> nume;
                    
                    unsigned long nr;
                    cout << "Numar telefon: ";
                    scanf("%lu", &nr);
                    
                    Nr_Telefon *numar = new Nr_Telefon;
                    init_nr(numar, nume, nr);
                    insert_nr(agenda, *numar);
                    show_agenda(*agenda);
                    break;
                }
            
            case 2:
                {
                    char nume[100] = {0};
                    cout << "Nume: ";
                    cin >> nume;
                    cout << nume;

                    const unsigned long nr = search_nr(*agenda, nume);
                    if (nr == 0) cout << "Nu s-a putut gasi persoana!" << endl;
                    else cout << nume << ": " << nr << endl;
                    break;
                }
            
            default:
                cout << "Optiune invalida" << endl;
                break;
        }
        cout << endl;
        cout << "Alegeti o optiune: " << endl;
        cout << "  1. Adaugare numar in agenda" << endl;
        cout << "  2. Cautare persoana in agenda" << endl;
        cout << "  0. Iesire" << endl;
    
        cout << "Optiune: ";
        cin >> op;
    }

    delete agenda;
    return 0;
}