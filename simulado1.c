#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[15];
	int poder;
}tpersonagem;

void imprime_tabuleiro(char tabuleiro[10][10][15]){
	int i,j;
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			printf(" %s ",tabuleiro[i][j]);
		}
		printf("\n");
	}
}

int posiciona(int linha, int coluna,char nome_personagem[], char tabuleiro[10][10][15]){
	if (linha > 9 || coluna > 9){
		return 0;
	}
	else {
		strcpy(tabuleiro[linha][coluna],nome_personagem);
		return 1;
	}
}

int ocorrencias(char nome_personagem[], char tabuleiro[10][10][15]){
	int i, j, cont=0;
	for (i=0;i<14;i++){
		for (j=0;j<10;j++){
			if ((strcmp(tabuleiro[i][j],nome_personagem)) == 0){
				cont++;
			}
		}
	}
	return cont;
}

int procurar_personagem (char nome_personagem[],tpersonagem personagens[30]){
	int i;
    for (i=0;i<30;i++){
    	if ((strcmp(personagens[i].nome,nome_personagem)) == 0){
        	return i;
        }
    }
    return -1;
}

int poder_total(tpersonagem personagens[30], char tabuleiro[10][10][15]){
	int linha,coluna,soma=0;
    char nome_personagem[15];
    for (linha=0;linha<10;linha++){
    	for (coluna=0;coluna<10;coluna++){
    		strcpy(nome_personagem,tabuleiro[linha][coluna]);
            int indice = procurar_personagem(nome_personagem,personagens);
            if (indice > -1){
            	soma = soma + personagens[indice].poder;
            }
        }
	}
    return soma;
}

int ataca(int linha, int coluna, tpersonagem personagens[30], char tabuleiro[10][10][15]){
	char nome_personagem[15];
	if (linha > 9 || coluna > 9 || strcmp(tabuleiro[linha][coluna],"") == 0){
		return 0;
	}
    else {
        strcpy(nome_personagem,tabuleiro[linha][coluna]);
        int indice = procurar_personagem(nome_personagem,personagens);
        if (indice > -1){
        	printf("\nPersonagem: %s",nome_personagem);
        	printf("\nValor: %d",personagens[indice].poder);
            }
    	strcpy(tabuleiro[linha][coluna],"");
    }
}

int main()
{
  char tabuleiro[10][10][15] = {
         {"mago", "", "", "", "", "fada", "", "","","vampiro"},
         {"", "", "dragao", "", "", "bruxa", "", "","",""},
         {"", "", "", "", "mago", "", "", "","",""},
         {"", "", "", "", "", "", "feiticeiro", "wendigo", "",""},
         {"", "", "", "cavaleiro", "", "", "", "","",""},
         {"", "", "", "", "duende", "", "", "","",""},
         {"", "", "", "", "", "", "vampiro",  "","",""},
         {"", "", "", "", "", "anjo", "lobisomem", "","",""},
         {"", "", "gnomo", "", "", "", "", "","",""},
         {"", "", "cavaleiro", "", "", "", "", "","","fada"}};
           

	tpersonagem  personagens[30]= {{"anjo",17},{"bruxa",12},{"cavaleiro",20},{"dragao",18},{"duende",5},
	{"fada",10},{"feiticeiro",12},{"gnomo",8},{"lobisomem",9},{"mago",15},{"princesa",4},
	{"vampiro",13},{"wendigo",16}};
	
	imprime_tabuleiro(tabuleiro);
	char nome[15]="princesa";
	printf("\n");
	printf("\n");
	posiciona(1,1,nome,tabuleiro);
	imprime_tabuleiro(tabuleiro);
	int teste = ocorrencias("feiticeiro",tabuleiro);
	printf("\n%d",teste);
    int teste_poder = poder_total(personagens,tabuleiro);
    printf("\n%d",teste_poder);
    ataca(1,1,personagens,tabuleiro);
    teste_poder = poder_total(personagens,tabuleiro);
    printf("\n%d",teste_poder);
	
	return 0;
}

