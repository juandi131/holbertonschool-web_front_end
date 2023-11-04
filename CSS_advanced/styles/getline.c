#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numero;

int checkpush(char *tocken)
{
    int len, a = 0;
    char *str = NULL, *str1 = NULL, *push = "push";

    len = strlen(tocken);


    str1 = malloc(len + 1);  // Asignar memoria para str
      if (str1 == NULL)
    {
        perror("Error al asignar memoria");
        return 1;
    }
    while (a <= len) {
        str1[a] = tocken[a];
        a++;
    }
    printf("%d\n", str1[len - 1]);

    return(1);
}


int main(int argc, char *argv[]) {
    int error;

    char *line = NULL;
    size_t bufsize = 0;
    size_t bytesRead;

    if (argc != 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }



    while ((bytesRead = getline(&line, &bufsize, file)) != -1) {
        char *token = strtok(line, "$");  // Separar por $ y salto de línea
        while (token != NULL) 
        {
            // Eliminar espacios del token
            char *cleanedToken = malloc(strlen(token) + 1);
            if (cleanedToken) 
            {
                int j = 0;
                for (int i = 0; token[i]; i++)
                {
                    if (token[i] != ' ') {
                        cleanedToken[j++] = token[i];
                    }
                }
                cleanedToken[j] = '\0';
                int otro = checkpush(cleanedToken);
                if (otro == 1)
                {
                    printf("error\n");      
                }
                free(cleanedToken);
            }

            token = strtok(NULL, "$\n");
        }
    }

    free(line);
    fclose(file);

    return 0;
}