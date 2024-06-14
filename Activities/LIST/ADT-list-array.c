#include<stdio.h>

typedef struct{
	char fName[20];
	char lName[20];
}studName;

typedef struct{
	int month;
	int year;
}bday;

typedef struct{
	studName name;
	bday birthdate;
	int age;
	int idNum;
}studentInfo;

typedef struct{
	studentInfo studList[20];
	int studCount;
}classRecord;

void display(classRecord LIST);
studentInfo getData();
void insertFirst(classRecord *LIST);
void insertRear(classRecord *LIST);
void insertAt(classRecord *LIST);
void insertSorted(classRecord *LIST);
void deleteFront(classRecord *LIST);
void deleteRear(classRecord *LIST);
void deleteAt(classRecord *LIST);

void main(){
	classRecord LIST;
	
	insertFirst(&LIST);
	display(LIST);
	
	insertRear(&LIST);
	display(LIST);
	
	insertAt(&LIST);
	display(LIST);
	
	insertAt(&LIST);
	display(LIST);
	
	insertSorted(&LIST);
	display(LIST);
	
	deleteFront(&LIST);
	display(LIST);
	
	deleteRear(&LIST);
	display(LIST);
	
	deleteAt(&LIST);
	display(LIST);
	
}

studentInfo getData(){
	
	studentInfo data;
	
	printf("\n\tFirst Name: ");
	scanf(" %s", data.name.fName);
	printf("\tLast Name: ");
	scanf(" %s", data.name.lName);

	printf("\tBirth Month: ");
	scanf("%d", &data.birthdate.month);
	printf("\tBirth Year: ");
	scanf("%d", &data.birthdate.year);
	
	printf("\tAge: ");
	scanf(" %d", &data.age);
	printf("\tID: ");
	scanf(" %d", &data.idNum);
		
	return data;
}

void display(classRecord LIST){
	printf("\n\n\t--------CURRENT LIST-----------");
	printf("\n\n\tStudent Count: %d", LIST.studCount);
	
	int ndx;
	for(ndx = 0; ndx < LIST.studCount; ndx++){
		
		printf("\n\n\tID: %d", LIST.studList[ndx].idNum);
		printf("\tName: %s %s", LIST.studList[ndx].name.fName, LIST.studList[ndx].name.lName);
		
		printf("\n\tBirthdate: %d/%d", LIST.studList[ndx].birthdate.month , LIST.studList[ndx].birthdate.year);
		
		printf("\tAge: %d", LIST.studList[ndx].age);
		
	}
}

void insertFirst(classRecord *LIST){
	if(LIST->studCount < 20){
		
		printf("\n\n\t------INSERTING FIRST------");
		
		studentInfo data = getData();
		
		int ndx;
		for(ndx = LIST->studCount-1; ndx >= 0; ndx--){
			LIST->studList[ndx] = LIST->studList[ndx-1];
		}
		
		LIST->studList[0] = data;
		LIST->	studCount++;
	}
}

void insertRear(classRecord *LIST){
	if(LIST->studCount < 20){
		printf("\n\n\t------INSERTING REAR------");
		
		studentInfo data = getData();
		LIST->studList[LIST->studCount] = data;
		LIST->studCount++;
	}
}

void insertAt(classRecord *LIST){
	if(LIST->studCount < 20){
		printf("\n\n\t------INSERTING AT INDEX------");
		
		int insertNdx;
		printf("\n\n\tIndex: ");
		scanf(" %d", &insertNdx);
		
		studentInfo data = getData();
		
		int ndx;
		for(ndx = LIST->studCount; ndx > insertNdx; ndx--){
			LIST->studList[ndx] = LIST->studList[ndx-1];
		}
		
		LIST->studList[insertNdx] = data;
		LIST->studCount++;
	}
}

void insertSorted(classRecord *LIST){
	if(LIST->studCount < 20){
		printf("\n\n\t------INSERT IN PRESORTED LIST------");
		
		studentInfo data = getData();
		
		int ndx = 0;
		while(data.age > LIST->studList[ndx].age){
			ndx++;
		}
		
		int i;
		for(i = LIST->studCount; i > ndx; i--){
			LIST->studList[i] = LIST->studList[i-1];
		}
		
		LIST->studList[ndx] = data;
		LIST->studCount++;
		
	}
}

void deleteFront(classRecord *LIST){
	if(LIST->studCount > 0){
		
		printf("\n\n\t------DELETING FRONT------\n\n");
		
		int ndx;
		for(ndx = 0; ndx < LIST->studCount-1; ndx++){
			LIST->studList[ndx] = LIST->studList[ndx+1];
		}
		
		LIST->studCount--;
	}
}

void deleteRear(classRecord *LIST){
	if(LIST->studCount > 0){
		printf("\n\n\t------DELETING REAR------\n\n");
		
		LIST->studCount--;

	}
}

void deleteAt(classRecord *LIST){
	if(LIST->studCount > 0){
		
		printf("\n\n\t------DELETING AT INDEX------");
		
		int deleteNdx;
		printf("\n\n\tIndex: ");
		scanf(" %d", &deleteNdx);
			
		int ndx;
		for(ndx = deleteNdx; ndx < LIST->studCount-1 ; ndx++){
			LIST->studList[ndx] = LIST->studList[ndx+1];
		}
		
		LIST->studCount--;
	}
}


