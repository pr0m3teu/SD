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
    agenda->len++;

    Nr_Telefon *p = agenda->cap;
    Nr_Telefon *q = new Nr_Telefon;
    init_nr(q, nr.nume, nr.nr);

    if (strcmp(nr.nume, p->nume) < 0)
    {
        q->next = p;
        agenda->cap = q;
        return;
    }

    while (p->next != nullptr && strcmp(nr.nume, p->next->nume) > 0)
    {
        p = p->next;
    }

    
    q->next = p->next;
    p->next = q;
    
}

void delete_nr(Agenda *agenda, const char* nume)
{
    Nr_Telefon *p = agenda->cap;
    if (agenda->len == 1 && strcmp(p->nume, nume) == 0)
    {
        delete agenda->cap->nume;
        delete agenda->cap;
        agenda->cap = nullptr;
        return;
    }

    agenda->len--;
    if (strcmp(nume, p->nume) == 0)
    {
        agenda->cap = p->next;
        delete p;
        return;
    }

    while(strcmp(p->next->nume, nume) != 0 && p != nullptr)
    {
        p = p->next;
    }

    if (p == nullptr) return;

    Nr_Telefon *q = p->next;
    p->next = q->next;
    delete q;
}

unsigned long search_nr(Agenda agenda, const char* nume)
{
    Nr_Telefon *p = agenda.cap;
    if (agenda.len == 1 && strcmp(p->next->nume, nume) == 0) return p->nr;

    while(strcmp(p->next->nume, nume) != 0 && p != nullptr)
    {
        // cout << p->nr << endl;
        p = p->next;
    }
    if (p == nullptr) return 0;
    return p->nr;
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