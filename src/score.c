#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float recursiveMax(float *list, int size);
float recursiveMin(float *list, int size);
float average(float *list, int size);
void display(float *list, int size);
char *check(float *list, int index);


int main() 
{
    int choice;
   unsigned num, counter = 0;
    /*
     *    choice: 
     *    counter: used to track proper index o
     *    num: total number of scores to be processed,
     */
    
    printf("%s", "Enter number of scores to be stored: ");
    scanf("%u", &num);

    float *scores_list = malloc(num * sizeof(float));
    
    while (1) 
    {
        puts("-----------------------------");
        puts("(1) Add a score");
        puts("(2) Display all scores");
        puts("(3) Highest score");
        puts("(4) Lowest score");
        puts("(5) Average");
        puts("(6) Check acceptance");
        puts("(7) quit");
        puts("-----------------------------");
        scanf("%i", &choice);
        
        switch (choice) 
        {
            case 1:
            {
                if (counter < num) 
                {
                    printf("%s", "Enter score: ");
                    scanf("%f", &scores_list[counter]);
                    counter += 1;
                    //scores_list[counter] = -1.0;
                } 
                else 
                {
                    puts("You cannot add more.");
                }
                break;
            }
            case 2:
            {
                display(scores_list, num);
                break;
            }   
            case 3:
            {
                float high;
                high = recursiveMax(scores_list, num);
                printf("%f\n", high);
                break;
            }   
            case 4:
            {
                float low = recursiveMin(scores_list, num);
                printf("%f\n", low);
                break;
            }
            case 5:
            {
                float avg = average(scores_list, num);
                printf("%f\n", avg);
                break;
            }
            case 6:
            {
                int student;
                printf("%s", "Enter number of student: ");
                scanf("%i", &student);
                printf("%s\n", check(scores_list, (student - 1)));
                break;
            }
            case 7:
            {
                return 0;
            }
        }
    }
}



float recursiveMax(float *list, int size) 
{
    /* 
     * Finds the biggest number within an array of floating points using recursion.
     *
     * parameters:
     *     *list: float -- the array of numbers
     *      size: int -- length of the array
     * 
     *
     * 
     * float value = recursiveMax(list, (size - 1));
     */
    
     
    if (size == 1)
        return list[0];  
    
    float value = recursiveMax(list, (size - 1));
    // float *sliced_list = malloc(size * sizeof(float));
    // memcpy(sliced_list, list, (size - 1) * sizeof(float));
    // float value = recursiveMax(sliced_list, (size - 1));
    
    if (list[size - 1] > value)
        return list[size - 1];
    else 
        return value;
}


float recursiveMin(float *list, int size) 
{
    /* 
     * Finds the biggest number within an array of floating points using recursion.
     *
     * parameters:
     *     *list: float -- the array of numbers
     *      size: int -- length of the array
     * 
     *
     * 
     * float value = recursiveMax(list, (size - 1));
     */
    
    if (size == 1)
        return list[0];    
    
    float *sliced_list = malloc(size * sizeof(float));
    memcpy(sliced_list, list, (size - 1) * sizeof(float));
    float value = recursiveMin(sliced_list, (size - 1));
    
    if (list[size - 1] < value)
        return list[size - 1];
    else 
        return value;
}


float average(float *list, int size) 
{
    float sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += list[i];
    }
    return ((float) sum / size);
}


void display(float *list, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        printf("%.2f\t", list[i]);
    }
    puts("");
}


char *check(float *list, int index)
{
    return ((list[index] >= 20) ? "Passed" : "Rejected");
}