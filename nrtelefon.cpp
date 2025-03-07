#include <iostream>
#include <cstring>
#include "nrtelefon.h"

using namespace std;

void init_nr(Nr_Telefon *& nr, const char * nume, unsigned long numar)
{
    if (nr == nullptr)
    {
        std::cout << "Pointer la nr null \n";
        nr = new Nr_Telefon;
    }

    nr->next = nullptr;
    nr->nume = new char[strlen(nume)];
    strncpy(nr->nume, nume, strlen(nume));
    nr->nr = numar;
}


void init_agenda(Agenda *& agenda)
{
	if (agenda == nullptr)
    {
        std::cout << "Pointer la agenda null \n";
        agenda = new Agenda;
    }

    agenda->cap = new Nr_Telefon;
    agenda->cap->nr = 0;
    agenda->cap->nume = nullptr;
    agenda->cap->next = nullptr;
    agenda->len = 1;

}


void insert_nr(Agenda *& agenda, Nr_Telefon nr)
{
    if (agenda == nullptr)
    {
        init_agenda(agenda);
        agenda->cap->nr = nr.nr;
        agenda->cap->nume = nr.nume;
        agenda->cap->next = nullptr;

        return;
    }

    if (agenda->len == 1 && agenda->cap->nume == nullptr)
    {
        init_nr(agenda->cap, nr.nume, nr.nr);
        return;
    }

    Nr_Telefon *p = agenda->cap;
    while (p->next != nullptr && strcmp(nr.nume, p->next->nume) > 0)
    {
        p = p->next;
    }

    Nr_Telefon *q = new Nr_Telefon;
    init_nr(q, nr.nume, nr.nr);
    
    q->next = p->next;
    p->next = q;
    
}


void show_agenda(Agenda agenda)
{
    Nr_Telefon *cap = agenda.cap;

    if (cap == nullptr) return;

    while (cap != nullptr)
    {
        cout << "Nume: " << cap->nume << ", Numar: " << cap->nr << endl;
        cap = cap->next;
    }
}