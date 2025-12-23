#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Scrivere un programma che sia in grado di
 *  collezione e gestire (?) i voti di uno studente.
 * 
 * - Salvare le informazioni anagrafiche dello studente.
 * - Visualizzare le informazioni anagrafiche dello studente.
 * - Poter salvare le votazioni ricevute nelle varie materie.
 * - Poter visualizzare le votazioni ricevute.
 * - Poter calcolare la media dei voti.
 * - (OPZIONALE) Poter calcolare la media dei voti per materia.
 */

#define MAX_TEMPLATES 10

#define MAX_NAMES 32
#define MAX_VOTES 10
#define MAX_SUBJECTS 8
#define MAX_STUDENTS 5

enum Materia
{
    Italiano,
    Storia,
    Geografia,
    Matematica,
    Chimica,
    Fisica,
    Informatica,
    EducazioneFisica
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Voto
{
    Materia materia;

    Date data;
    float valore;
};
struct Studente
{
    char nome[MAX_NAMES];
    char cognome[MAX_NAMES];

    Date data_nascita;

    int voti_count;
    Voto voti[MAX_VOTES];
};

const char STUDENT_NAMES[][MAX_NAMES] =
{
    "Alessandro",
    "Andrea",
    "Chiara",
    "Federica",
    "Francesca",
    "Giulia",
    "Luca",
    "Marco",
    "Matteo",
    "Sara"
};
const char STUDENT_SURNAMES[][MAX_NAMES] =
{
    "Bianchi",
    "Bruno",
    "Colombo",
    "Esposito",
    "Ferrari",
    "Ricci",
    "Romano",
    "Russo",
    "Sorrentino",
    "Verdi"
};

/* Utils... */

void gets(char* buffer, int size)
{
    fgets(buffer, size, stdin);

    int len = strlen(buffer);
    if ((len > 0) && (buffer[len - 1] == '\n'))
    {
        buffer[len - 1] = '\0';
    }
}
void fputs(const char* buffer)
{
    fputs(buffer, stdout);
}

/* Init... */

static const char* convert_subject_to_string(Materia materia)
{
    switch (materia)
    {
        case Italiano:
            return "Italiano";

        case Storia:
            return "Storia";

        case Geografia:
            return "Geografia";

        case Matematica:
            return "Matematica";

        case Chimica:
            return "Chimica";

        case Fisica:
            return "Fisica";

        case Informatica:
            return "Informatica";

        case EducazioneFisica:
            return "Educazione Fisica";

        default:
            return "Sconosciuta";
    }
}

Date generate_date(int year, int offset = 0)
{
    Date data;

    data.day = (rand() % 28) + 1;
    data.month = (rand() % 12) + 1;
    data.year = year + offset;

    return data;
}

Voto generate_vote()
{
    Voto voto;

    voto.materia = (Materia)(rand() % MAX_SUBJECTS);
    voto.data = generate_date(2025);
    voto.valore = ((rand() % 19) / 2) + 1;

    return voto;
}
int generate_votes(Voto voti[])
{
    int max_voti = (rand() % MAX_VOTES);
    for (int i = 0; i < max_voti; i += 1)
    {
        voti[i] = generate_vote();
    }

    return max_voti;
}

Studente generate_student()
{
    Studente studente;

    int name_index = rand() % MAX_TEMPLATES;
    int surname_index = rand() % MAX_TEMPLATES;

    strcpy(studente.nome, STUDENT_NAMES[name_index]);
    strcpy(studente.cognome, STUDENT_SURNAMES[surname_index]);

    studente.data_nascita = generate_date(2010, (rand() % 3) - 1);
    studente.voti_count = generate_votes(studente.voti);

    return studente;
}
int generate_students(Studente studenti[])
{
    int max_studenti = (rand() % MAX_STUDENTS);
    for (int i = 0; i < max_studenti; i += 1)
    {
        studenti[i] = generate_student();
    }

    return max_studenti;
}

int main()
{
    int studenti_count;
    Studente studenti[MAX_STUDENTS];

    studenti_count = generate_students(studenti);

    return 0;
}
