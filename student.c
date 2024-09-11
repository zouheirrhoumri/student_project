#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int departmentID;
    char name[30];
    int studentCount;
} Department;

typedef struct student
{
    int id;
    char nom[15];
    char prenom[15];
    char birthdate[15];
    int departmentID;
    Department departement;
    float note;

} student;

student t[100];
int dim = 0;
int ID = 0;

void ajouter_student(student t[])
{

    t[dim].id = ID + 1;

    printf("\t\tNom : ");
    scanf(" %[^\n]", t[dim].nom);

    printf("\t\tPrenom : ");
    scanf(" %[^\n]", t[dim].prenom);

    printf("\t\tBirthdate (dd/mm/yyyy) : ");
    scanf(" %[^\n]", t[dim].birthdate);

    printf("\t\tDepartement : ");
    scanf(" %[^\n]", t[dim].departement.name);

    printf("\t\tMoyenne generale : ");
    scanf("%f", &t[dim].note);

    dim++;
}

void ajouter_plus(student t[])
{
    int nbr, p;
    printf("\t\tcombien vous voulez ajouter :");
    scanf("%d", &nbr);
    p = nbr + dim;
    for (int i = dim; i < p; i++)
    {
        ajouter_student(t);
    }
}

void afficher_student()
{
    printf("\t\t+-------------------------------------------------------------------------------------------------------------------+\n");
    printf("\t\t| Id |        nom           |      prenom     |    date de naissance   |    departement    |   moyenne generale |\n");
    printf("\t\t+-------------------------------------------------------------------------------------------------------------------+\n");

    for (int i = 0; i < dim; i++)
    {
        printf("\t\t| %-2d | %-20s | %-15s | %-15s | %-15s | %-20.2f |\n",
               t[i].id, t[i].nom, t[i].prenom, t[i].birthdate, t[i].departement.name, t[i].note);
    }

    printf("\t\t+-------------------------------------------------------------------------------------------------------------------+\n");
}

void supprimer(student t[])
{

    int identifiant, c;

    printf("\t\t enter numero unique d etudiant : ");
    scanf("%d", &identifiant);

    for (int i = 0; i < dim; i++)
    {
        if (t[i].id == identifiant)
        {
            c++;
            for (int j = i; j < dim - 1; j++)
            {
                t[j] = t[j + 1];
            }
            dim--;
        }
    }
    if (c == 0)
        printf("\t\tIl n\'y a pas de tache avec l\'Id %d\n", identifiant);
    else
        afficher_student(t);
}

void modifier(student t[])
{
    int identifiant, c;

    printf("\t\t enter numero unique d etudiant : ");
    scanf("%d", &identifiant);

    for (int i = 0; i < dim; i++)
    {
        if (t[i].id == identifiant)
        {
            c++;
            printf("Modifier les informations de l'etudiant %d :\n", identifiant);
            printf("\t\tNom : ");
            scanf(" %[^\n]", t[i].nom);
            printf("\t\tPrenom : ");
            scanf(" %[^\n]", t[i].prenom);
            printf("\t\tBirthdate (dd/mm/yyyy) : ");
            scanf(" %[^\n]", t[i].birthdate);
            printf("\t\tDepartement : ");
            scanf(" %[^\n]", t[i].departement.name);
            printf("\t\tMoyenne generale : ");
            scanf("%f", &t[i].note);
            printf("Les informations de l'etudiant %d ont ete modifiees avec succes !\n", identifiant);
            break;
        }
    }
    if (c == 0)
        printf("\t\tIl n\'y a pas de tache avec l\'Id %d\n", identifiant);
    else
        afficher_student(t);
}

void calculmoyenn(student t[])
{
    char dep[30];
    int sum = 0;
    int count = 0;
    printf("entrez le departement : ");
    scanf("%s", &dep);
    for (int i = 0; i < dim; i++)
    {

        if (strcmp(t[i].departement.name, dep) == 0)
        {
            count++;
            sum = sum + t[i].note;
        }
    }

    if (count > 0)
    {
        float moyenne = sum / count;
        printf("La moyenne generale pour le departement %s est %.2f\n", dep, moyenne);
    }
    else
    {
        printf("Aucun etudiant trouve pour le departement %s.\n", dep);
    }

    for (int i = 0; i < dim; i++)
    {
        sum += t[i].note;
        count++;
    }

    if (count > 0)
    {
        float moyenne = sum / count;
        printf("La moyenne generale pour l'universite est %.2f\n", moyenne);
    }
    else
    {
        printf("Aucun etudiant dans l'universite.\n");
    }
}

