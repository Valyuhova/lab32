#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

struct dog 
{
    char breed[30];
    char name[30];
    float weight;
};

int main() 
{
    system("chcp 65001");

    struct dog dogs[N];
    int count, i;
    char search_breed[30];
    float max_weight;
    FILE *output;

    printf("Введіть кількість собак: ");
    scanf("%d", &count);

    if (count > N) 
    {
        printf("Забагато записів!\n");
        return 1;
    }

    for (i = 0; i < count; i += 1) 
    {
        printf("\nСобака #%d:\n", i + 1);
        printf("Порода: ");
        scanf("%s", dogs[i].breed);
        printf("Кличка: ");
        scanf("%s", dogs[i].name);
        printf("Вага (кг): ");
        scanf("%f", &dogs[i].weight);
    }

    printf("\nВведіть породу для пошуку: ");
    scanf("%s", search_breed);
    printf("Введіть максимальну вагу: ");
    scanf("%f", &max_weight);

    output = fopen("dogs_filtered.txt", "w");

    if (!output) 
    {
        printf("Помилка відкриття файлу для запису.\n");
        return 1;
    }

    fprintf(output, "Собаки породи \"%s\" з вагою не більше %.2f кг:\n", search_breed, max_weight);

    for (i = 0; i < count; i += 1) 
    {
        if (strcmp(dogs[i].breed, search_breed) == 0 && dogs[i].weight <= max_weight) 
        {
            fprintf(output, "Кличка: %s | Порода: %s | Вага: %.2f кг\n",
                    dogs[i].name, dogs[i].breed, dogs[i].weight);
        }
    }

    fclose(output);

    printf("Результати збережено в файл dogs_filtered.txt\n");
    return 0;
}
