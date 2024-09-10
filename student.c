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
void ajouter_student(student t[]) {
    printf("\t\tEntrer le numero unique : ");
    scanf("%d", &t[dim].id);  

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
        printf("\t\t| %-2d | %-20s | %-15s | %-15s | %-15s | %-5.2f |\n",
               t[i].id, t[i].nom, t[i].prenom, t[i].birthdate, t[i].departement.name, t[i].note);
    }

    printf("\t\t+-------------------------------------------------------------------------------------------------------------------+\n");
}

int main(){

    ajouter_student(t);

    return 0 ;
}