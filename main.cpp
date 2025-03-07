#include <iostream>
#include "nrtelefon.h"

using namespace std;


int main()
{
    Agenda *agenda = new Agenda;
    init_agenda(agenda);

    Nr_Telefon *nr1 = new Nr_Telefon;
    Nr_Telefon *nr2 = new Nr_Telefon;

    init_nr(nr1, "Mihai Andrei", 1234);
    init_nr(nr2, "Mihai Gabriel", 1234);

    insert_nr(agenda, *nr1);
    insert_nr(agenda, *nr1);
    insert_nr(agenda, *nr2);

    show_agenda(*agenda);


    delete agenda;
    return 0;
}