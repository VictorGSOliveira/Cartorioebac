#include <stdio.h> //biblioteca de comunia��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings
//
//
//fun��o registro
int registro()
{ 
	printf("Voc� escolheu o registro de nomes.\n\n");
	
	//determinando os caracteres das vari�veis.
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
//fun��o consulta
int consulta()
{ 

	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("\nVoc� escolheu a consulta de nomes! \n\n");
	
	printf("\nDigite o CPF a ser consultado(sem pontos): \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //ler o aquivo cpf
	
	if(file == NULL){
		printf("\nN�o foi poss�vel locarlizar este CPF!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
//
//fun��o deletar
int deletar()
{ 
	printf("\nVoc� escolheu deletar nomes.\n");
	
	char cpf[40];
	
	printf("\nDigite o CPF a ser deletado(sem pontos): \n");
	scanf("%s", cpf); //guardar o cpf na variavel
	
	remove(cpf); //apagar a variavel com o cpf
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Este arquivo n�o se encontra no sistema!\n"); // verificar se o cpf da vari�vel existe.
	}
	
	system("pause");
	
}



int main() {
	
	int opcao=0; //definindo a vari�vel
	int rMenu=1;
	
	for(rMenu=1;rMenu=1;){ //inicio da repeti��o e quando ser� repetida
	
		system("cls"); //limpar a �rea
		
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem(idioma)
	
		printf("\n### Cart�rio da EBAC ###\n\n"); //in�cio menu
		printf("Escolha a op��o desejada do menu:\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n\n");
		printf("Op��o: "); //fim menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //limpar a �rea
	
		//in�cio da sele��o	
		switch(opcao){
			case 1:
				registro(); //chamada de fun��es
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
				printf("Essa op��o est� indispon�vel!\n");
				system("pause");
				break;
		}			
		//final da sele��o
	}
}




