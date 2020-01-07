#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM_LETTERS ((int)26)
typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];
} node;
struct node* getnode()
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
          // init all the child to NULL
	for (int i = 0; i < NUM_LETTERS; i++)
		node->children[i] = NULL;

	return node;
}

void insertWord (node *root, char *word ){
          int len = strlen(word);
          node* pCrawl = root;
          for (int i=0; i<len; i++){
                    char c = word[i];
                    int index = c - 'a'; 
                  
                    if (pCrawl->children[index] == NULL){
                    pCrawl->children[index] = getnode(); }
                    else{
                    pCrawl = pCrawl->children[index]; //go to the next Node
                    }
          }

}
int main(){
          struct node* head = getnode();

	insertWord(head, "hello");}