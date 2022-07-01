// Primeiramente, nos incluimos nossas bibliotecas, para poder utilizar suas funções

#include <stdio.h>  // Stdio.h nos usamos para utilizar funções para ler e imprimir dados
#include <stdlib.h>  // Stdlib.h nos usamos para utilizar funções do sistema
#include <conio.h>  // Conio.h nos usamos para utilizar funções como o gets e getch
#include <string.h> // String.h nos usamos para utilizar funções para manipular strings
#include <time.h>  // Time.h nos usamos para utilizar funções relacionadas a espaço tempo * COMO LOCAL TIME E STRUCT TM

//FUNÇÕES PARA LÓGICA DE CALCULO 
float residencial(float valorFixoResidencial, float kwh){
	float valorResidencial = valorFixoResidencial*kwh;
	return(valorResidencial);
}

float comercial(float valorFixoComercial, float kwh){
	float valorComercial = valorFixoComercial*kwh;
	return(valorComercial);
}

float industrial(float valorFixoIndustrial, float kwh){
	float valorIndustrial = valorFixoIndustrial*kwh;
	return(valorIndustrial);
}


int main(){
	system("color A"); //Utilizado para mudar a cor da letra ou cor de fundo do terminal (cmd), a letra A corresponde a cor verde
	
// VARIAVEIS DE LOGIN =============================	
	char nomeAcesso[30]; 
	char senhaAcesso[10];
	
// VARIAVEIS DE ESCOLHA =============================
	int i, j;
	int opcao;
	int escolha;	
	
// VARIAVEIS DE  QUANTIDADE DE CADASTRO, ALTERACAO OU EXCLUSAO ============================= (RELACIONADA A QUANTIDADE DE CADASTROS QUE VOCE IRA FAZER, ALTERAR OU EXCLUIR)										
	int quantidadeUsuarios;	
		
// VARIAVEIS DE CADASTRO  =============================								
	char nomeUsuario[1000] [100];														
	char identificadorUsuario[1000] [100];																	
	float kwhGastosUsuario[1000];
	int classificacaoUsuario[1000];
	
// TAXAS POR KWH
	float valorFixoResidencial = 0.4;
	float valorFixoComercial = 0.6;
	float valorFixoIndustrial = 0.9;
		
// VARIAVEIS AUXILIARES QUE ARMAZENAM O VALOR DA CONTA	

		
// VARIAVEIS DE PREÇO E CALCULO TOTAL E MEDIA PONDERADA DE CONSUMO	
	float precoRecibo[1000];	
	float somaValores = 0;
	float mediaKWH = 0;
	
// LOGIN DO SISTEMA
	printf ("\n Digite o nome de acesso : \t");
	fflush(stdin); // FFLUSH STDIN PARA LIMPAR O "LIXO" DE MEMORIA QUE ACABA FICANDO, E MUITAS VEZES OCASIONA A ALGUM BUG OU CRASH DO PROGRAMA
	gets(nomeAcesso);
	printf("\n");				
									
	printf ("\n Digite a senha de acesso : \t");
	fflush(stdin);
	scanf ("%s", &senhaAcesso); // Colocamos o login e senha normalmente (o usuario podemos colocar qualquer um, a senha tem que ser a correspondente
	printf("\n");                     // que no caso é contadeluz2105
//VERIFICACAO DE SENHA
	for(i=0;senhaAcesso[i];i++)  // Aqui nos usamos para verificar se a senha digitada é correta
		    senhaAcesso[i]=tolower(senhaAcesso[i]);  
		    if(strcmp(senhaAcesso,"contadeluz2105")==0){  // Aqui iniciamos o  for em 0, no  laço de parada, definimos a variavel
		    	                                           // que vai ler a senha digitada, apos isso, o incremento ira adicionar essa senha, ou seja, inicia em 0
		    		system("cls");                         // para quando terminar a leitura da senha digitada, e adiciona essa senha digitada 
					   										// apos, nos pegamos nossa variavel de senha, colocamos ela para receber a conversao para minusculo do que
		            printf(" \n Seja bem vindo(a), %s \n", nomeAcesso);// foi digitado, e a funçao strcmp para comparar o que foi digitado com a senha correta
		            sleep(1);  
					                                         // para entao, entrar no programa ( se a senha for errada ele vai reiniciar o programa)
					                                         
		      		struct tm *dataHoraAtual;      // Aqui nos definimos nossa estrutura como tm  e completamos com um ponteiro  para ver a data e hora
					                               // Ou seja, nessa estrutura (colecao de variaveis) nos temos a variavel para printar a data e hora atual
					                               //Nos temos a variavel segundos, que recebe nomeacao da propria biblioteca (time_t)
					time_t segundos;               // Temos a variavel time chamando os segundos e temos o nosso ponteiro  recebendo localtime chamando tambem os segundos
					                               // vai ser aonde ira realizar a conversao para minuto, segundo e hora, dias meses e anos, de acorcom com funçoes da 
					                               // propria biblioteca
					time(&segundos);     					
					dataHoraAtual = localtime(&segundos);

					printf("\n");	            
		            printf("\n Data de acesso : %d / %d / %d", dataHoraAtual->tm_mday, dataHoraAtual->tm_mon+1,  dataHoraAtual->tm_year+1900);
					printf("\n Horario de acesso : %d : %d : %d", dataHoraAtual->tm_hour, dataHoraAtual->tm_min, dataHoraAtual->tm_sec);
					sleep(3);
					system("cls");	
					printf(" \n Digite a quantidade de usuarios\n para cadastrar %s: \t", nomeAcesso);
					scanf("%d", &quantidadeUsuarios);
					float quantidade = quantidadeUsuarios;
					printf("\n\n");
					system("pause");
					system("cls");
					for (i=0;i<quantidadeUsuarios;i++){  // Aqui temos nossa estrutura de repeticao, que vai ate a quantidade de cadastros que voce colocar											
						printf ("\n\n   CADASTRO DO %d FUNCIONARIO", i+1);
						printf ("\n\n Digite o nome completo do usuario : \t");
						fflush (stdin);
						scanf ("%[^.\n]s", &nomeUsuario[i]);  // Uma outra forma de ler do usuario, parecida com o gets, ela  lê uma string do usuario (considerando os espaços em branco) até que o usuario dê enter, vamos						 
						printf ("\n Digite o numero de identificacao do usuario : \t");
						fflush (stdin);
						scanf ("%[^.\n]s", &identificadorUsuario[i]);								 				
						printf(" \n Digite a quantidade de KWH gastos no mes : \t");
						fflush (stdin);
						scanf ("%f", &kwhGastosUsuario[i]);
						printf(" \n Digite a classificacao do usuario\n1 - Residencial\n2 - Comercial\n3 - Industrial: \t");
						fflush (stdin);
						scanf ("%d", &classificacaoUsuario[i]);
						switch(classificacaoUsuario[i]){
							case 1:
								precoRecibo[i] = residencial(valorFixoResidencial, kwhGastosUsuario[i]); //função de calculo;
								break;
											
							case 2:
								precoRecibo[i] = comercial(valorFixoComercial, kwhGastosUsuario[i]); //função de calculo;
								break;
											
							case 3:
								precoRecibo[i] = industrial(valorFixoIndustrial, kwhGastosUsuario[i]); //função de calculo;
								break;	
											
							default:
								printf("Impossivel realizar calculo");
								break;		
							}
							somaValores = somaValores+precoRecibo[i];
							mediaKWH = mediaKWH+kwhGastosUsuario[i]/quantidade;
									
							system("cls");													
						}	
						printf(" \n CADASTRO CONCLUIDO COM SUCESSO !\n\n");						      
						system("pause");
						system("cls");											
					
					do{
						printf(" \n =====  =====  =====   =      =====    ===== ");
						printf(" \n =      =   =  =       =      =    =   =   = ");
						printf(" \n =      =   =  =====   =      =====    ===== ");
						printf(" \n =      =   =  =       =      =    =   =   = ");
						printf(" \n =====  =====  =====   =====  =====    =   = ");									
						printf(" \n 1 - EXIBIR RECIBO DOS USUARIOS"); // CUSTO TOTAL POR USUARIO AQUI
						printf(" \n 2 - EXIBIR RECIBO GERAL DE USUARIOS"); // CUSTO TOTAL DOS USUARIOS ENVOLVIDOS E MEDIA DE CONSUMI AQUI
						printf(" \n 3 - FECHAR"); // SAIR DO PROGRAMA
						printf("\n Digite a opcao desejada : \t ");
						scanf("%d", &escolha);
						system("cls");						
						switch(escolha) // aqui nos temos nossa condicional, se a pessoa digitar de 1 a 3, ele ira printar os casos, de acordo com a numeracao
						{  // se a pessoa digitar um numero fora, ele ira reiniciar o menu
										
// 1 CASE EXIBIR RECIBO DOS USUARIOS =====================================================================================================================================================																		
							case 1:
								system("cls");
								printf(" \n OPCAO SELECIONADA : EXIBIR RECIBO DOS USUARIOS");
								sleep(1);
								printf("...");
								system("cls");
								for (i=0; i<quantidadeUsuarios; i++){ // Aqui temos nossa estrutura de repeticao, que vai printar  ate a quantidade de cadastros que voce tiver colocado
																			
										printf(" \n ===============================");								 									
										printf ("\n      RECIBO DO %d USUARIO",  i+1);
										printf(" \n ===============================");										
										printf (" \n\n Nome do usuario : %s\n", nomeUsuario [i]);
										printf (" \n Identificador do usuario : %s\n", identificadorUsuario [i]);
										printf (" \n KWH gastos no mes : %.2f\n", kwhGastosUsuario[i]);
										if(classificacaoUsuario[i] == 1){
									    	printf (" \n Tipo de usuario : Residencial\n");	
										}else if(classificacaoUsuario[i] == 2){
											printf (" \n Tipo de usuario : Comercial\n");
										}else{
											printf (" \n Tipo de usuario : Industrial\n");
										}
										printf(" \n ===============================");
										printf (" \n Valor do recibo : R$ %.2f\n",  precoRecibo[i]);
										printf(" \n ===============================\n");
										system("pause");
										system("cls");
									}	
								system("cls");	
							break;						

// 2 CASE EXIBIR RECIBO GERAL DOS USUARIOS =====================================================================================================================================================							
							case 2:
								for (i=0; i<quantidadeUsuarios; i++){ // Aqui temos nossa estrutura de repeticao, que vai printar  ate a quantidade de cadastros que voce tiver colocado
									printf(" \n\n\n\n\n ===============================");								 									
									printf ("\n      RECIBO DO %d USUARIO",  i+1);
									printf(" \n ===============================");										
									printf (" \n\n Nome do usuario : %s\n", nomeUsuario [i]);
									printf (" \n Identificador do usuario : %s\n", identificadorUsuario [i]);
									printf (" \n KWH gastos no mes : %.2f\n", kwhGastosUsuario[i]);
									if(classificacaoUsuario[i] == 1){
									    printf (" \n Tipo de usuario : Residencial\n");	
									}else if(classificacaoUsuario[i] == 2){
										printf (" \n Tipo de usuario : Comercial\n");
									}else{
										printf (" \n Tipo de usuario : Industrial\n");
									}
									printf("\n");
									printf(" \n ================================================================================");	
									printf(" \n\n\n Digite ENTER para ( exibir ) a proxima lista ou para ( finalizar ) \t");
									getch();
									printf(" \n ================================================================================");	
									printf("\n\n");
								}
								system("cls");
								printf(" \n ===============================");
								printf(" \n Custo total R$ %.2f\n", somaValores); // CUSTO TOTAL DOS USUARIOS
								printf(" \n Media de consumo geral %.2f KWH\n", mediaKWH); // MEDIA DE CONSUMO GERAL DOS USUARIOS EM KWH
								printf(" \n ===============================\n");
								system("pause");
								system("cls");									
							break;

// 3 CASE SAIR =====================================================================================================================================================							
							case 3:
								system("cls");
								printf(" \n Saindo");
								sleep(1);
								printf("...");
								printf("\n");
								return 0;
							break;
							
							default:
								printf("Por favor, selecione uma opcao");
								system("cls");
								break;
						}
				}while(opcao!=3);	//Repita o menu ate que a opcao inserida seja diferente de 3 	
		}else{
			system("cls");		
			printf(" \n Erro, senha incorreta. Tente novamente"); //Else para senha, caso a senha digitada seja incorreta, o programa sera reinicializado
			printf("\n");
			sleep(1);
			printf(" \n REINICIANDO");	
			sleep(1);
			printf(" \n...");
			system("cls");
			return main();
		}	
}