void stat_inscris(student t[])
{
    int c;
    for (int i = 0; i < dim; i++)
    {
        c++;
    }
    printf("le nombre total est : %d ", c);
}

void stat_departmt(student t[])
{
    char dep[30];
    printf("entrez le departement :");
    scanf("%s", &dep);
    int count = 0;
    for (int i = 0; i < dim; i++)
    {
        if (strcmp(t[i].departement.name, dep) == 0)
        {
            count++;
        }
    }
    printf("Le nombre d etudiants dans le departement '%s' est : %d\n", dep, count);
}

void stat_seuil(student t[])
{
    float seuil;
    printf("\t\t entrez la seuil :");
    scanf("%f", &seuil);
    for (int i = 0; i < dim; i++)
    {
        if (t[i].note > seuil)
        {
            printf("\t\t le etudiant depassant la seuil : nom : %s avec note: %.2f \n", t[i].nom, t[i].note);
        }
    }
}

void note_description(float note, char description[])
{
    if (note >= 18)
    {
        strcpy(description, "Excellent");
    }
    else if (note >= 16)
    {
        strcpy(description, "Tres Bien");
    }
    else if (note >= 14)
    {
        strcpy(description, "Bien");
    }
    else if (note >= 12)
    {
        strcpy(description, "Passable");
    }
    else if (note >= 10)
    {
        strcpy(description, "Passable");
    }
    else
    {
        strcpy(description, "echou");
    }
}

void tri_meilleur(student t[])
{

    for (int i = 1; i < dim; i++)
    {
        float temp = t[i].note;
        int j = i - 1;
        while (temp > t[j].note && j >= 0)
        {
            t[j + 1].note = t[j].note;
            j--;
        }
        t[j + 1].note = temp;
    }
    for (int i = 0; i < dim; i++)
    {
        printf("\t\t| %-2d | %-20s | %-15s | %-15s | %-15s | %-20.2f |\n",
               t[i].id, t[i].nom, t[i].prenom, t[i].birthdate, t[i].departement.name, t[i].note);
    }
}

