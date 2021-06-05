#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef const char* string;

bool Strcmp(string str1, string str2);

void StringInit(char*** list)
{
    if (*list == NULL)
    {
        list[0] = NULL;
    }
    else
    {
        return;
    }
}

void StringListAdd(char*** list, string str)
{

    char** next;
    next = (char**)calloc(2, sizeof(char*));
    next[0] = (char*)calloc(strlen(str) + 1, sizeof(char*));
    next[1] = NULL;

    if (next[0] != NULL)
    {
       strcpy_s(next[0], sizeof(char*) * (strlen(str) + 1) ,str);
    }

    if (*list == NULL)
    {
        *list = next;
    }
    else
    {
        char** current = *list;

        while (current[1] != NULL)
        {
            current = (char**)current[1];
        }

        current[1] = (char*)next;
    }

}

void StringListRemove(char*** list, string str) {

    char** current;
    char** previous;

    previous = *list;
    current = *list;

    while (current[1] != NULL)
    {
        if (Strcmp(current[0], str)) 
        {
            break; 
        }

        current = (char**)current[1];
    }

    while (previous[1] != NULL)
    {
        if (previous[1] == (char*)current) 
        {
            break; 
        }

        previous = (char**)previous[1];
    }

    free(current[0]);

    if (previous[1] != NULL)
    {
        previous[1] = current[1];
    }

    else
    {
        *list = (char**)current[1];
    }
}

int StringListSize(char*** list) {

    char** current = *list;
    int Size = 0;

    while (current != NULL)
    {
        current = (char**)current[1];
        Size++;
    }

    return Size;

}

int StringListIndexOf(char*** list, string str) {
    
    char** current = *list;
    int counter = 0;

    while (current[0] != NULL)
    {
        if (Strcmp(current[0], str))
        {
            return counter;
            break;
        }
        else
        {

            current = (char**)current[1];
            counter++;
        }
    }

}

void StringListDestroy(char*** list) {

    char** previous = *list;
    char** current = *list;

    while (*list != NULL)
    {
        previous = *list;
        current = (char**)current[1];
        free(previous);
        *list = current;
    }

    free(*list);
}
    

void Output(char** list)
{
    char** current = list;

    while (current[1] != NULL)
    {
        printf("%s |", current[0]);
        current = (char**)current[1];
    }

    printf("%s\n", current[0]);
}

bool Strcmp(string str1, string str2)
{
    int len = strlen(str1);

    if (strlen(str1) == strlen(str2))
    {
        for (size_t i = 0; i < len; i++) 
        {
            if (str1[i] != str2[i]) { return false; }
        }

        return true;
    }

    else
    {
        return false;
    }
}


int main()
{
    char** list = NULL;
    StringInit(&list);
    StringListAdd(&list, "Tesla");
    StringListAdd(&list, "model S");
    StringListAdd(&list, "P100D");
    Output(list);
    StringListRemove(&list, "model S");
    printf("(model S) was removed:\n");
    Output(list);
    printf("StringListIndexOf (P100D): ");
    printf("%d\n", StringListIndexOf(&list, "P100D"));
    printf("StringListSize: ");
    printf("%d", StringListSize(&list));
    StringListDestroy(&list);

    return 0;

}
