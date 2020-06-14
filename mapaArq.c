/*
	Gravar e carregar struct do arquivo
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#include <locale.h>

// declaração da struct pessoa
typedef struct obras
{
	char titulo[50];
	char autor[50];
	char editora[50];
	char isbn[50];
	int tipo, caixa;
	int ano, edicao, quantidadeExemplar;
} t_obras;

void identificacao(){
	system("cls");
	int t;
	for(t=0; t<80; t++) printf("-");
	printf("\n >>>> RAFAEL ALVES FLORINDO <<<<");
	printf("\n >>>> RA: 00000000-5 <<<< ");
	printf("\n >>>> Engenharia de Software <<<< \n");
	for(t=0; t<80; t++) printf("-");
}
// função para escrever os elementos de uma struct no arquivo
void escrever_arquivo(t_obras obras[])
{
	identificacao();
	int i;
//	int len_vet = sizeof(obrass) - 1; // tamanho do vetor
	FILE * arq;

	// abre o arquivo para escrita no modo append (adiciona ao final)
	arq = fopen("dados.txt", "a+");

	if(arq != NULL)
	{
		for(i = 0; i < 2; i++){
			fflush(stdin);
			printf("\nInforme o Tipo [1] livro | [2]: Revista: ");
			scanf("%d", &obras[i].tipo);
			fflush(stdin);
			printf("\nInforme o Título: ");
			gets(obras[i].titulo);
			printf("\nInforme o Autor: ");
			gets(obras[i].autor);
			printf("\nInforme a Editora: ");
			gets(obras[i].editora);
			printf("\nInforme o ISBN: ");
			gets(obras[i].isbn);
			printf("\nInforme a Edição: ");
			scanf("%d", &obras[i].edicao);
			printf("\nInforme a ano: ");
			scanf("%d", &obras[i].ano);
			printf("\nInforme a quantidade de Exemplares: ");
			scanf("%d", &obras[i].quantidadeExemplar);
			printf("\nInforme a caixa: ");
			scanf("%d", &obras[i].caixa);
			fwrite(&obras[i], sizeof(t_obras), 1, arq);
		}
		fclose(arq); // aborta o programa
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}

int ler_arquivo(t_obras aux_obras[MAX])
{
	FILE * arq = fopen("dados.txt", "r");
	if(arq != NULL)
	{
		int indice = 0;
		while(1)
		{
			t_obras p;
			size_t r = fread(&p, sizeof(t_obras), 1, arq);
			if(r < 1)
				break;
			else
				aux_obras[indice++] = p;
		}
		fclose(arq); // fecha o arquivo
		return indice;
	}
	else
	{
		printf("\nErro ao abrir o arquivo para leitura!\n");
		exit(1); // aborta o programa
	}
}


void imprimir_Livro(t_obras aux_obras[MAX]){	
	identificacao();
	FILE *arq; 	
	arq = fopen ("dados.txt", "r");
	fread(aux_obras, sizeof (int), 10, arq); 	
	int len_vet = ler_arquivo(aux_obras);	
	int i,rID;
	int j=0;
	rID = 0;
	printf("\n>>>> Lista de Livros <<<< \n");
	for(i = 0; i < len_vet; i++)
	{
		if(aux_obras[i].tipo == 1){		
			printf("\nItem: %d \tTítulo: %s\t Autor: %s", i+1, aux_obras[i].titulo, aux_obras[i].autor);
			printf("\nEditora: %s \tEdição: %d", aux_obras[i].editora, aux_obras[i].edicao);
			printf("\nISBN: %s \t Ano: %d \tQuantidade: %d \t Caixa: %d", aux_obras[i].isbn, aux_obras[i].ano, aux_obras[i].quantidadeExemplar, aux_obras[i].caixa);
			printf("\n***************************************************************\n");
			j++;
		}
	}
	if (j>0) printf("\nForam impressos %d livros.", j);
	else printf("\nNão há obras cadastradas.");
}
void imprimir_Revista(t_obras aux_obras[MAX]){	
	identificacao();
	FILE *arq; 	
	arq = fopen ("dados.txt", "r");
	fread(aux_obras, sizeof (int), 10, arq); 	
	int len_vet = ler_arquivo(aux_obras);	
	int i,rID;
	int j=0;
	rID = 0;
	printf("\n>>>> Lista de Revistas <<<<");
	for(i = 0; i < len_vet; i++)
	{
		if(aux_obras[i].tipo == 2){
			printf("\nItem: %d \tTítulo: %s\t Autor: %s", i+1, aux_obras[i].titulo, aux_obras[i].autor);
			printf("\nEditora: %s \tEdição: %d", aux_obras[i].editora, aux_obras[i].edicao);
			printf("\nISBN: %s \t Ano: %d \tQuantidade: %d \t Caixa: %d", aux_obras[i].isbn, aux_obras[i].ano, aux_obras[i].quantidadeExemplar, aux_obras[i].caixa);
			printf("\n***************************************************************\n");
			j++;
		}
	}
	if (j>0) printf("\nForam impressas %d revistas.", j);
	else printf("\nNão há obras cadastradas.");
}
void busca_caixa(t_obras aux_obras[MAX]){
	identificacao();
	FILE *arq; 	
	arq = fopen ("dados.txt", "r");
	fread(aux_obras, sizeof (int), 10, arq); 	
	int len_vet = ler_arquivo(aux_obras);	
	int i,rID;
	rID = 0;
	int nCaixa;
	int j=0;
	printf("\nInforme o número das caixa a ser pesquisada:");
	fflush(stdin);
	scanf("%d", &nCaixa);
	printf("\n>>>> Lista de Obras por caixa <<<<");
	printf("\nCaixa selecionada: %d", nCaixa);
	for(i = 0; i < len_vet; i++)
	{
		if(aux_obras[i].caixa == nCaixa){
			if (aux_obras[i].tipo ==1) printf("\nLivro");
			if (aux_obras[i].tipo ==2) printf("\nRevista");
			printf("\nItem: %d \tTítulo: %s\t Autor: %s", i+1, aux_obras[i].titulo, aux_obras[i].autor);
			printf("\nEditora: %s \tEdição: %d", aux_obras[i].editora, aux_obras[i].edicao);
			printf("\nISBN: %s \t Ano: %d \tQuantidade: %d \t Caixa: %d", aux_obras[i].isbn, aux_obras[i].ano, aux_obras[i].quantidadeExemplar, aux_obras[i].caixa);
			printf("\n***************************************************************\n");
			j++;
		}
	}
	if (j>0) printf("\nForam impressos %d obras.", j);
	else printf("\nNão há obras cadastradas.");
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Portuguese");
	int op;
	t_obras obras[MAX];
	do{
		identificacao();
		printf("\n1 - Cadastrar obras");
		printf("\n2 - Listar todos os Livros");
		printf("\n3 - Listar todas as Revistas");
		printf("\n4 - Listar Obras por caixa");
		printf("\n0 - Sair");
		printf("\nEscolha Opção: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				escrever_arquivo(obras);
				break;
			case 2:
				imprimir_Livro(obras);
				printf("\n");
				system("pause");
				break;
			case 3: 
				imprimir_Revista(obras);
				printf("\n");
				system("pause");
				break;
			case 4: 
				busca_caixa(obras);
				printf("\n");
				system("pause");
				break;
			case 0:
				printf("\nSaindo do sistema!!!");
				break;
			default:
				printf("Valor indefinido");
				system("pause");
				break;
		}	
	}while(op!=0);
	return 0;
}
