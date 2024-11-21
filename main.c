#include <stdio.h>
#include <stdlib.h>

void preencher(char* his[], int valor, int categoria );
void Imprimir_Histograma(char* his[], int valor[], int categoria);

int main(){

    
    int qtd_categ, i;
    scanf("%d", &qtd_categ);

    char *histograma[qtd_categ];
    int vendasPorCateg[qtd_categ];

    for(i=0; i<qtd_categ; i++){

        scanf("%d", &vendasPorCateg[i]);
        
        if(vendasPorCateg[i] == 0){
            histograma[i] = NULL;
        }
        else{
            histograma[i] = (char *) malloc(vendasPorCateg[i]* sizeof(char));
            preencher(histograma, vendasPorCateg[i], i);
        }

    }
    Imprimir_Histograma(histograma, vendasPorCateg, qtd_categ);

    for(i=0; i<qtd_categ; i++){
        free(histograma[i]);
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
