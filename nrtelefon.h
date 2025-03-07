#ifndef NRTELEFON_H_
#define NRTELEFON_H_

struct Nr_Telefon
{
    char *nume;
    unsigned long nr;

    Nr_Telefon *next;
};

struct Agenda
{
    Nr_Telefon *cap;
    unsigned int len;
};

void init_agenda(Agenda *& agenda);
void init_nr(Nr_Telefon *& nr, const char * nume, unsigned long numar);

void insert_nr(Agenda *& agenda, Nr_Telefon nr);
void delete_nr(Agenda *agenda, const char* nume);

unsigned long search_nr(Agenda agenda, const char* nume);
void show_agenda(Agenda agenda);
#endif // NRTELEFON_H_