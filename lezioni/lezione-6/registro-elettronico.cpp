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

void _gets(char* buffer, int size)
{
    fgets(buffer, size, stdin);

    int len = strlen(buffer);
    if ((len > 0) && (buffer[len - 1] == '\n'))
    {
        buffer[len - 1] = '\0';
    }
}
void _puts(const char* buffer)
{
    fputs(buffer, stdout);
}

void _clear()
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
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

/* Vote functions... */

int aggiungi_voto(Studente studenti[], int studenti_count, int index)
{
    if (studenti_count == 0)
    {
        printf("Nessuno studente presente a sistema.\n");

        return -1;
    }
    if ((index < 0) || (index >= studenti_count))
    {
        printf("Lo studente selezionato non è valido.\n");

        return -1;
    }

    Studente* studente = &studenti[index];

    if (studente -> voti_count >= MAX_VOTES)
    {
        printf("Numero massimo di voti collezionabili dallo studente raggiunto.\n");
        printf("Non è più possibile aggiungere nuovi voti per lo studente selezionato.\n");

        return -1;
    }

    Voto nuovo_voto;

    int materia;
    printf("Materie:\n");
    printf(" 0. Italiano\n");
    printf(" 1. Storia\n");
    printf(" 2. Geografia\n");
    printf(" 3. Matematica\n");
    printf(" 4. Chimica\n");
    printf(" 5. Fisica\n");
    printf(" 6. Informatica\n");
    printf(" 7. Educazione Fisica\n\n");

    printf("Seleziona la materia del voto: ");
    scanf("%d", &materia);
    nuovo_voto.materia = (Materia)materia;

    printf("Inserisci la data del voto (gg/mm/aaaa): ");
    scanf("%d/%d/%d", &nuovo_voto.data.day, &nuovo_voto.data.month, &nuovo_voto.data.year);

    printf("Inserisci il valore del voto: ");
    scanf("%f", &nuovo_voto.valore);
    
    _clear();

    studente -> voti[studente -> voti_count] = nuovo_voto;
    studente -> voti_count += 1;

    printf("Voto aggiunto con successo.\n");

    return 0;
}
void visualizza_voti(Studente studenti[], int studenti_count, int index)
{
    if (studenti_count == 0)
    {
        printf("Nessuno studente presente a sistema.\n");

        return;
    }
    if ((index < 0) || (index >= studenti_count))
    {
        printf("Lo studente selezionato non è valido.\n");

        return;
    }

    Studente studente = studenti[index];

    if (studente.voti_count == 0)
    {
        printf("Nessuna votazione presente per lo studente selezionato.\n");

        return;
    }

    printf("Voti dello studente %s %s:\n", studente.nome, studente.cognome);
    for (int i = 0; i < studente.voti_count; i += 1)
    {
        Voto voto = studente.voti[i];

        printf(" Voto %d:\n", i + 1);
        printf("  ├ Materia: %s\n", convert_subject_to_string(voto.materia));
        printf("  ├ Data: %02d/%02d/%04d\n", voto.data.day, voto.data.month, voto.data.year);
        printf("  └ Valore: %.2f\n", voto.valore);
        printf("\n");
    }
}
void calcola_media(Studente studenti[], int studenti_count, int index)
{
    if (studenti_count == 0)
    {
        printf("Nessuno studente presente a sistema.\n");

        return;
    }
    if ((index < 0) || (index >= studenti_count))
    {
        printf("Lo studente selezionato non è valido.\n");

        return;
    }

    Studente studente = studenti[index];

    if (studente.voti_count == 0)
    {
        printf("Nessuna votazione presente per lo studente selezionato.\n");

        return;
    }

    float somma = 0.0f;
    for (int i = 0; i < studente.voti_count; i += 1)
    {
        somma += studente.voti[i].valore;
    }

    float media = somma / studente.voti_count;

    printf("La media dei voti dello studente %s %s è: %.2f\n", studente.nome, studente.cognome, media);
}
int rimuovi_voto(Studente studenti[], int studenti_count, int index)
{
    if (studenti_count == 0)
    {
        printf("Nessuno studente presente a sistema.\n");

        return -1;
    }
    if ((index < 0) || (index >= studenti_count))
    {
        printf("Lo studente selezionato non è valido.\n");

        return -1;
    }

    Studente* studente = &studenti[index];

    if (studente -> voti_count == 0)
    {
        printf("Nessuna votazione presente per lo studente selezionato.\n");

        return -1;
    }

    studente -> voti_count -= 1;

    printf("Ultimo voto rimosso con successo.\n");

    return 0;
}

/* Student functions... */

