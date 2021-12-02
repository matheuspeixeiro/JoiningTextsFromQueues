#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 50

typedef struct tempRecord{
    int letter;
    struct tempRecord* next;
} RECORD;

typedef struct {
    RECORD* begin;
    RECORD* end;
} QUEUE;

QUEUE* CreateQueue(){
    QUEUE* queue = (QUEUE*) malloc(sizeof(QUEUE));
    queue->begin = NULL;
    queue->end = NULL;
    return queue;
}

bool isEmpty(QUEUE* queue){
    return (queue->begin == NULL);
}

bool Peek(QUEUE* queue, RECORD* value){
    if(isEmpty(queue)) return false;

    *value = *(queue->begin);
    return true;
}

bool Enqueue(QUEUE* queue, char letter){
    RECORD* newRecord = (RECORD*) malloc(sizeof(RECORD));
	newRecord->letter = letter;
    newRecord->next = NULL;

    if(isEmpty(queue)) queue->begin = newRecord;
    else queue->end->next = newRecord;

    queue->end = newRecord;

    return true;
}

bool Dequeue(QUEUE* queue, RECORD* value){
    if(isEmpty(queue)) return false;

    RECORD* oldRecord = queue->begin;
    *value = *(oldRecord);
    queue->begin = oldRecord->next;

    if(isEmpty(queue)) queue->end = NULL;

    free(oldRecord);
    return true;
}

bool PrintQueue(){
	
}

int main(){
	// definindo o idioma como português
	setlocale(LC_ALL, "Portuguese");
	
	printf("Seja bem-vindo ao programa que junta dois textos em um!\n\n");
	system("pause");
	system("cls");
	
	QUEUE* name = CreateQueue();
	QUEUE* surname = CreateQueue();
	
	char nameString[11];
	char surnameString[21];
	printf("\nInforme o nome: ");
	fflush(stdin);
	gets(nameString);
	printf("\nInforme o sobrenome: ");
	fflush(stdin);
	gets(surnameString);
	
	// Fazendo push para inserir o nome na stack "name"
	for (int i=0 ; i<strlen(nameString) ; i++)
		Enqueue(name, nameString[i]);	
	
	// Fazendo push para inserir o nome na stack "name"
	for (int i=0 ; i<strlen(surnameString) ; i++)
		Enqueue(name, surnameString[i]);	
	
	
	
    /*RECORD recWriter, recReader;

    QUEUE* queue = CreateQueue();

    recWriter.key = 3;
    if(Enqueue(queue, recWriter)){
        printf("Record 3 enqueued\n");
    }
    else{
        printf("Queue full!\n");
    }

    recWriter.key = 5;
    if(Enqueue(queue, recWriter)){
        printf("Record 5 enqueued\n");
    }
    else{
        printf("Queue full!\n");
    }

    recWriter.key = 10;
    if(Enqueue(queue, recWriter)){
        printf("Record 10 enqueued\n");
    }
    else{
        printf("Queue full!\n");
    }

    if(Peek(queue, &recReader))
    {
        printf("Peek begin: %d\n", recReader.key);
    }

    if(Dequeue(queue, &recReader))
    {
        printf("Value dequeued: %d\n", recReader.key);
    }

    if(Peek(queue, &recReader))
    {
        printf("Peek begin: %d\n", recReader.key);
    }

    if(Dequeue(queue, &recReader))
    {
        printf("Value dequeued: %d\n", recReader.key);
    }

    if(Peek(queue, &recReader))
    {
        printf("Peek begin: %d\n", recReader.key);
    }

    if(Dequeue(queue, &recReader))
    {
        printf("Value dequeued: %d\n", recReader.key);
    }

    if(Dequeue(queue, &recReader))
    {
        printf("Value popped: %d\n", recReader.key);
    }
    else
    {
        printf("Error!\n");
    }*/


    return 0;
}
