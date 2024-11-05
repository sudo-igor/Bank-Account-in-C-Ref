// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

// Declaring all the functions
void checkBalance(char*);
void transferMoney(void);
void display(char*);
void person(char*);
void login(void);
void loginsu(void);
void createAccount(void);
void accountCreated(void);
//void afterlogin(void);
void logout(void);
void clearScreen();
void mainMenu();
// Testa se tudo é número na data
int isNumeric(const char *str);
void getPassword(char *password, int maxLength);

// Declaring cursorPosition
// function for setting
// cursor position
void cursorPosition (int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Creating a structure to store
// data of the user
struct user {
	char username[50];
	char date[3];
	char month[3];
	char year[5];
	char phoneNumber[15];
	char adharNumber[20];
	char firstName[20];
	char lastName[20];
	char fatherName[20];
	char motherName[20];
	char address[50];
	char typeAccount[20];
};

// Structure to keep track
// of amount transfer
struct money {
	char usernameTo[50];
	char userPersonFrom[50];
	long int money1;
};

struct userpass {
	char password[50];
};

// Driver Code
int main()
{
	int choice;
	int passwordLength;

	while (1) {
        mainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: createAccount(); break;
            case 2: login(); break;
            case 3: exit(0); break;
            default: printf("Invalid option. Try again.\n");
        }
    }
}

// Function to create accounts
// of users
void createAccount(void)
{
	char password[20];
	int passwordLength, i, seek = 0;
	char ch;
	FILE *fp, *fu;
	struct user u1;
	struct userpass p1;

	struct userpass u2;
	
	clearScreen();
	// Opening file to
	// write data of a user
	fp = fopen("username.txt", "ab");
	if (fp == NULL) {
	    perror("Error opening file");
	    return;  // Saia da função se o arquivo não puder ser aberto
	}

	// Inputs
	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

	printf("\n\nFIRST NAME..");
	scanf("%20s", u1.firstName);

	printf("\n\n\nLAST NAME..");
	scanf("%20s", u1.lastName);

	printf("\n\nFATHER's NAME..");
	scanf("%20s", u1.fatherName);

	printf("\n\nMOTHER's NAME..");
	scanf("%20s", u1.motherName);

	printf("\n\nADDRESS..");
	scanf("%50s", u1.address);

	printf("\n\nACCOUNT TYPE..");
	scanf("%20s", u1.typeAccount);

	printf("\n\nDATE OF BIRTH..");
	printf("\nDATE-");
	do { 
		scanf("%2s", u1.date);
		if (!isNumeric(u1.date)) { 
	        printf("Date is invalid, please input a valid number.\n"); 
	    }
	} while (!isNumeric(u1.date));

	printf("\nMONTH: ");
	do { 
		scanf("%2s", u1.month);
		if (!isNumeric(u1.month)) { 
	        printf("Date is invalid, please input a valid number.\n"); 
	    }
	} while (!isNumeric(u1.month));
	
	printf("\nYEAR: ");
	do { 
		scanf("%4s", u1.year);
		if (!isNumeric(u1.year)) { 
	        printf("Date is invalid, please input a valid number.\n"); 
	    }
	} while (!isNumeric(u1.year));

	printf("\n\nADHAR NUMBER..");
	do { 
		scanf("%20s", u1.adharNumber);
		if (!isNumeric(u1.adharNumber)) { 
	        printf("Adhar number is invalid, please input a valid number.\n"); 
	    }
	} while (!isNumeric(u1.adharNumber));

	printf("\n\nPHONE NUMBER..");
	do { 
		scanf("%15s", u1.phoneNumber);
		if (!isNumeric(u1.phoneNumber)) { 
	        printf("Phone number is invalid, please input a valid number.\n"); 
	    }
	} while (!isNumeric(u1.phoneNumber));

	printf("\n\nUSERNAME.. ");
	scanf("%50s", u1.username);

	printf("\n\nPASSWORD (max 50 characters): ");
	getPassword(password, 50);
	
	// Writing to the file
	fwrite(&u1, sizeof(u1),
		1, fp);

	// Closing file
	fclose(fp);

	// Calling another function
	// after successful creation
	// of account
	accountCreated();
}

