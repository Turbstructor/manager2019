#include "user.h"

int load_file(LOGIN* list[], char* filename){

#ifdef DEBUG
    fprintf(stdout, "DEBUG MODE: load_file from user.c has been called\n");
#endif

    int count = 0;
    FILE *datafile = fopen(filename, "r");
    char ans;
    if(datafile == NULL)
    {
	fprintf(stderr, "Error: File %s does not exist, do you wish to create new one? (Y/n) : ", filename);
	fscanf(stdin, " %c", &ans);
	getchar();

	if(ans == 'Y' || ans == 'y')
	{
	    datafile = fopen(filename, "w");
	    fclose(datafile);
	    datafile = fopen(filename, "r");
	}
	else
	{
	    fprintf(stderr, "Error: user chose not to create new file, aborting program.\n");
	    return -1;
	}
    }

    while(!feof(datafile)){
	list[count] = (LOGIN*)malloc(sizeof(LOGIN));
	fscanf(datafile, "%s %s", list[count] -> id, list[count] -> password);
	
	if(strcmp(list[count] -> id, "")) count++;
    }

    fprintf(stdout, "%d records read from %s\n", count, filename);
    fclose(datafile);

    return count;
}


void join(LOGIN* list[], int *count){

#ifdef DEBUG
    fprintf(stdout, "DEBUG MODE: join from user.c has been called\n");
#endif

    char id[20], pass[20];

    while(1){
	fprintf(stdout, "Enter new user id: ");
	scanf("%s", id);

	int dup = 0;
	for(int i = 0; i < *count; i++){
	    if(strcmp(id, list[i] -> id) == 0) {
	       dup = 1; break;
	    }
	}
	if(dup == 1){
	    fprintf(stderr, "Error: That id already exists\n");
	}
	else{
	    fprintf(stdout, "Enter password: ");
	    scanf("%s", pass);
	    list[*count] = (LOGIN*)malloc(sizeof(LOGIN));
	    strcpy(list[*count] -> id, id);
	    strcpy(list[*count] -> password, pass);
	    *count += 1;
	    
	    fprintf(stdout, "New user added!\n");
	    break;
	}
    }
    getchar();
}

int login(LOGIN* list[], int count){

#ifdef DEBUG
    fprintf(stdout, "DEBUG MODE: login from user.c has been called\n");
#endif

    char id[20], pass[20];
    fprintf(stdout, "Enter user id: ");
    fscanf(stdin, "%s", id);
    
    int dup = 0, found;
    for(int i = 0; i < count; i++){
	if(strcmp(id, list[i] -> id) == 0) {
	    dup = 1;
	    found = i;
	    break;
	}
    }

    if(dup != 1){
	fprintf(stderr, "Error: No such user\n");

	getchar();
	return 0;
    }
    else{
	fprintf(stdout, "Enter password: ");
	fscanf(stdin, "%s", pass);
	getchar();
	if(strcmp(list[found] -> password, pass) == 0){
	    fprintf(stdout, "Welcome %s!\n", id);
	    return 1;
	}
	else{
	    fprintf(stderr, "Error: Password incorrect\n");
	    return 0;
	}
    }
}

void logout(int* is_login){

#ifdef DEBUG
    fprintf(stdout, "DEBUG MODE: logout from user.c has dbeen called\n");
#endif

    *is_login = 0;
    fprintf(stdout, "Logout\n");
}

void list(LOGIN* list[], int count)
{

#ifdef DEBUG
    fprintf(stdout, "DEBUG MODE: list from user.c has been called\n");
#endif

    fprintf(stdout, "%d accounts currently available\n", count);
    fprintf(stdout, "User names and password are:\n");

    for(int i = 0; i < count; i++) fprintf(stdout, "[%d] %s / %s\n", (i + 1), list[i] -> id, list[i] -> password);
}

void save_file(LOGIN* list[], int count, char* filename){

#ifdef DEBUG
    fprintf(stdout, "DEBUG MODE: save_file from user.c has been called\n");
#endif

    FILE *datafile = fopen(filename, "w");
    for(int i = 0; i < count; i++){
	fprintf(datafile, "%s %s\n", list[i] -> id, list[i] -> password);
    }
    fprintf(stdout, "%s Saved!\n", filename);
    fclose(datafile);
}
