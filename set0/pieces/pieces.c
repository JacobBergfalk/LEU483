#include <stdio.h>

int main() {
    int tables;
    int chairs;
    int pieces;
    / genom att ändra värderna i chairs eller tables så ändras värdet i pieces
    chairs = 4;
    tables = 1;

    pieces = chairs + tables;

    printf("%d \n", pieces);
    /* printf funktionen är tom. */
    return 0;
}