void tri_alphabetique(student t[])
{
    student temp;

    for (int i = 0; i < dim; i++)
    {
        for (int j = i + 1; j < dim; j++)
        {
            if (strcmp(t[i].nom, t[j].nom) > 0)
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    printf("\t\tLes taches triees alphabitique : \n");
    afficher_student(t);
}

void tri_reussit(student t[])
{
    for (int i = 1; i < dim; i++)
    {
        float temp = t[i].note;
        int j = i - 1;
        while (temp > t[j].note && j >= 0)
        {
            t[j + 1].note = t[j].note;
            j--;
        }
        t[j + 1].note = temp;
    }
    char description[20];
    for (int i = 0; i < dim; i++)
    {
        note_description(t[i].note, description);
        printf("\t\t| %-2d | %-20s | %-15s | %-15s | %-15s | %-20.2f | %-12s |\n",
               t[i].id, t[i].nom, t[i].prenom, t[i].birthdate, t[i].departement.name, t[i].note, description);
    }
}

void stat_meilleurs()
{
    tri_meilleur(t);

    printf("Les meilleurs 3 eleves sont :\n");
    for (int i = 0; i < 3 && i < dim; i++)
    {
        printf("\t\t+-------------------------------------------------------------------------------------------------------------------+\n");
        printf("\t\t| Id |        nom           |      prenom     |    date de naissance   |    departement    |   moyenne generale |\n");
        printf("\t\t+-------------------------------------------------------------------------------------------------------------------+\n");

        for (int i = 0; i < dim; i++)
        {
            printf("\t\t| %-2d | %-20s | %-15s | %-15s | %-15s | %-20.2f |\n",
                   t[i].id, t[i].nom, t[i].prenom, t[i].birthdate, t[i].departement.name, t[i].note);
        }

        printf("\t\t+-------------------------------------------------------------------------------------------------------------------+\n");
    }
}

void stat_reussit()
{
    char dep[30];
    int count = 0;
    printf("entrez le departement : ");
    scanf("%s", &dep);
    for (int i = 0; i < dim; i++)
    {
        if (strcmp(t[i].departement.name, dep) == 0 && t[i].note > 10)
        {
            count++;
        }
    }
    if (count > 0)
    {
        printf("La nombre de reussis pour le departement %s est %d\n", dep, count);
    }
    else
    {
        printf("Aucun etudiant trouve pour le departement %s.\n", dep);
    }
}

void recherche()
{
    char name[30];
    printf("entrez le nom pour rechercher :");
    scanf("%s", &name);
    for (int i = 0; i < dim; i++)
    {
        if (strcmp(t[i].nom, name) == 0)
        {
            printf("\t\t| %-2d | %-20s | %-15s | %-15s | %-15s | %-20.2f |\n",
                   t[i].id, t[i].nom, t[i].prenom, t[i].birthdate, t[i].departement.name, t[i].note);
        }
    }
}

void recherche_departement()
{
    char dep[30];
    printf("entrez le departement");
    scanf("%s", &dep);
    for (int i = 0; i < dim; i++)
    {
        if (strcmp(t[i].departement.name, dep) == 0)
        {
            printf("\t\t| %-2d | %-20s | %-15s | %-15s | %-15s | %-20.2f |\n",
             t[i].id, t[i].nom, t[i].prenom, t[i].birthdate, t[i].departement.name, t[i].note);
        }
    }
}

int menu_stats()
{
    int choix;
    while (1)
    {
        printf("\t\tMenu stats :\n");
        printf("\t\t1. le nombre total d etudiants inscrits.\n");
        printf("\t\t2. le nombre d etudiants dans chaque departement\n");
        printf("\t\t3. les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
        printf("\t\t4. les 3 etudiants ayant les meilleures notes.\n");
        printf("\t\t5. le nombre d etudiants ayant reussi dans chaque departement.\n");
        printf("\t\t6. retour \n");
        printf("\t\tEnter votre choix (1-4): ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            stat_inscris(t);
            system("pause");
            break;
        case 2:
            stat_departmt(t);
            system("pause");
            break;
        case 3:
            stat_seuil(t);
            system("pause");
            break;
        case 4:
            stat_meilleurs(t);
            system("pause");
            break;
        case 5:
            stat_reussit(t);
            system("pause");
            break;
        case 6:
            return 0;
            break;
        default:
            printf("\t\terreur, entrer en entier de 1 a 4.\n");
            return 0;
        }
    }

    return 0;
}

int menu_triage()
{

    int choix;
    while (1)
    {
        printf("\t\tMenu triage :\n");
        printf("\t\t1. tri alphabetique.\n");
        printf("\t\t2. tri moyenne general\n");
        printf("\t\t3. tri par status de reussite\n");
        printf("\t\t4. retour \n");
        printf("\t\tEnter votre choix (1-3): ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            tri_alphabetique(t);
            break;
        case 2:
            tri_meilleur(t);
            break;
        case 3:
            tri_reussit(t);
            break;
        case 4:
            return 0;
            break;
        default:
            printf("\t\terreur, entrer en entier de 1 a 7.\n");
            return 0;
        }
    }

    return 0;
}

int menu()
{
    int choix;
    while (1)
    {
        printf("\t\tMenu:\n");
        printf("\t\t1. ajouter un seul etudiant \n");
        printf("\t\t2. ajouter plusieur etudiant \n");
        printf("\t\t3. menu affichage \n");
        printf("\t\t4. calcul de moyenne\n");
        printf("\t\t5. statistiques\n");
        printf("\t\t6. menu triage\n");
        printf("\t\t7. supression\n");
        printf("\t\t8. modification\n");
        printf("\t\t9. recherche\n");
        printf("\t\t10. quitter \n");
        printf("\t\tEnter votre choix (1-6): ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajouter_student(t);
            break;
        case 2:
            ajouter_plus(t);
            break;
        case 3:
            afficher_student();
            break;
        case 4:
            calculmoyenn(t);
            break;
        case 5:
            menu_stats();
            break;
        case 6:
            menu_triage();
            break;
        case 7:
            supprimer(t);
            break;
        case 8:
            modifier(t);
            break;
        case 9:
            recherche(t);
            break;
        case 10:
            return 0;
        default:
            printf("\t\terreur, entrer en entier de 1 a 6.\n");
            return 0;
        }
    }

    return 0;
}

int main()
{

    menu();

    return 0;
}