int aggiungi_studente(Studente studenti[], int* studenti_count)
{
    if (*studenti_count >= MAX_STUDENTS)
    {
        printf("Numero massimo di studenti collezionabili raggiunto.\n");
        printf("Non è più possibile aggiungere nuovi studenti.\n");

        return -1;
    }

    Studente nuovo_studente;

    printf("Inserisci il nome dello studente: ");
    _gets(nuovo_studente.nome, MAX_NAMES);

    printf("Inserisci il cognome dello studente: ");
    _gets(nuovo_studente.cognome, MAX_NAMES);

    printf("Inserisci la data di nascita (gg/mm/aaaa): ");
    scanf("%d/%d/%d", &nuovo_studente.data_nascita.day, &nuovo_studente.data_nascita.month, &nuovo_studente.data_nascita.year);

    _clear();

    nuovo_studente.voti_count = 0;

    studenti[*studenti_count] = nuovo_studente;
    *studenti_count += 1;

    printf("Studente aggiunto con successo.\n");

    return 0;
}
void elenca_studenti(Studente studenti[], int studenti_count)
{
    if (studenti_count == 0)
    {
        printf("Nessuno studente presente a sistema.\n");

        return;
    }

    for (int i = 0; i < studenti_count; i += 1)
    {
        Studente studente = studenti[i];

        printf("Studente %d:\n", i + 1);
        printf(" ├ Nome: %s\n", studente.nome);
        printf(" ├ Cognome: %s\n", studente.cognome);
        printf(" ├ Data di nascita: %02d/%02d/%04d\n", studente.data_nascita.day, studente.data_nascita.month, studente.data_nascita.year);
        printf(" └ Numero di valutazioni: %d\n", studente.voti_count);
        printf("\n");
    }
}

int elimina_studente(Studente studenti[], int* studenti_count, int index)
{
    if (*studenti_count == 0)
    {
        printf("Nessuno studente presente a sistema.\n");

        return -1;
    }
    if ((index < 0) || (index >= *studenti_count))
    {
        printf("Lo studente selezionato non è valido.\n");

        return -1;
    }

    for (int i = index; i < (*studenti_count - 1); i += 1)
    {
        studenti[i] = studenti[i + 1];
    }

    *studenti_count -= 1;

    printf("Studente eliminato con successo.\n");
    return 0;
}

/* Menu functions... */

bool scegli_studente(Studente studenti[], int studenti_count, int* index)
{
    if (studenti_count == 0)
    {
        printf("Nessuno studente presente a sistema.\n");

        return false;
    }

    for (int i = 0; i < studenti_count; i += 1)
    {
        Studente studente = studenti[i];

        printf("%d. %s %s\n", i + 1, studente.nome, studente.cognome);
    }
    printf("0. Torna indietro\n\n");

    int selezione;
    printf("Seleziona uno studente: ");
    scanf("%d", &selezione);
    printf("\n");

    _clear();

    if (selezione == 0) { return false; }
    if ((selezione < 1) || (selezione > studenti_count))
    {
        printf("Lo studente selezionato non è valido.\n");

        return true;
    }

    *index = selezione - 1;

    return true;
}
bool menu_studente(Studente studenti[], int* studenti_count, int index)
{
    char scelta;

    printf("\n");
    printf("1. Aggiungi voto\n");
    printf("2. Visualizza voti\n");
    printf("3. Calcola media\n");
    printf("4. Rimuovi voto\n");
    printf("5. Elimina studente\n");
    printf("0. Torna al menu principale\n\n");

    printf("Seleziona un'opzione: ");
    scanf(" %c", &scelta);
    printf("\n");

    _clear();

    switch (scelta)
    {
        case '1':
            aggiungi_voto(studenti, *studenti_count, index);

            return true;

        case '2':
            visualizza_voti(studenti, *studenti_count, index);

            return true;

        case '3':
            calcola_media(studenti, *studenti_count, index);

            return true;

        case '4':
            rimuovi_voto(studenti, *studenti_count, index);

            return true;

        case '5':
            elimina_studente(studenti, studenti_count, index);

            return true;

        case '0':
            return false;

        default:
            printf("Opzione non valida.\n");

            return true;
    }
}

void gestisci_studente(Studente studenti[], int* studenti_count)
{
    int index;

    while (true)
    {
        if (!(scegli_studente(studenti, *studenti_count, &index))) { return; }

        while (menu_studente(studenti, studenti_count, index));
    }
}

bool menu_principale(Studente studenti[], int* studenti_count)
{
    char scelta;

    printf("\n");
    printf("1. Aggiungi un nuovo studente\n");
    printf("2. Elenca tutti gli studenti\n");
    printf("3. Gestisci uno studente\n");
    printf("0. Esci\n\n");

    printf("Seleziona un'opzione: ");
    scanf(" %c", &scelta);
    printf("\n");

    _clear();

    switch (scelta)
    {
        case '1':
            aggiungi_studente(studenti, studenti_count);

            return true;

        case '2':
            elenca_studenti(studenti, *studenti_count);
            
            return true;

        case '3':
            gestisci_studente(studenti, studenti_count);
            
            return true;
            
        case '0':
            printf("Uscita in corso...\n");
            
            return false;

        default:
            printf("Opzione non valida.\n");

            return true;
    }
}

int main()
{
    int studenti_count;
    Studente studenti[MAX_STUDENTS];

    studenti_count = generate_students(studenti);

    while (menu_principale(studenti, &studenti_count));

    return 0;
}