// Successful account creation
void accountCreated(void)
{
	int i;
	char ch;
	clearScreen();
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	cursorPosition(30, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY....");
	cursorPosition(0, 20);

	printf("Press enter to login");

	getch();
	login();
}

// Login function to check
// the username of the user
void login(void)
{
	clearScreen();

	char username[50];
	char password[50];

	int i;
	int loginSuccessful = 0;
	char ch;
	FILE *fp, *fu;
	struct user u1;
	struct userpass u2;

	// Opening file of
	// user data
	fp = fopen("username.txt", "rb");
	if (fp == NULL) {
	    perror("Error opening file");
	    return;  // Saia da função se o arquivo não puder ser aberto
	}

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	cursorPosition(34, 2);
	printf(" ACCOUNT LOGIN ");
	cursorPosition(7, 5);
	printf("***********************************************"
		"********************************");

	cursorPosition(35, 10);
	printf("==== LOG IN ====");

	// Take input
	cursorPosition(35, 12);
	printf("USERNAME.. ");
	scanf("%s", &username);

	cursorPosition(35, 14);
	printf("PASSWORD..");

	// Input the password
	getPassword(password, 50);

	// Checking if username
	// exists in the file or not
	while (fread(&u1, sizeof(u1), 1, fp)) {
		if (strcmp(username, u1.username) == 0) {
			loginSuccessful = 1;
			loginsu();
			display(username);
		}
	}

	// Closing the file
	fclose(fp);
	if (!loginSuccessful) {
    	printf("\nUsername or password is incorrect.\n");
	}
}

// Redirect after
// successful login
void loginsu(void)
{
	int i;
	FILE* fp;
	struct user u1;
	clearScreen();
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	cursorPosition(30, 10);
	printf("LOGIN SUCCESSFUL....");
	cursorPosition(0, 20);
	printf("Press enter to continue");

	getch();
}

// Display function to show the
// data of the user on screen
void display(char username1[])
{
	clearScreen();
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	if (fp == NULL) {
	    perror("Error opening file");
	    return;  // Saia da função se o arquivo não puder ser aberto
	}
	
	struct user u1;

	if (fp == NULL) {
		printf("error in opening file");
	}

	while (fread(&u1, sizeof(u1), 1, fp)) {
		if (strcmp(username1, u1.username) == 0) {
			cursorPosition(30, 1);
			printf("WELCOME, %s %s",
				u1.firstName, u1.lastName);
			cursorPosition(28, 2);
			printf("..........................");
			cursorPosition(55, 6);
			printf("==== YOUR ACCOUNT INFO ====");
			cursorPosition(55, 8);
			printf("***************************");
			cursorPosition(55, 10);
			printf("NAME..%s %s", u1.firstName, u1.lastName);

			cursorPosition(55, 12);
			printf("FATHER's NAME..%s", u1.fatherName);

			cursorPosition(55, 14);
			printf("MOTHER's NAME..%s", u1.motherName);

			cursorPosition(55, 16);
			printf("ADHAR CARD NUMBER..%s", u1.adharNumber);

			cursorPosition(55, 18);
			printf("MOBILE NUMBER..%s", u1.phoneNumber);

			cursorPosition(55, 20);
			printf("DATE OF BIRTH.. %s - %s - %s", u1.date, u1.month, u1.year);

			cursorPosition(55, 22);
			printf("ADDRESS..%s", u1.address);

			cursorPosition(55, 24);
			printf("ACCOUNT TYPE..%s", u1.typeAccount);
		}
	}

	fclose(fp);

	cursorPosition(0, 6);

	// Menu to perform different
	// actions by user
	printf(" HOME ");
	cursorPosition(0, 7);
	printf("******");
	cursorPosition(0, 9);
	printf(" 1....CHECK BALANCE");
	cursorPosition(0, 11);
	printf(" 2....TRANSFER MONEY");
	cursorPosition(0, 13);
	printf(" 3....LOG OUT\n\n");
	cursorPosition(0, 15);
	printf(" 4....EXIT\n\n");

	printf(" ENTER YOUR CHOICE..");
	scanf("%d", &choice);

	switch (choice) {
		case 1:
			checkBalance(username1);
			break;
	
		case 2:
			transferMoney();
			break;
	
		case 3:
			logout();
			login();
			break;
	
		case 4:
			exit(0);
			break;
		}
}

// Function to transfer
// money from one user to
// another
void transferMoney(void)
{
	int i, j;
	FILE *fm, *fp;
	struct user u1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	clearScreen();

	// Opening file in read mode to
	// read user's username
	fp = fopen("username.txt", "rb");
	if (fp == NULL) {
	    perror("Error opening file");
	    return;  // Saia da função se o arquivo não puder ser aberto
	}

	// Creating a another file
	// to write amount along with
	// username to which amount
	// is going to be transferred
	fp = fopen("money.txt", "ab");
	if (fp == NULL) {
	    perror("Error opening file");
	    return;  // Saia da função se o arquivo não puder ser aberto
	}

	cursorPosition(33, 4);
	printf("---- TRANSFER MONEY ----");
	cursorPosition(33, 5);
	printf("========================");

	cursorPosition(33, 11);
	printf("FROM (your username).. ");
	scanf("%s", &usernamet);

	cursorPosition(33, 13);
	printf(" TO (username of person)..");
	scanf("%s", &usernamep);

	// Checking for username if it
	// is present in file or not
	while (fread(&u1, sizeof(u1),
				1, fp))

	{
		if (strcmp(usernamep,
				u1.username)
			== 0) {
			strcpy(m1.usernameTo,
				u1.username);
			strcpy(m1.userPersonFrom,
				usernamet);
		}
	}
	cursorPosition(33, 16);

	// Taking amount input
	printf("ENTER THE AMOUNT TO BE TRANSFERRED..");
	scanf("%d", &m1.money1);

	// Writing to the file
	fwrite(&m1, sizeof(m1),
		1, fm);

	cursorPosition(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	cursorPosition(0, 28);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	cursorPosition(0, 29);
	printf("transferring amount, Please wait..");

	cursorPosition(10, 27);
	for (i = 0; i < 70; i++) {
		for (j = 0; j < 1200000; j++) {
			j++;
			j--;
		}
		printf("*");
	}

	cursorPosition(33, 40);
	printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
	getch();

	// Close the files
	fclose(fp);
	fclose(fm);

	// Function to return
	// to the home screen
	display(usernamet);
}

// Function to check balance
// in users account
void checkBalance(char username2[])
{
	FILE* fm;
	struct money m1;
	char ch;
	int i = 1, summoney = 0;
	
	clearScreen();
	// Opening amount file record
	fm = fopen("money.txt", "rb");

	int k = 5, l = 10;
	int m = 30, n = 10;
	int u = 60, v = 10;

	cursorPosition(30, 2);
	printf("==== BALANCE DASHBOARD ====");
	cursorPosition(30, 3);
	printf("***************************");
	cursorPosition(k, l);
	printf("S no.");
	cursorPosition(m, n);
	printf("TRANSACTION ID");
	cursorPosition(u, v);
	printf("AMOUNT");

	// Reading username to
	// fetch the correct record
	while (fread(&m1, sizeof(m1),
				1, fm)) {
		if (strcmp(username2,
				m1.usernameTo)
			== 0) {
			cursorPosition(k, ++l);
			printf("%d", i);
			i++;
			cursorPosition(m, ++n);
			printf("%s", m1.userPersonFrom);

			cursorPosition(u, ++v);
			printf("%d", m1.money1);
			// Adding and
			// finding total money
			summoney = summoney + m1.money1;
		}
	}

	cursorPosition(80, 10);
	printf("TOTAL AMOUNT");

	cursorPosition(80, 12);
	printf("%d", summoney);

	getch();

	// Closing file after
	// reading it
	fclose(fm);
	display(username2);
}

// Logout function to bring
// user to the login screen
void logout(void)
{
	int i, j;
	clearScreen();
	printf("Please wait, logging out");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	cursorPosition(30, 10);
	printf("Sign out successfully..\n");

	cursorPosition(0, 20);
	printf("Press any key to continue..");

	getch();
}

int isNumeric(const char *str) { 
    while (*str) { 
        if (!isdigit(*str)) { 
            return 0; // Not a number 
        } 
        str++; 
    } 
    return 1; // All characters are digits 
} 

void clearScreen() {
	#ifdef _WIN32
	    system("cls");  // Windows
	#else
	    system("clear");  // Unix/Linux/Mac
	#endif
}

void mainMenu() {
    clearScreen();
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
    printf("1.... CREATE A BANK ACCOUNT\n");
    printf("2.... ALREADY A USER? SIGN IN\n");
    printf("3.... EXIT\n\n");
    printf("ENTER YOUR CHOICE: ");
}

void getPassword(char *password, int maxLength) {
	int i = 0;
    char ch;
    while (i < maxLength - 1) {  // Reserve espaço para '\0'
        ch = getch();
        if (ch == '\r') {  // Enter key
            break;
        }
        if (ch == '\b' && i > 0) {  // Backspace key
            printf("\b \b");
            i--;
            continue;
        }
        password[i++] = ch;
        printf("*");
    }
    password[i] = '\0';
}

