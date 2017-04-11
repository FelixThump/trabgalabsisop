/*
 ============================================================================
 Name        : trabga.c
 Author      : Felipe
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
	int opcao;
	do {
		printf("<<<< Applications Menu >>>\n");
		printf("    1) Web Browser\n");
		printf("    2) Text Editor\n");
		printf("    3) Terminal\n");
		printf("    4) Finalizar processo\n");
		printf("    5) Quit\n");
		printf("Opção: \n");
		scanf("%d", &opcao);

		switch (opcao) {
		case 1:
			printf("Digite o site que gostaria de visitar: \n");
			char* s;
			scanf("%s", s);
			execl("/usr/bin/firefox", "firefox", s, NULL);
			pid_t firefox = getpid(); // não tá funcionando
			printf("%d", firefox);
			break;

		case 2:
			execl("/usr/bin/gedit", "gedit", NULL);
			pid_t gedit = getpid(); // não tá funcionando
			printf("%d", gedit);
			break;

		case 3:
			system("gnome-terminal");
			pid_t terminal = getpid(); // não tá funcionando
			printf("%d", terminal);
			printf("pid do terminal = %d", terminal);
			break;

		case 4:
			printf("Qual processo deseja terminar?\n");
			printf("1) Web Browser\n");
			printf("2) Text Editor\n");
			printf("3) Terminal");

			int proc;
			scanf("%d", &proc);

			if (proc == 1)
				kill(firefox + 1, SIGTERM);
			if (proc == 2)
				kill(gedit, SIGTERM);
			if (proc == 3)
				kill(terminal, SIGTERM);
			break;

		default:
			if (opcao != 5)
				printf("Essa opção não existe!\n");
			break;
		}
	} while (opcao != 5);
}