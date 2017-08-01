/**
    @file hlight.c
    @author Ady Francis (afranci)
    Program that prints hypertext tags and entities highlighted in color
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 
 /** Exit code for reaching EOF within a tag */
 #define INVALID_TAG_EOF 101
 
/** Exit code for reaching EOF within an entity */
 #define INVALID_ENTITY_EOF 100
 
/**
    Function that reads the rest of the tag and prints it out in red.
*/
void showTag() {
    char ch;
    bool valid = false;
    
    printf("\33[31m");
    printf("<");
    while ((ch = getchar()) != EOF) {
        printf("%c", ch);
        if (ch == '>') {
            valid = true;
            break;
        }
    }
    printf("\33[0m");
    if (!valid)
        exit(INVALID_TAG_EOF);

}

/**
    Function that handles entities
*/
void showEntity() {
    char ch;
    bool valid = false;

    printf("\33[34m");
    printf("&");
    while ((ch = getchar()) != EOF) {
        printf("%c", ch);
        if (ch == ';') {
           valid = true;
           break;
        }
    }
    printf("\33[0m");
    if (!valid)
        exit(INVALID_ENTITY_EOF);
}

 /**
    Starting point for the program
    @return Exit status for the program
 */
int main () {

    char letter;

    while ((letter = getchar()) != EOF) {
        if (letter == '<')
            showTag();
        else if (letter == '&')
            showEntity();
        else
            printf("%c", letter);
    }

    return EXIT_SUCCESS;
}
