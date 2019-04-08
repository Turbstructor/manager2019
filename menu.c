#include "menu.h"

int ask_menu(int is_login){
    
#ifdef DEBUG
    fprintf(stdout, "DEBUG MODE: ask_menu from menu.c has been called\n");
#endif

    char cmd[64];

    if(is_login) fprintf(stdout, "# ");
    else fprintf(stdout, "> ");

    fgets(cmd, 64, stdin);
    cmd[strlen(cmd) - 1] = '\0';

    if(!strcmp(cmd, "join") && !is_login) return 1;
    else if(!strcmp(cmd, "login") && !is_login) return 2;
    else if(!strcmp(cmd, "logout") && is_login) return 3;
    else if(!strcmp(cmd, "list") && !is_login) return 4;
    else if(!strcmp(cmd, "exit") && !is_login) return 5;
    else
    {
	if(!is_login) fprintf(stderr, "Error: unknown command \"%s\"\n", cmd);
	else fprintf(stdout, "%s\n", cmd);
	return -1;
    }
}
