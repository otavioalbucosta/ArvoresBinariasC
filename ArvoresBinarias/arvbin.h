#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct No
{
    float preco;
    struct No *noesq;
    struct No *nodir;
};
typedef struct No No;


void criarArvore(No **t){
    *t = NULL;
}

void insertTree(No** t, float preco){
  if(*t == NULL){
    *t = (No*)malloc(sizeof(No)); 
    (*t)->noesq = NULL; 
    (*t)->nodir = NULL; 
    (*t)->preco = preco;
  } else {
    if(preco < (*t)->preco){
      insertTree(&(*t)->noesq, preco);
    }else if(preco > (*t)->preco){ 
      insertTree(&(*t)->nodir, preco);
    }else if (preco == (*t)->preco){
    	printf("\nJa existe um no com este valor\n");
    	return;
	}
  }
}

No *MaiorDireita(No **t)
{
    if((*t)->nodir != NULL)
    {
       return MaiorDireita(&(*t)->nodir);
    }
    else
    {
       No *aux = *t;
       
       if((*t)->noesq != NULL) 
        {
          *t = (*t)->noesq;
        }
        else
        {
            *t = NULL;
        }
        return aux;
    }
        
}

No *MenorEsquerda(No **t)
{
    if((*t)->noesq != NULL)
    {
       return MenorEsquerda(&(*t)->noesq);
    }
    else
    {
        No *aux = *t; 
        if((*t)->nodir != NULL){
          *t = (*t)->nodir;
        }
        else{
          *t = NULL;
        }
        return aux;
    }
}

void remover(No **t, float preco){
    if(*t == NULL){   
       printf("\nNumero nao existe na arvore!\n");
       getch();
       return;
    }
    if(preco < (*t)->preco)
       remover(&(*t)->noesq, preco);
    else if(preco > (*t)->preco)
          remover(&(*t)->nodir, preco);
       else{   
         No *tAux = *t;
          if ( ((*t)->noesq == NULL) && ((*t)->nodir == NULL)){
                free(tAux);
                (*t) = NULL;
              printf("removido com sucesso\n");
            }
          else{     
             if ((*t)->noesq == NULL){
                (*t) = (*t)->nodir;
                tAux->nodir = NULL;
                free(tAux); 
				tAux = NULL;
                 printf("removido com sucesso\n");
                }
             else{           
                if ((*t)->nodir == NULL){
                    (*t) = (*t)->noesq;
                    tAux->noesq = NULL;
                    free(tAux); 
					tAux = NULL;
                    printf("removido com sucesso\n");
                    }
                else{       
                   tAux = MaiorDireita(&(*t)->noesq); 
                   tAux->noesq = (*t)->noesq;          
                   tAux->nodir = (*t)->nodir;
                   (*t)->noesq = NULL;
				   (*t)->nodir = NULL;
                   free((*t));
                    (*t) = tAux;
				   tAux = NULL;
				   printf("removido com sucesso\n");
                   }
                }
             }
          }
}

float procurar(struct No *t,float preco) {
     if(t == NULL){   
       printf("\nNumero nao existe na arvore!\n");
       getch();
       return 0;
    }
    if(preco < t->preco)
       procurar(t->noesq, preco);
    else if(preco > t->preco)
          procurar(t->nodir, preco);
       else{
       	printf("\nHa um tenis no preco desejado de %.2f, deseja comprar?\n",t->preco);
 }
}
float emOrdem(struct No *t) {
     if(t != NULL) {
         emOrdem(t->noesq);
         printf("%.2f ",t->preco);
         emOrdem(t->nodir);
     }
 }

float preOrdem(struct No *t) {
    if(t != NULL) {
        printf("%.2f ",t->preco);
        preOrdem(t->noesq);
        preOrdem(t->nodir);

    }

}
float posOrdem(struct No *t) {
    if(t != NULL) {

        posOrdem(t->noesq);
        posOrdem(t->nodir);
        printf("%.2f ",t->preco);

    }

}
 

