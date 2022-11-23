#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct itens {
	int quantidade;
	float valor;
	char nome[50];
};

int main() {
	
	setlocale(LC_ALL, "");
	
	//declaração de variáveis
	int i, j, k, l;
	int qtd_carrinho = 0, qtd_caixa = 0;
	float soma = 0;
	struct itens carrinho[10];
	struct itens caixa[10];
	
	//ENTRADA - Menu do Código
	while(1) {
		printf("-----------------------------------------\n");
		printf("1 - Inserir apenas um item\n");
		printf("2 - Processar apenas um item\n");
		printf("3 - Processar todos os itens\n");
		printf("4 - Mostrar itens do carrinho\n");
		printf("5 - Imprimir nota fiscal\n");
		printf("6 - Sair\n");
		scanf("%d", &i);
		
	//PROCESSAMENTO
		switch(i) {
			
			//Insere apenas um item
			case 1:
				printf("-----------------------------------------\n");
				if (qtd_carrinho < 10) { //enquanto a quantidade de itens for menor que 10, o carrinho não está cheio
					printf("Nome do produto: ");
					scanf("%s", carrinho[qtd_carrinho].nome);
					
					printf("Quantidade do produto: ");
					scanf("%d", &carrinho[qtd_carrinho].quantidade);
					
					printf("Valor individual do produto: ");
					scanf("%f", &carrinho[qtd_carrinho].valor);
					
					printf("-----------------------------------------\n");
					printf("Quantidade: %dx\nProduto: %s\nValor R$%.2f\n", carrinho[qtd_carrinho].quantidade, carrinho[qtd_carrinho].nome, carrinho[qtd_carrinho].valor);
					
					qtd_carrinho += 1; //aumenta o número de itens dentro do carrinho
					
				}else {
					printf("Não há mais espaço no carrinho!\n");
				}
				break;
				
			//Processa apenas um item
			case 2:
				printf("-----------------------------------------\n");
				if (qtd_carrinho > 0) { //verificar se existe item dentro do carrinho para ser processado
					if (qtd_caixa < 10) { //se a quantidade de itens do caixa for menor que 10, o caixa não está cheio
						caixa[qtd_caixa] = carrinho[qtd_carrinho - 1]; //o caixa recebe os itens do carrinho
						
						printf("%dx %s: %.2f\n", caixa[qtd_caixa].quantidade, caixa[qtd_caixa].nome, (float)caixa[qtd_caixa].quantidade * caixa[qtd_caixa].valor);
						
						//diminui os itens do carrinho e aumenta os itens do caixa
						qtd_carrinho -= 1;
						qtd_caixa += 1;
						
					}else {
						printf("Caixa cheio!\n");
					}
				}else {
					printf("O carrinho está vazio!\n");
				}
				break;
				
			//Processa todos os itens do carrinho
			case 3:
				printf("-----------------------------------------\n");
				if (qtd_carrinho == 0) {
					printf("Carrinho vazio!\n");
				}
				
				for (j = qtd_carrinho - 1; qtd_caixa < 10 && qtd_carrinho > 0; j--) { //o 'for' vai rodar até que não exista mais itens dentro do carrinho
				caixa[qtd_caixa] = carrinho[qtd_carrinho - 1];
				
				printf("%dx %s: %.2f\n", caixa[qtd_caixa].quantidade, caixa[qtd_caixa].nome, (float)caixa[qtd_caixa].quantidade * caixa[qtd_caixa].valor);
						
				qtd_carrinho -= 1;
				qtd_caixa += 1;
				}
				break;
			
			//Mostrar itens do carrinho
			case 4:
				printf("-----------------------------------------\n");
				if (qtd_carrinho != 0) { //verifica se existe item dentro do carrinho
					for (k = qtd_carrinho - 1; k >= 0; k--) { //o 'for' vai rodar até que tenha algum item dentro do carrinho
						printf("%dx\t%s\t\t\t\t\tR$ %.2f\t\n", carrinho[k].quantidade, carrinho[k].nome, carrinho[k].valor);
						
					}
				}else {
					printf("Carrinho vazio!\n");
				}
				break;
			
			//Imprimir a nota fiscal
			case 5:
				printf("-----------------------------------------\n");
				printf("Itens comprados: \n");
				printf("Quantidade		Descrição		Valor final		\n");
				printf("************************************************************\n");
				
				if (qtd_caixa != 0) { //verifica se existe item dentro do caixa
					for (l = 0; l < qtd_caixa; l++) { //o 'for' vai rodar até printar todos os itens que estão no vetor do caixa
						printf("%dx\t%s\t\t\t\t\tR$ %.2f\t\n", caixa[l].quantidade, caixa[l].nome, caixa[l].valor);
						
						soma += caixa[l].quantidade * caixa[l].valor;
					}
					printf("************************************************************\n");
					printf("Total:\t\t\t\t\t\tR$ %.2f\n", soma);
				}else {
					printf("Caixa vazio!\n");
				}
				break;
				
			//Sair do programa
			case 6:
				printf("Obrigado por usar o nosso programa!!\n");
				return 0;
		}
	}
}