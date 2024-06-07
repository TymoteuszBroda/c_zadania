#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getWordVal(const char *str, int *index)
{
    if (strncmp(&str[*index], "one", 3) == 0)
    {
        *index += 3;
        return 1;
    }
    else if (strncmp(&str[*index], "two", 3) == 0)
    {
        *index += 3;
        return 2;
    }
    else if (strncmp(&str[*index], "three", 5) == 0)
    {
        *index += 5;
        return 3;
    }
    else if (strncmp(&str[*index], "four", 4) == 0)
    {
        *index += 4;
        return 4;
    }
    else if (strncmp(&str[*index], "five", 4) == 0)
    {
        *index += 4;
        return 5;
    }
    else if (strncmp(&str[*index], "six", 3) == 0)
    {
        *index += 3;
        return 6;
    }
    else if (strncmp(&str[*index], "seven", 5) == 0)
    {
        *index += 5;
        return 7;
    }
    else if (strncmp(&str[*index], "eight", 5) == 0)
    {
        *index += 5;
        return 8;
    }
    else if (strncmp(&str[*index], "nine", 4) == 0)
    {
        *index += 4;
        return 9;
    }
    return -1;
}

int calculate(const char *line)
{
    int length = strlen(line);
    int fval = -1, lval = -1;

    for (int i = 0; i < length;)
    {
        char c = tolower(line[i]);
        if (isdigit(c))
        {
            fval = c - '0';
            break;
        }
        else
        {
            int numericVal = getWordVal(line, &i);
            if (numericVal != -1)
            {
                fval = numericVal;
                break;
            }
            else
            {
                i++;
            }
        }
    }

    for (int i = length - 1; i >= 0;)
    {
        char c = tolower(line[i]);
        if (isdigit(c))
        {
            lval = c - '0';
            break;
        }
        else
        {
            int temp = i;
            int numericVal = getWordVal(line, &temp);
            if (numericVal != -1)
            {
                lval = numericVal;
                break;
            }
            else
            {
                i--;
            }
        }
    }

    if (fval == -1 || lval == -1)
    {
        return -1;
    }

    int value = fval * 10 + lval;
    return value;
}

int main()
{
    int sum = 0;

    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Nie można znaleźć pliku o tejnazwie!\n");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        int num = calculate(line);
        if (num != -1)
        {
            sum += num;
            printf("Liczba: %d\n", num);
        }
    }

    fclose(file);
    printf("Suma wszystkich wartości energetycznych: %d\n", sum);
    return 0;
}