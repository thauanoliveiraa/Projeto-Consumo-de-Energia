#include <stdio.h>  // Biblioteca stdio.h usamos funções para ler e imprimir dados
#include <conio.h>  // Biblioteca conio.h usamos funções como o gets e getch
#include <string.h> // Bibliteca string.h usamos funções para manipular strings
#include <stdlib.h>  // Biblioteca Stdlib.h usamos funções do sistema

//FUNÇÕES PARA LÓGICA DE CALCULO 
float calculoResidencial(float residencial, float kwh){ //Função denominada calculo resindencial que retorna float, recebendo como argumentos a variavel referente ao tipo de usuario residencial e o valor de kwh gastos pelo usuario
	float residencialValor = residencial*kwh;
	return(residencialValor);
}

float calculoComercial(float comercial, float kwh){
	float comercialValor = comercial*kwh;
	return(comercialValor);
}

float calculoIndustrial(float industrial, float kwh){
	float industrialValor = industrial*kwh;
	return(industrialValor);
}


int main(){	
// VARIAVEIS DE LOGIN =============================	
	char nomeLogin[30]; //Definindo o maximo de caracteres para 30
	char senhaLogin[10];
	
// VARIAVEIS DE ESCOLHA =============================
	int i, j; // Iteração
	int opcao;
	int escolha;
	
// CADASTRO 								
	char nome[300] [50]; // Nos colchetes está sendo definido que a linha possui um tamanho maximo de 300 e a coluna um tamanho maximo de 50														
	char identificacao[300] [50];																	
	float kwhGastos[300];
	int classificacao[300];	
		
// QUANTIDADE DE CADASTROS					
	int quantidade;	
			
// VALOR DO RECIBO E CALCULOS DE MEDIA PONDERADA E CALCULO TOTAL
	float recibo[300];	
	float total = 0;
	float media = 0;
		
// VALORES PARA TIPO DE USUARIO
	float residencial = 0.4;
	float comercial = 0.6;
	float industrial = 0.9;	
	
// LOGIN DO SISTEMA
	printf(" -- LIGHT SYSTEM 8) --");
	printf ("\n Nome : \t");
	fflush(stdin); // usamos o fflush stdin pra limpar o lixo de memoria
	gets(nomeLogin);
	printf("\n");				
									
	printf ("\n Senha : \t");
	fflush(stdin);
	scanf ("%s", &senhaLogin); // Colocamos o login e senha normalmente, pode ser qualquer usuario e a senha tem que ser sistema25032004
	printf("\n");                    
//VERIFICACAO DE SENHA
	for(i=0;senhaLogin[i];i++)  // Aqui nos usamos para verificar se a senha digitada é correta (usando a funçao strcmp para comparar o que foi digitado com a senha correta)
		    senhaLogin[i]=tolower(senhaLogin[i]);  
		    if(strcmp(senhaLogin,"sistema25032004")==0){ 
		    	                                           
		    		system("cls");   // FUNÇÃO UTILIZADA PARA "FECHAR" O QUE TIVER ABERTO E EVITAR POLUIÇÃO VISUAL (system close)                     
					   									
		            printf(" \n Seja bem vindo(a) ao sistema da conta de luz, %s \n", nomeLogin);
		            sleep(2);  // SLEEP PARA ESPERAR 2 SEGUNDOS ATE PRINTAR OUTRA COISA									                                    
					system("cls");	
					printf(" \n Quantos usuarios voce quer cadastrar %s ? \t", nomeLogin);
					scanf("%d", &quantidade);
					float conversaoQuantidade = quantidade;
					printf("\n\n");
					system("pause");
					system("cls");
					for (i=0;i<quantidade;i++){  // estrutura de repeticao que vai ate a quantidade de cadastros que colocar										
						printf ("\n\n   %d CADASTRO", i+1); //No for esse i é uma variavel de iteração, ou seja, ele vai ler os dados e armazenar a cada loop for (guardando em um array 300 por 50 "300x50")
						printf ("\n\n Nome completo : \t");
						fflush (stdin);
						scanf ("%[^.\n]s", &nome[i]);  // forma de ler do usuario que é parecido com o gets, lê uma string considerando os espaços em branco até dar enter					 
						printf ("\n Numero de identificacao : \t");
						fflush (stdin);
						scanf ("%[^.\n]s", &identificacao[i]);								 				
						printf(" \n KWH gastos : \t");
						fflush (stdin);
						scanf ("%f", &kwhGastos[i]);
						printf(" \n Tipo de usuario\n1) - Residencial\n2) - Comercial\n3) - Industrial : \t");
						fflush (stdin);
						scanf ("%d", &classificacao[i]);
						switch(classificacao[i]){
							case 1:
								recibo[i] = calculoResidencial(residencial, kwhGastos[i]); 
								break;
											
							case 2:
								recibo[i] = calculoComercial(comercial, kwhGastos[i]); 
								break;
											
							case 3:
								recibo[i] = calculoIndustrial(industrial, kwhGastos[i]);
								break;	
											
							default:
								printf("Infelizmente nao foi possivel calcular");
								break;		
							}
							total = total+recibo[i];
							media = media+kwhGastos[i]/conversaoQuantidade;
									
							system("cls");													
						}	
						printf(" \n Cadastro realizado com sucesso !!!\n\n");						      
						system("pause");
						system("cls");											
					
					do{
						printf(" \n --- CONTA DE LUZ ---");								
						printf(" \n 1 - Mostrar recibos"); // Mostrar recibos de forma individual
						printf(" \n 2 - Mostrar recibos (GERAL)"); // Mostrar recibos de forma geral
						printf(" \n 3 - Quem somos ?"); // Mostrar recibos de forma geral
						printf(" \n 4 - Sair do sistema"); // Sair do sistema
						printf("\n Digite a opcao desejada : \t ");
						scanf("%d", &escolha);
						system("cls");						
						switch(escolha) //condicional onde se a pessoa digitar de 1 a 4 vai printar os casos
						{ 
										
// PRIMEIRO CASO : MOSTRAR RECIBOS																		
							case 1:
								system("cls");
								printf(" \n Exibindo recibos (individuais)");
								sleep(1);
								printf("...");
								system("cls");
								for (i=0; i<quantidade; i++){ // estrutura de repeticao que vai printar  ate a quantidade de cadastros tiver colocado
																			
										printf(" \n -------------------------------");								 									
										printf ("\n      -- RECIBO %d USUARIO --",  i+1);
										printf(" \n -------------------------------");										
										printf (" \n\n Nome : %s\n", nome [i]);
										printf (" \n Identificador : %s\n", identificacao [i]);
										printf (" \n KWH gastos : %.2f\n", kwhGastos[i]);
										if(classificacao[i]== 1){
									    	printf (" \n - Usuario residencial\n");	
										}
										else if(classificacao[i] == 2){
											printf (" \n - Usuario comercial\n");
										}
										else{
											printf (" \n - Usuario industrial\n");
										}
										printf (" \n Valor da conta : R$ %.2f\n",  recibo[i]);
										printf(" \n -------------------------------\n");	
										system("pause");
										system("cls");
									}	
								system("cls");	
							break;						

// SEGUNDO CASO : MOSTRAR RECIBOS DE FORMA GERAL 							
							case 2:
								system("cls");
								printf(" \n Exibindo recibos (geral)");
								sleep(1);
								printf("...");
								system("cls");
								for (i=0; i<quantidade; i++){ //estrutura de repeticao, que vai printar  ate a quantidade de cadastros que  tiver colocado								 									
									printf(" \n -------------------------------");	
									printf ("\n %d USUARIO ",  i+1);
									printf(" \n -------------------------------");											
									printf (" \n\n Nome  : %s\n", nome [i]);
									printf (" \n Identificador : %s\n", identificacao [i]);
									printf (" \n KWH gastos : %.2f\n", kwhGastos[i]);
									if(classificacao[i] == 1){
									    printf (" \n - Usuario residencial\n");	
									}
									else if(classificacao[i] == 2){
										printf (" \n - Usuario comercial\n");
									}
									else{
										printf (" \n - Usuario industrial\n");
									}
									printf("\n");
									printf(" \n -------------------------------");	
									printf(" \n\n\n Digite ENTER para mostrar a proxima lista \t");
									getch();
									printf(" \n -------------------------------");
									printf("\n\n");
								}
								system("cls");
								printf(" \n -------------------------------");
								printf(" \n Media ponderada de consumo %.2f KWH\n", media); // MEDIA PONDERADA DE CONSUMO DOS USUARIOS DO SISTEMA EM KWH
								printf(" \n Valor total do recibo R$ %.2f\n", total); // CUSTO TOTAL DE ACORDO COM A QUANTIDADE DE USUARIOS DO SISTEMA
								printf(" \n -------------------------------\n");
								system("pause");
								system("cls");									
							break;

// TERCEIRO CASO : QUEM SOMOS							
							case 3:
								system("cls");
								printf(" \n Quem somos ?"); 
								sleep(1);
								printf("...");
								system("cls");
								system("cls");
								printf(" \n -------------------------------");
								printf(" \n -------------------------------");
								printf(" \n Somos a empresa que cuida da sua conta de luz, sempre com voce !");
								printf(" \n LIGHT SYSTEM 8) \n"); 
								printf(" \n -------------------------------");
								printf(" \n -------------------------------\n");
								system("pause");
								system("cls");																
								break;

// QUARTO CASO : SAIR DO SISTEMA 							
							case 4:
								system("cls");
								printf(" \n Sair do sistema");
								sleep(1);
								printf("...");
								system("cls");
								printf(" \n Saindo");
								sleep(1);
								printf("...");
								printf(" \n Obrigado por utilizar nosso sistema, volte sempre ;)");
								sleep(1);
								printf("\n");
								return 0;
							break;
							
							default:
								printf("Selecione uma opcao");
								system("cls");
								break;
						}
				}while(opcao!=4);	//Aqui é para repetir o menu ate que a opcao seja diferente de 4 	
		}
		else{
			system("cls");		
			printf(" \n Um momento! A senha esta incorreta, tente denovo"); //Se a senha que for inserida estiver errada o programa vai reiniciar 
			printf("\n");
			sleep(1);
			printf(" \n Reinicializando");	
			sleep(1);
			printf(" \n...");
			printf(" \n 3");	
			sleep(1);
			printf(" \n 2");	
			sleep(1);
			printf(" \n 1");
			system("cls");
			return main();
		}	
}
