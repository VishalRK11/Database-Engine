#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "API.h"

void insertRow(Tables *table){

	char choice, index = 0;

	char **columnNames = (char **)malloc(sizeof(char*)* MIN_SIZE);
	char **values = (char **)malloc(sizeof(char*)* MIN_SIZE);

	do{
		columnNames[index] = (char *)malloc(sizeof(char)* STRING_SIZE);
		values[index] = (char *)malloc(sizeof(char)* STRING_SIZE);


		printf("\nEnter column name: ");
		fflush(stdin);
		gets(columnNames[index]);

		printf("\nEnter value: ");
		fflush(stdin);
		gets(values[index]);

		index++;

		printf("\nDo you want to insert another column? [Y/N]");
		scanf("%c", &choice);

	} while (choice == 'y' || choice == 'Y');

	putData(table, columnNames, values, index, -1);
}

void getRow(Tables *table){
	int id;

	printf("\nEnter the id: ");
	scanf("%d", &id);

	getData(table, id);
}

void putRow(Tables *table){

	int id;
	printf("\nEnter id: ");
	scanf("%d", &id);

	char choice, index = 0;

	char **columnNames = (char **)malloc(sizeof(char*)* MIN_SIZE);
	char **values = (char **)malloc(sizeof(char*)* MIN_SIZE);

	do{
		columnNames[index] = (char *)malloc(sizeof(char)* STRING_SIZE);
		values[index] = (char *)malloc(sizeof(char)* STRING_SIZE);


		printf("\nEnter column name: ");
		fflush(stdin);
		gets(columnNames[index]);

		printf("\nEnter value: ");
		fflush(stdin);
		gets(values[index]);

		index++;

		printf("\nDo you want to insert another column? [Y/N]");
		scanf("%c", &choice);

	} while (choice == 'y' || choice == 'Y');

	putData(table, columnNames, values, index, id);
}

void deleteRow(Tables *table){
	int id;

	printf("\nEnter id: ");
	scanf("%d", &id);

	deleteData(table, id);
}

void rowOperations(Tables *table){
	int choice;

	while (1){
		printf("\n1. Insert Row");
		printf("\n2. Get Row Data");
		printf("\n3. Put Row Data");
		printf("\n4. Delete Row Data");
		printf("\n5. Back");
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice){
		case 1: insertRow(table);
			break;
		case 2: getRow(table);
			break;
		case 3: putRow(table);
			break;
		case 4: deleteRow(table);
			break;
		case 5: return;
		default: printf("\nInvalid Option");
		}
	}
}

void createATable(){
	char *tableName = (char *)malloc(sizeof(char)* STRING_SIZE);

	printf("\nEnter table name: ");
	fflush(stdin);
	gets(tableName);

	createTable(tableName);
}

void insertIntoTable(){
	char *tableName = (char *)malloc(sizeof(char)* STRING_SIZE);

	printf("\nEnter table name: ");
	fflush(stdin);
	gets(tableName);

	Tables *table = findTable(tableName);

	rowOperations(table);
}

void dropATable(){
	char *tableName = (char *)malloc(sizeof(char)* STRING_SIZE);

	printf("\nEnter table name: ");
	fflush(stdin);
	gets(tableName);

	dropTable(tableName);
}

void fillData(){
	int choice;

	while (1){

		printf("\n1. Create Table");
		printf("\n2. Insert Into Table");
		printf("\n3. Drop Table");
		printf("\n4. Back");

		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice){
		case 1: createATable();
			break;
		case 2: insertIntoTable();
			break;
		case 3: dropATable();
			break;
		case 4: return;
		default: printf("\n\nInvalid Option entered!\n\n");
		}
	}
}

void logout(){
	//accessData();
}

void accessData(){
	int choice;

	char *userName = (char *)malloc(sizeof(char)* STRING_SIZE);

	printf("\nEnter your ID to login: ");
	scanf("%s", userName);

	Tables *table = findTable("Following");
	Rows *tempRow = table->row;

	while (tempRow != NULL){
		Columns *tempCol = tempRow->columns;
		while (tempCol != NULL){
			Cell* tempCell = tempCol->cell;
			while (tempCell != NULL){
				

				tempCell = tempCell->next;
			}
			tempCol = tempCol->next;
		}
		tempRow = tempRow->next;
	}

}

int main(){

	int choice;

	while (1){
		printf("\n1. Fill Data");
		printf("\n2. Access Data");

		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice){
		case 1: fillData();
			break;
//		case 2: accessData();
	//		break;
		default: printf("\nInvalid Option entered!");
		}
	}
	
	system("pause");
	return 0;
}