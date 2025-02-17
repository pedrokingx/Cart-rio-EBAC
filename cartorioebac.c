#include <stdio.h> //biblioteca de comunicação com usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsavel por cuidar das string

 int registro() //função resonsavel por cadastrar os usuarios
{  
    char arquivo[40]; //inicio da criação das variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // final das criações das variaveis
	
	printf("Digite o CPF para cadastro: "); //coletando informações do usuario
	scanf("%s",cpf); //salvando a string
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string
	
	FILE *file; //criar arquivo
	file = fopen(arquivo,"w"); //criar o arquivo e escrever
	
	fprintf(file,cpf); //salvar o valor da variavel
	fclose(file); //fechar arquivo
	
	file = fopen (arquivo,"a"); //atualizar arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome para cadastro: ");
	scanf("%s",nome);
	
	file = fopen (arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome para cadastro: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo para cadastro: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("cls"); // limpar aba anterior 
	
	printf("Usuario cadastrado com sucesso! \n");
	
	system("pause"); //pausar a tela
	
	
}
   
 int consultar() // função responsavel por consultar usuarios
 {
   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
   char cpf[40];
   char conteudo[100];
	
   printf("Digite o CPF a ser consultado: ");
   scanf("%s",cpf);
  	
   FILE *file;
   file = fopen(cpf,"r");
  	
   if(file == NULL) // comando para arquivo não existente
 {
   printf("Não foi possivel abrir o arquivo, usuario não localizado!\n");
 }
	
   while(fgets(conteudo, 100, file) != NULL)
 {
   printf("\nEssas são as informações do usuario: ");
   printf("%s", conteudo);
   printf("\n\n");
 }
  	
   system ("pause");

}

 int deletar() //função para deletar usuarios
{
   char cpf[40];
   
   printf("Digite o usuaria para ser deletado: ");
 
   scanf("%s" , cpf);
   
   remove(cpf); //deletar arquivo 
   
   FILE *file;
   file = fopen(cpf , "r");
   
   if(file == NULL)
 {
   printf("Usuario deletado com sucesso! \n");
   system("pause");
 }
   
}

int main () //funçao principal
{
   int opcao=0; //definindo variaveis 
   int x=1;
	
   for(x=1;x=1;)
 {
    system("cls");
		 
    setlocale(LC_ALL, "portuguese"); 
   	
    printf("\tCartório da EBAC\n\n"); //inicio do menu
    printf("  Selecione a opção desejada:\n\n");
    printf("1- Registrar nomes\n");
    printf("2- Consultar nomes\n");
    printf("3- Deletar nomes\n\n\n");
	printf("digite a opção: "); //fim do menu

    scanf("%d", &opcao); //armazenando a escolha do usuario
	
    system("cls"); 

    switch(opcao) //inicio da seleção do menu
{
    case 1:
    registro(); //chamada de fução		
    break;
    	
    case 2:
    consultar();   	
	break;
	    	
	case 3:
	deletar();   	
	break;
			
	default:
	printf("opção indisponível!\n"); //fim da seleçao do menu
	system("pause");
	break;
}
	
    
 }

}

