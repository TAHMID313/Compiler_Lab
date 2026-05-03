#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char word[]) {
    if (strcmp(word, "int") == 0 ||
        strcmp(word, "float") == 0 ||
        strcmp(word, "char") == 0 ||
        strcmp(word, "double") == 0)
        return 1;
    return 0;
}

int isOperator(char ch) {
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='=')
        return 1;
    return 0;
}

int main() {
    char input[200], word[100];
    int i = 0, j;

    printf("enter statement:\n");
    fgets(input, sizeof(input), stdin);

    printf("\n tokens:\n");

    while (input[i] != '\0') {

        if (input[i] == ' ' || input[i] == '\n') {
            i++;
            continue;
        }

        if (isalpha(input[i])) {
            j = 0;
            while (isalnum(input[i])) {
                word[j++] = input[i++];
            }
            word[j] = '\0';

            if (isKeyword(word))
                printf("%s : Keyword\n", word);
            else
                printf("%s : Identifier\n", word);
        }

        else if (isdigit(input[i])) {
            j = 0;
            int isFloat = 0;

            while (isdigit(input[i]) || input[i] == '.') {
                if (input[i] == '.')
                    isFloat = 1;
                word[j++] = input[i++];
            }
            word[j] = '\0';

            if (isFloat)
                printf("%s : float\n", word);
            else
                printf("%s : integer\n", word);
        }

        else if (input[i] == '\'') {
            j = 0;
            word[j++] = input[i++];

            while (input[i] != '\'' && input[i] != '\0') {
                word[j++] = input[i++];
            }

            word[j++] = input[i++];
            word[j] = '\0';

            printf("%s : character \n", word);
        }

        else if (input[i] == '\"') {
            j = 0;
            word[j++] = input[i++];

            while (input[i] != '\"' && input[i] != '\0') {
                word[j++] = input[i++];
            }

            word[j++] = input[i++];
            word[j] = '\0';

            printf("%s : string \n", word);
        }

        else if (isOperator(input[i])) {
            printf("%c : operator\n", input[i]);
            i++;
        }

        else {
            printf("%c : special symbol\n", input[i]);
            i++;
        }
    }
    printf("\n\n\n\n Tahmid Khan Mojlish");
    printf("\n ID:0822310105101055 \n 4/1 \n spring 2026\n\n\n\n");

    return 0;
}
