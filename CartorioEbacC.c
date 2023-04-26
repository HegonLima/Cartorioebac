#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro()  // fun��o de acordo com a op��o escolhida
{
	//inicio cria�ao de variaves/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); 		// responsavel por copiar os valores das string
	
	FILE *file;	 				// cria o arquivo 
	file = fopen(arquivo, "w");	// cria o arquivo
	fprintf(file,cpf);			// salva o valor da variavel
	fclose(file);				// fecha o arquivo
	
	file = fopen(arquivo,"a"); // "a" significa que vai abrir o arquivo e atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");	//config de linguagem e acentua��o 
	
	char cpf[40];
	char conteudo [200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // ''r'' para ler o arquivo digitado acima 
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, nao localizado!. \n"); // caso nao localize o dado digitado 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
	
}



int main()   //tela inicial do projeto
{
	//variavel de op��o
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //para limpar mensagengs do loop
	
		setlocale(LC_ALL, "Portuguese");	//config de linguagem e acentua��o  	
	
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		
		printf("\t1 - Registrar nomes\n"); 	//menu de op��es
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("op��o..."); 				//fim do menu
	
	
		scanf("%d", &opcao);   	//escolha da op��o oferecida para o usuario
	
		system("cls");  		//para limpar mensagengs anteriores	
			
			
		switch(opcao) 			//inicio da sele��o do meni
		{
			case 1:
			registro(); 		//chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("essa op��o nao est� disponivel\n\n\n\n");
			system("pause");
			break;				//fim da sele�ao 			
		}

}
}
