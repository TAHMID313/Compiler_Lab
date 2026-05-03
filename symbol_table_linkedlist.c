#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Symbol{
    char name[30];
    char type[10];
    char kind[10];
    int scope;
    char value[30];
    struct Symbol *next;
} Symbol;

// Create empty table
Symbol *createTable() {
    return NULL;
}

// Add symbol
Symbol* addSymbol(Symbol *table, char *name, char *type, char *kind, int scope, char *value) {
    Symbol *newSym = (Symbol*)malloc(sizeof(Symbol));

    strcpy(newSym->name, name);
    strcpy(newSym->type, type);
    strcpy(newSym->kind, kind);
    newSym->scope = scope;
    strcpy(newSym->value, value);

    newSym->next = table;
    return newSym;
}

// Display table
void displayTable(Symbol *table) {
    if(table == NULL) {
        printf("\nSymbol Table is EMPTY\n");
        return;
    }

    printf("\nName\tType\tKind\tScope\tValue\n");
    printf("-------------------------------------------\n");

    for(Symbol *p = table; p != NULL; p = p->next) {
        printf("%s\t%s\t%s\t%d\t%s\n",
               p->name, p->type, p->kind, p->scope, p->value);
    }
}

// Search
Symbol* searchSymbol(Symbol *table, char *name) {
    for(Symbol *p = table; p != NULL; p = p->next) {
        if(strcmp(p->name, name) == 0) {
            return p;
        }
    }
    return NULL;
}

// Update
void updateSymbol(Symbol *table, char *name) {
    Symbol *sym = searchSymbol(table, name);

    if(sym == NULL) {
        printf("Symbol not found!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%s", sym->value);

    printf("Updated successfully!\n");
}

// Delete
Symbol* deleteSymbol(Symbol *table, char *name) {
    Symbol *temp = table, *prev = NULL;

    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0) {

            if(prev == NULL)
                table = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Deleted successfully!\n");
            return table;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Symbol not found!\n");
    return table;
}

// Main Menu
int main() {
    Symbol *table = createTable();

    int choice;
    char name[30], type[10], kind[10], value[30];
    int scope;

    while(1) {
        printf("\n SYMBOL TABLE MENU \n");
        printf("1. Insert Symbol\n");
        printf("2. Display Table\n");
        printf("3. Search Symbol\n");
        printf("4. Update Symbol\n");
        printf("5. Delete Symbol\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Type: ");
            scanf("%s", type);
            printf("Enter Kind: ");
            scanf("%s", kind);
            printf("Enter Scope: ");
            scanf("%d", &scope);
            printf("Enter Value: ");
            scanf("%s", value);

            table = addSymbol(table, name, type, kind, scope, value);
            printf("Symbol inserted!\n");
            break;

        case 2:
            displayTable(table);
            break;

        case 3:
            printf("Enter name to search: ");
            scanf("%s", name);

            Symbol *found = searchSymbol(table, name);
            if(found)
                printf("Found: %s %s %s %d %s\n",
                       found->name, found->type,
                       found->kind, found->scope,
                       found->value);
            else
                printf("Not found!\n");
            break;

        case 4:
            printf("Enter name to update: ");
            scanf("%s", name);
            updateSymbol(table, name);
            break;

        case 5:
            printf("Enter name to delete: ");
            scanf("%s", name);
            table = deleteSymbol(table, name);
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
