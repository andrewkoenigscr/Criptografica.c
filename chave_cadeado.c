#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct chaveiro
{
	char nameChave[20];
	char chave[53][2];
};
typedef struct chaveiro chaveiro;

void limpeza()
{
	// limpa o buffer para evitar bugs
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
	{
	}
}

void verificar_SO(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void functionChave(char chave[53][2], char name[20])
{

	int cont, confirm;

	// escaneia um valor para segunda coluna(chave[][1]), está coluna serve para embaralhar a mensagem
	for (cont = 0; cont < 53; cont++)
	{

		bool verificador;
		do
		{
			printf("[%d] informe a chave para [%c]\n", cont, chave[cont][0]);
			scanf("%c", &chave[cont][1]);
			limpeza();

			// verifica se o caractere já foi utilizado
			for (int i = 0; i < cont; i++)
			{

				for (int x = 1; x < 2; x++)
				{

					if (chave[cont][1] != chave[i][x])
					{
						verificador = true;
					}
					else if (chave[cont][1] == chave[i][x] && chave[cont][1] != '\n')
					{
						printf("este caractere ja foi utilizado!\n");
						cont -= 1;
						verificador = false;
						i = cont;
					}
				}
			}

		} while (verificador = false);
	}

	// exibe a chave que foi criada mostrando o alfabeto e suas novas "representações"
	do
	{

		printf("\n\nNome da chave: %s\n", name);

		for (cont = 0; cont < 53; cont++)
		{
			printf("linha [%d] coluna [0] = %c  coluna [1]=%c\n", cont, chave[cont][0], chave[cont][1]);
		}

		// pede ao usuario confirmação para salvar/retornar a nova chave a o menu
		printf("\nConfirme a chave\n1-Cancelar\n2-Salvar\n");
		scanf(" %d", &confirm);
		limpeza();

		// Avalia a escolha do usuario
		if (confirm == 1)
		{
			// limpa o que foi inserido na segunda coluna da  chave
			printf("\nCancelando!\n");
			strcpy(name, "indefinido");
			for (cont = 0; cont < 53; cont++)
			{
				chave[cont][1] = '\0';
			}
		}
		else if (confirm == 2)
		{
			printf("\nSalvando\n");
		}
		else
		{
			printf("\nErro\n");
		}

		printf("Press Enter para continuar\n");
		getchar();

		verificar_SO();
	} while (confirm != 1 && confirm != 2);
}

void codificador(char cadeado[53][2])
{

	// pede ao usuario os elementos que deseja codificar
	char palavra[100];
	char codificacao[100];
	printf("Informe o que deseja codificar\n");
	fgets(palavra, 100, stdin);
	palavra[strcspn(palavra, "\n")] = '\0';
	int tam = strlen(palavra);

	// enconta onde está o caractere correspondente a cada elementos da mensagem do usuario e a remonta con sua nova representaçao na variavel codificacao
	for (int i = 0; palavra[i] != '\0'; i++)
	{
		for (int j = 0; j < 53; j++)
		{
			if (palavra[i] == cadeado[j][0])
			{
				codificacao[i] = cadeado[j][1];
				break;
			}
		}
	}

	codificacao[tam] = '\0';

	// exibe a palavra codificada
	printf("A sua palavra:\n%s\n\n\n", codificacao);
	printf("Press Enter para continuar\n");
	getchar();
}

void decodificador(char cadeado[53][2])
{

	// recebe a palavra codificada
	char palavra[100];
	char decodificacao[100];
	printf("Informe o que deseja descodificar\n");
	fgets(palavra, 100, stdin);
	palavra[strcspn(palavra, "\n")] = '\0';
	int tam = strlen(palavra);

	// enconta onde está o caractere correspondente a cada elementos da mensagem do usuario e a remonta com sua letra correspondente na variavel codificacao
	for (int i = 0; palavra[i] != '\0'; i++)
	{
		for (int j = 0; j < 53; j++)
		{
			if (palavra[i] == cadeado[j][1])
			{
				decodificacao[i] = cadeado[j][0];
				break;
			}
		}
	}

	decodificacao[tam] = '\0';

	// exibe a palavra traduzida
	printf("A sua palavra:\n%s\n\n\n", decodificacao);
	printf("Press Enter para continuar\n");
	getchar();
}

void menuCvCd()
{

	int selector, i;
	i = 0;

	chaveiro chaveiro0[2];

	// chave padrão
	strcpy(chaveiro0[0].nameChave, "chave padrao");
	const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	const char newCaracteres[] = "pmlqazwxsoijnedcuhbrfvgtkyYKTGVFRBHUCDENJIOSXWZAQLMP|";

	// inseri o alfabedo na couluna de checagem(chave[][0]) e inseri os novos caracteres na couluna de correspondentes(chave[][1])
	for (int cont = 0; cont < 53; cont++)
	{
		chaveiro0[0].chave[cont][0] = caracteres[cont];
		chaveiro0[0].chave[cont][1] = newCaracteres[cont];
	}

	// nome padrão da segunda chave(utilizado como parametro de verificação)
	strcpy(chaveiro0[1].nameChave, "indefinido");
	for (int cont = 0; cont < 53; cont++)
	{

		chaveiro0[1].chave[cont][0] = caracteres[cont];
	}

	// menu de seleção de tarefas
	do
	{
		verificar_SO();
		printf("Selecione uma opcao\n1-Codificar\n2-Traduzir\n3-Sair\n");
		scanf("%d", &selector);
		limpeza();
		verificar_SO();

		// codifiacr

		if (selector == 1)
		{

			int selector2;
			int selectChave;
			printf("Criar uma nova chave?\n1-Sim\n2-Nao\n");
			scanf("%d", &selector2);
			limpeza();
			verificar_SO();

			// uma nova chave
			if (selector2 == 1)
			{
				// Pede um novo nome para a segunda chave e chama a função para criala
				printf("\nDefina um nome para essa chave\n");
				fgets(chaveiro0[1].nameChave, 20, stdin);
				chaveiro0[1].nameChave[strcspn(chaveiro0[1].nameChave, "\n")] = '\0';
				functionChave(chaveiro0[1].chave, chaveiro0[1].nameChave);
			}
			else if (selector2 == 2)
			{
				// seleção da chave para criptografa-lá
				int option;
				option = 1;

				printf("Qual chave deseja usar para criptografar sua mensagem?\n");

				if (strcmp(chaveiro0[1].nameChave, "indefinido") == 0)
				{

					printf("%d- %s\n", option, chaveiro0[0].nameChave);
				}
				else
				{

					for (int j = 0; j < 2; j++)
					{
						printf("%d- %s\n", option, chaveiro0[j].nameChave);
						option++;
					}
				}
			}
			scanf(" %d", &selectChave);
			limpeza();

			// Avalia qual chave foi escolhida
			if (selectChave == 1)
			{
				// chamar função de codificação com o primeiro item da matriz chaveiro
				codificador(chaveiro0[0].chave);
			}
			else if (selectChave == 2 && strcmp(chaveiro0[1].nameChave, "indefinido") != 0)
			{
				// chamar função de codificação com o segundo item da matriz chaveiro
				codificador(chaveiro0[1].chave);
			}
			else
			{
				printf("Comando nao reconhecido\n");
			}
		}
		// descriptografia
		else if (selector == 2)
		{
			// selção da chave para descriptografar
			int selectChave;
			printf("Qual chave deseja usar para descriptografar sua mensagem?\n");
			int option;
			option = 1;
			// avalia se a segunda chave foi criada(se não esta com o nome padrão)
			if (strcmp(chaveiro0[1].nameChave, "indefinido") == 0)
			{

				printf("%d-%s\n", option, chaveiro0[0].nameChave);
			}
			else
			{

				for (int j = 0; j < 2; j++)
				{
					printf("%d-%s\n", option, chaveiro0[j].nameChave);
					option++;
				}
			}
			scanf(" %d", &selectChave);
			limpeza();
			// chama a função de decodificação passando a chave que o usuario informou
			if (selectChave == 1)
			{
				// chamar função de codificação com o primeiro item do array chaveiro
				decodificador(chaveiro0[0].chave);
			}
			else if (selectChave == 2)
			{
				// chamar função de codificação com o segundo item do array chaveiro
				decodificador(chaveiro0[1].chave);
			}
			else
			{
				printf("Comando nao reconhecido\n");
			}
		}
		else if (selector == 3)
		{
			// saida
			printf("Ate mais!");
		}
		else
		{
			printf("Comando nao reconhecido");
		}
	} while (selector != 3);
}
