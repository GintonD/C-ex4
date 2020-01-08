#include <stdio.h>
#include<string.h>
#include<stdlib.h>
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

void insertWord (node *root, char *word ) {
    int len = strlen(word);
    node *pNode = root;
    for (int i = 0; i < len; i++) {
        char c = word[i];
        int index = c - 'a';
//        pNode->letter= c;
//        pNode->count++;
        if (pNode->children[index] == NULL) {
            pNode->children[index] = getnode();
            pNode = pNode->children[index];

        } else {
            pNode = pNode->children[index]; //go to the next Node
        }
        pNode->letter = c;
        pNode->count++;


    }
    pNode->endWord = TRUE;

}
void printWordDefult (struct node *head, char *word, int level) {
    node *pNode = head;

    if (pNode->endWord == TRUE) {
        word[level] = '\0';
//        for (int i=0; i<pNode->count;i++) {
        printf("%s" " %ld \n", word, pNode->count);
//        }
    }
    for (int i = 0; i < NUM_LETTERS; i++) {
        if (pNode->children[i]) {
            word[level] = i + 'a';
            printWordDefult(pNode->children[i], word, level + 1);
        }
    }
}
    void printWordReverse(struct node *head, char *word, int level) {
        node *pNode = head;

        if (pNode->endWord == TRUE) {
            word[level] = '\0';
//        for (int i=0; i<pNode->count;i++) {
            printf("%s" " %ld \n", word, pNode->count);
//        }
        }
        for (int i = NUM_LETTERS-1; i > 0; i--) {
            if (pNode->children[i]) {
                word[level] = i + 'a';
                printWordReverse(pNode->children[i], word, level + 1);
            }
        }

    }
    // // returns True if given node has any children
     int haveChildren(node* curr)
{
for (int i = 0; i < NUM_LETTERS; i++)
if (curr->children[i])
return TRUE;	// child found

return FALSE;
}


void delete (node* root){
    node* pRoot = root;
    if (pRoot!=NULL){
//    if (haveChildren(pRoot)==FALSE){
      if (pRoot->endWord==TRUE){
        free(pRoot);
    }
    else{
        for (int i=0; i<NUM_LETTERS; i++){
            if (pRoot->children[i])
                delete(pRoot->children[i]);
        }
    }
    }
}
    int main() {
        struct node *head = getnode();

        insertWord(head, "abc");
        insertWord(head, "bac");
        insertWord(head, "bac");
        insertWord(head, "abc");
        insertWord(head, "ddd");
        insertWord(head, "aaa");


        //abc bac bac abc ddd aaa

        char str[30];
        printWordDefult(head, str, 0);
        delete(head);
//        printf("Defullt \n");

//        printWordReverse(head, str, 0);

    }

