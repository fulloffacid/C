
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


main()
{
    typedef struct {
        char familyname[30];
        char name[30];
        char fathername[30];
        int date;
        int marks[3];
        float avermark;
    }enrollee;

    FILE *f;
    enrollee man;
    enrollee mas[10];

    if ((f = fopen("enrollee.dat", "wb")) == NULL) exit(1);

    for (int i = 0; i < 5; i++){
        printf("New enrollee %d\n", i);
        printf("Familyname = ");  scanf("%s", &man.familyname);
        printf("Name = ");        scanf("%s", &man.name);
        printf("Fathername = ");  scanf("%s", &man.fathername);
        printf("date = ");        scanf("%d", &man.date);
        printf("marks (separated by spaces) = ");  scanf("%d %d %d", &man.marks[0], &man.marks[1], &man.marks[2]);
        printf("Average mark in school-leaving certificate = ");  scanf("%f", &man.avermark);

        fwrite(&man, sizeof(enrollee), 1, f);
        if (ferror(f) != NULL) exit(2);
    }
    fclose(f);

    if ((f = fopen("enrollee.dat", "rb")) == NULL) exit(3);

    int i = 0;
    while (!feof(f) && i < 5)
    {
        fread(&mas[i], sizeof(enrollee), 1, f);
        i++;
    }
    fclose(f);

    for (int i = 0; i < 5; i++){
        printf("\nNew enrollee %d\n", i);
        printf("Familyname = %s\n", mas[i].familyname);
        printf("Name = %s\n", mas[i].name);
        printf("Fathername = %s\n", mas[i].fathername);
        printf("date = %d\n", mas[i].date);
        printf("marks  = %d %d %d\n", mas[i].marks[0], mas[i].marks[1], mas[i].marks[2]);
        printf("Average mark in school-leaving certificate = %f\n", mas[i].avermark);
    }

    int numdel;
    printf("Input number of enrollee you want to delete. From 1 to 5. "); scanf("%d", &numdel);
    for (i = numdel - 1; i < 4; i++){
        mas[i] = mas[i + 1];
    }

    char familyadd[30];
    enrollee masnew[10];
    bool familyfound = false, familyinserted = false;

    printf("Input family name of enrollee after wich you want to add new one. "); scanf("%s", &familyadd);

    if ((f = fopen("enrollee.dat", "wb")) == NULL) exit(4);

    int j = 0;
    for (i = 0; i < 5; i++) {
        man = mas[i];
        if ((strcmp(mas[i].familyname, familyadd) == 0) && !familyfound) {
            familyfound = true;
            man = mas[j];
            j++;
        }
        else {
            if (familyfound && !familyinserted) {
                printf("i = %d\n", i);
                printf("Familyname = ");  scanf("%s", &man.familyname);
                printf("Name = ");        scanf("%s", &man.name);
                printf("Fathername = ");  scanf("%s", &man.fathername);
                printf("date = ");        scanf("%d", &man.date);
                printf("marks (separated by spaces) = ");
                scanf("%d %d %d", &man.marks[0], &man.marks[1], &man.marks[2]);
                printf("Average mark in school-leaving certificate = ");
                scanf("%f", &man.avermark);
                familyinserted = true;
            }
            else { man = mas[j]; j++; }
        }
        fwrite(&man, sizeof(enrollee), 1, f);
        if (ferror(f) != NULL) exit(5);
    }
    fclose(f);

    enrollee rmas[10];
    i = 0;
    while (!feof(f) && i < 5)
    {
        fread(&rmas[i], sizeof(enrollee), 1, f);
        i++;
    }
    fclose(f);

    for (int i = 0; i < 5; i++){
        printf("\nNew enrollee %d\n", i);
        printf("\nFamilyname = %s\n", rmas[i].familyname);
        printf("Name = %s\n", rmas[i].name);
        printf("Fathername = %s\n", rmas[i].fathername);
        printf("date = %d\n", rmas[i].date);
        printf("marks  = %d %d %d\n", rmas[i].marks[0], rmas[i].marks[1], rmas[i].marks[2]);
        printf("Average mark in school-leaving certificate = %f\n", rmas[i].avermark);
    }
    system("pause");
    return 0;
}
