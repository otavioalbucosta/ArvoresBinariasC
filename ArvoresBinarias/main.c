#include <stdio.h>
#include <stdlib.h>
#include "arvbin.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){
    system("cls");
    printf("==================================================================\n");
    printf("ESCOLHA O NUMERO DE ACORDO COM A OPERACAO DESEJADA!\n");
    printf("1 -- INSERIR PRECO DO TENIS NA ARVORE\n");
    printf("2 -- PROCURAR VALOR DE TENIS NA ARVORE\n");
    printf("3 -- REMOVER VALOR DE TENIS DA ARVORE\n");
    printf("4 -- LISTAR TODOS OS VALORES DOS TENIS DA ARVORE EM ORDEM\n");
    printf("5 -- LISTAR TODOS OS VALORES DOS TENIS DA ARVORE EM PRE ORDEM\n");
    printf("6 -- LISTAR TODOS OS VALORES DOS TENIS DA ARVORE EM POS ORDEM\n");
    printf("7 -- SAIR DO PROGRAMA\n");
    printf("=================================================================\n");
}
void chose(){

    printf("Escolha em qual marca voce deseja fazer a operacao:\n");
    printf("1 -- Nike\n");
    printf("2 -- Adidas\n");
    printf("3 -- Olympikus\n");
}

int main(void) {
	No *nike;
	No *adidas;
	No *olympikus;
	criarArvore(&nike);
	criarArvore(&adidas);
	criarArvore(&olympikus);
	insertTree(&nike,100.0);
	insertTree(&nike,95.0);
	insertTree(&nike,120.0);
	insertTree(&nike,80.0);
	insertTree(&nike,140.0);
	insertTree(&nike,195.0);
	insertTree(&nike,70.0);
	insertTree(&nike,82.50);
	insertTree(&adidas,115.0);
	insertTree(&adidas,120.0);
    insertTree(&adidas,96.0);
    insertTree(&adidas,150.0);
    insertTree(&adidas,105.0);
    insertTree(&adidas,140.0);
    insertTree(&adidas,85.0);
    insertTree(&adidas,180.0);
	insertTree(&olympikus,150.0);
	insertTree(&olympikus,100.0);
	insertTree(&olympikus,170.0);
	insertTree(&olympikus,80.0);
	insertTree(&olympikus,140.0);
	insertTree(&olympikus,190.0);
	insertTree(&olympikus,60.0);
	insertTree(&olympikus,200.0);
	int x = 0;
	while(x ==0){
	    menu();
	    int op = 0;
        int opt;
        float price;
	    scanf("%d",&op);

	    switch (op){
	        case 1:
	            chose();

	            scanf("%d",&opt);
	            printf("Digite o preco\n");
	            scanf("%f",&price);
	            if (opt==1) {
                    insertTree(&nike, price);
                    printf("Inserido com sucesso!\n");
                    system("pause");
                }else if (opt==2) {
                    insertTree(&adidas, price);
                    printf("Inserido com sucesso!\n");
                    system("pause");
                }else if (opt==3) {
                    insertTree(&olympikus, price);
                    printf("Inserido com sucesso!\n");
                    system("pause");
                }else{
                    printf("digite uma operacao correta na proxima vez");
                }
	        break;
            case 2:
                chose();
                scanf("%d",&opt);
                printf("Digite o preco a ser procurado\n");
                scanf("%f",&price);
                if (opt==1) {
                    procurar(nike, price);
                    system("pause");
                }else if (opt==2) {
                    procurar(adidas, price);
                    system("pause");
                }else if (opt==3) {
                    procurar(olympikus, price);
                    system("pause");
                }else{
                    printf("digite uma operacao correta na proxima vez");
                }

            break;
            case 3:
                chose();
                scanf("%d",&opt);
                printf("Digite o preco a ser removido\n");
                scanf("%f",&price);
                if(opt==1){
                    remover(&nike,price);
                    system("pause");
                }else if(opt==2){
                    remover(&adidas,price);
                    system("pause");
                }else if(opt==3){
                    remover(&olympikus,price);
                    system("pause");
                }else{
                    printf("digite uma operacao correta na proxima vez");
                }
            break;
            case 4:
                chose();
                scanf("%d",&opt);
                if(opt==1){
                    emOrdem(nike);
                    printf("\n");
                    system("pause");
                }else if(opt==2){
                    emOrdem(adidas);
                    printf("\n");
                    system("pause");
                }else if(opt==3){
                    emOrdem(olympikus);
                    printf("\n");
                    system("pause");
                }else{
                    printf("digite uma operacao correta na proxima vez");
                }
            break;
            case 5:
                chose();
                scanf("%d",&opt);
                if(opt==1){
                    preOrdem(nike);
                    printf("\n");
                    system("pause");
                }else if(opt==2){
                    preOrdem(adidas);
                    printf("\n");
                    system("pause");
                }else if(opt==3){
                    preOrdem(olympikus);
                    printf("\n");
                    system("pause");
                }else {
                    printf("digite uma operacao correta na proxima vez");
                }
            break;
	        case 6:
                chose();
                scanf("%d",&opt);
                if(opt==1){
                    posOrdem(nike);
                    printf("\n");
                    system("pause");
                }else if(opt==2){
                    posOrdem(adidas);
                    printf("\n");
                    system("pause");
                }else if(opt==3){
                    posOrdem(olympikus);
                    printf("\n");
                    system("pause");
                }else{
                    printf("digite uma operacao correta na proxima vez");
                }
            break;
            case 7:
                x=2;
                break;
            default:
                break;
	    }
	}

 }


