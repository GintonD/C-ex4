/*
Creators
meir fuchs &&Ginton 

*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_LETTERS ((int)26)
typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
    char letter;
    long unsigned int count;
    boolean endWord ;
    struct node* children[NUM_LETTERS];
} node;
struct node* getnode()
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    // init all the child to NULL
    for (int i = 0; i < NUM_LETTERS; i++) {
        node->children[i] = NULL;
    }
    node ->endWord = FALSE;
    return node;
}

//**************************insertWord ***************************


void insertWord (node **root, char *word ) {
if (word[0]==' '||word[0]=='\n'||word[0]=='\t')  return;    
int len = strlen(word);
    node* pNode = *root;
    for (int i = 0; i < len; i++) {
        char c = word[i];
	if (c>='a' &&c<='z'){
        int index = c - 'a';
//        pNode->letter= c;
//        pNode->count++;
        if (pNode->children[index] == NULL) {
            pNode->children[index] = getnode();
            pNode = pNode->children[index];

        }
	 else { //exsict this char
            pNode = pNode->children[index]; //go to the next Node
        } 
        pNode->letter = c;

}

    }
    pNode->endWord = TRUE;
	pNode->count++;

}
//**************************printWordDefult ***************************


void printWordDefult ( node *pNode, char *str, int level) {
    if (pNode->endWord==TRUE) {
        str[level] = '\0';
        printf("%s \t %ld \n", str, pNode->count);

    }
    for (int i = 0; i < NUM_LETTERS; i++) {
        if (pNode->children[i] !=NULL) {
            str[level] = i + 'a';
            printWordDefult(pNode->children[i], str, level + 1);
        }
    }
}

//**************************printWordReverse ***************************

void printWordReverse( node *pNode, char *str, int level) {

    for (int i = NUM_LETTERS-1; i > -1; i--) {
        if (pNode->children[i]) {
            str[level] = i + 'a';
            printWordReverse(pNode->children[i], str, level + 1);
        }
    }
   if (pNode->endWord==TRUE) {
        str[level] = '\0';
        printf("%s \t %ld \n", str, pNode->count);

    }



}
// returns True if given node has any children
int haveChildren(node* curr)
{
    for (int i = 0; i < NUM_LETTERS; i++)
        if (curr->children[i])
            return TRUE;	// child found

    return FALSE;
}

// ***** destroy the tree from the memory ******

void delete (node *toDelete){


    for (int i=0; i<NUM_LETTERS; i++){
        if (toDelete->children[i])
            delete(toDelete->children[i]);
    }
    free(toDelete);
}


// ********function loweer case

void lowerCase (char* word){
    
    for (int i=0; i<strlen(word); i++){
        word[i] = tolower(word[i]);
    }

}
int main(int argc,char *argv[] )
{
    node* head = getnode();
// insert words from file: 
    char c;
    size_t n;
    char *word;
    n = 0;
    word = (char *)malloc(sizeof(char));
    word[n++] = '\0';

    printf( "Enter a word: \n " );
    c = getchar();
    int i=0;
    while (c != EOF && i<1000000) {
        while ( (c != EOF && c!=' '&& c!='\t'&& c != '\n')&& i<10000000) {
            word = realloc(word, (n + 1)*sizeof(char));

            word[n-1] = c;
            word[n++] = '\0';
            c = getchar();
            i++;
        } // end while of word
        i++;
        lowerCase(word); // to function lowerCase
   //     printf("You've entered \"%s\"\n", word);
        insertWord(&head, word); // insert word to the tree.
        free(word);
     //   free(tmp);
        //   if (c== EOF || c == '\n') break;
        c = getchar();
	if (c==EOF) break;

        n=1;
        word = (char *)malloc(sizeof(char));

        word[0] = c;

    } // end file
//free (word);
 /*
    insertWord(&head, "ab");

    insertWord(&head, "ab");
    insertWord(&head, "ab");
    insertWord(&head, "ab");
    insertWord(&head, "ab");
    insertWord(&head, "ab");
    insertWord(&head, "a");
*/   

    char* str =(char *)malloc(sizeof(char));
    if (argc==1){
 printf("Defult \n");
        printWordDefult(head, str, 0);
}
    else if(argv[1][0]=='r'){
        printf("Reverse \n");
 	printWordReverse(head, str, 0);

}
free (str);
    delete(head);
    //  free(head);
}





