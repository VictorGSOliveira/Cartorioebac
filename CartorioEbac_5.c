#include <stdio.h> //biblioteca de comuniação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings
//
//
//função registro
int registro()
{ 
	printf("Você escolheu o registro de nomes.\n\n");
	
	//determinando os caracteres das variáveis.
	char arquivo[40]; 
	char cpf [40]; 
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	
	//cadastro cpf {
	
	printf("\nDigite o CPF a ser cadastrado(sem pontos): \n"); //coletando o cpf
	scanf("%s", cpf); //input cpf (s - save)
	
	strcpy(arquivo, cpf); //copia dos valores das strings(cpf)
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arq (w - write)
	fprintf(file,cpf); //salva o valor do arq
	fclose(file); //fecha o arq'
	
	file = fopen(arquivo, "a");//atualizar com , (a - atualize)
	fprintf(file,", ");
	fclose(file);
	
	//cadastro nome {
	
	printf("\nDigite o Nome a ser cadastrado: \n"); //coletando o nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	//cadastro sobrenome {
	
	printf("\nDigite o Sobrenome a ser cadastrado: \n"); //coletando o sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	//cadastro cargo {
	
	printf("\nDigite o Cargo a ser cadastrado: \n"); //coletando o cargo
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
//
//função consulta
int consulta()
{ 

	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("\nVocê escolheu a consulta de nomes! \n\n");
	
	printf("\nDigite o CPF a ser consultado(sem pontos): \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //ler o aquivo cpf
	
	if(file == NULL){
		printf("\nNão foi possível locarlizar este CPF!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
//
//função deletar
int deletar()
{ 
	printf("\nVocê escolheu deletar nomes.\n");
	
	char cpf[40];
	
	printf("\nDigite o CPF a ser deletado(sem pontos): \n");
	scanf("%s", cpf); //guardar o cpf na variavel
	
	remove(cpf); //apagar a variavel com o cpf
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Este arquivo não se encontra no sistema!\n"); // verificar se o cpf da variável existe.
	}
	
	system("pause");
	
}



int main() {
	
	int opcao=0; //definindo a variável
	int rMenu=1;
	
	for(rMenu=1;rMenu=1;){ //inicio da repetição e quando será repetida
	
		system("cls"); //limpar a área
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem(idioma)
	
		printf("\n### Cartório da EBAC ###\n\n"); //início menu
		printf("Escolha a opção desejada do menu:\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n\n");
		printf("Opção: "); //fim menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //limpar a área
	
		//início da seleção	
		switch(opcao){
			case 1:
				registro(); //chamada de funções
				break;
			
			case 2:
				consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			default:
				printf("Essa opção está indisponível!\n");
				system("pause");
				break;
		}			
		//final da seleção
	}
}




