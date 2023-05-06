#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro()  // função de acordo com a opção escolhida
{
	//inicio criaçao de variaves/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
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
	fprintf(file,",");			// função para separar os dados cadastrados com  uma'','' (virgula)
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
	setlocale(LC_ALL, "Portuguese");	//config de linguagem e acentuação 
	
	char cpf[40];
	char conteudo [200];
	
	printf ("Digite o CPF a ser consultado: ");  //recebendo dados para consultar o usuario
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // ''r'' para ler o arquivo digitado acima 
	
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, nao localizado!. \n"); // caso nao localize o dado digitado 
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
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
	fclose(file);
	
	if(file == NULL)
	{
		printf("O Usuário não se encontra no sistema!. \n");
		system("pause");
	}
	
}

int main()   //tela inicial do projeto
	{
	int opcao=0; //variavel de opção
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de Administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{	
		
		for(laco=1;laco=1;)
		{				
			system("cls"); //para limpar mensagengs do loop
			setlocale(LC_ALL, "Portuguese");	//config de linguagem e acentuação  	
	
			printf("### Cartório da EBAC ###\n\n");
			printf("Escolha a opção desejada do menu:\n\n");		
			printf("\t1 - Registrar nomes\n"); 	//menu de opções
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("opção: "); 				    //fim do menu
	
	
			scanf("%d", &opcao);   	//escolha da opção oferecida para o usuario
	
			system("cls");  		//para limpar mensagengs anteriores	
			
			
			switch(opcao) 			//inicio da seleção do meni
			{
				case 1:
				registro(); 		//chamada de funções de registro
				break;
			
				case 2:
				consulta();			//chamada de funções de consulta
				break;
			
				case 3:
				deletar();			//chamada de funções de deletar
				break;
			
				case 4:
				printf("obrigado por utilizar o sistema!\n"); // mensagem de finalizaçao do sistema
				return 0;
				break;
			
				default:
				printf("essa opção nao está disponivel\n\n\n\n");  // em caso de opção inexistente
				system("pause");
				break;				//fim da seleçao 			
			}
		}
	}
	
	else
		printf("Senha incorreta!");  // caso digite a senha incorreta
}	
