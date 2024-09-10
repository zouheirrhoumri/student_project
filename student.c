#include <stdio.h>
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

void ajouter_student()
{

    printf("\t\tentrer le numero unique : ");
    scanf(" %d", t[dim].id);
    printf("\t\tnom : ");
    scanf(" %[^\n]", t[dim].nom);
    printf("\t\tprenom : ");
    scanf(" %[^\n]", t[dim].prenom);
    printf("\t\tbirthdate : ");
    scanf(" %[^\n]", t[dim].birthdate);
    printf("\t\t departement : ");
    scanf(" %[^\n]", t[dim].departement.name);
    printf("\t\t moyenne generale : ");
    scanf(" %f", t[dim].note);

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
