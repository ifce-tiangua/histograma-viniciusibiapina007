#include <stdio.h>
#include <stdlib.h>

void preencher(char* his[], int valor, int categoria );
void Imprimir_Histograma(char* his[], int valor[], int categoria);

int main(){
    
    int qtd_categ, i; // quantidade de categorias
    scanf("%d", &qtd_categ);

    char *histograma[qtd_categ]; // vetor de ponteiros para char
    int vendasPorCateg[qtd_categ]; // numero de ventas por caategoria

    for(i=0; i<qtd_categ; i++){

        scanf("%d", &vendasPorCateg[i]); // para cada categoria de indice i vai ler um valor
        
        if(vendasPorCateg[i] == 0){
            histograma[i] = NULL;
        }
        else{
            histograma[i] = (char *) malloc(vendasPorCateg[i]* sizeof(char)); // criar um veto dinamico na posicao i do histograma
            preencher(histograma, vendasPorCateg[i], i); // preencher este vetor dinamico com os asteristicos
        }

    }
    Imprimir_Histograma(histograma, vendasPorCateg, qtd_categ);  // imprime o histograma

    for(i=0; i<qtd_categ; i++){
        free(histograma[i]); // desalocar a memoria reservada para cada vetor dinamico do histograma
    }
    
    return 0;
}

void preencher(char* his[], int valor, int categoria){

    int i;

    for(i=0; i<valor; i++){
        his[categoria][i] = '*';
    }
}

void Imprimir_Histograma(char* his[], int valor[], int categoria){

    int i, j;

    if(categoria==0){
        printf("vazio\n");
    }
    
    for(i=0; i<categoria; i++){

        printf("%d ", valor[i]);

        if(valor[i] != 0){

            for(j=0; j<valor[i]; j++){
                printf("%c", his[i][j]);
            }
        }
        printf("\n");

    }
}
