/* Trabalho de fila
    Nome: Matheus Simões Peixeiro
    Curso: Engenharia da Computação
    Etapa: 2ª
*/

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

bool PrintQueue(QUEUE* queue){
    system("cls");
    printf("\nImprimindo:\n\n");
    if (isEmpty(queue)) return false;

    RECORD* aux = queue->begin;
    while (aux->next != NULL){
        printf("%c", aux->letter);
        aux = aux->next;
    }
    printf("\n\n");
    system("pause");
    system("cls");
    return true;
}

QUEUE* JoinQueue(QUEUE* name, QUEUE* surname){
    QUEUE* finalQueue = CreateQueue();

    RECORD* aux = name->begin;
    while (aux != NULL){
        Enqueue(finalQueue, aux->letter);
        aux = aux->next;
    }

    Enqueue(finalQueue, ' ');

    aux = surname->begin;
    while (aux != NULL){
        Enqueue(finalQueue, aux->letter);
        aux = aux->next;
    }
    return finalQueue;
}

int main(){
	// definindo o idioma como português
	setlocale(LC_ALL, "Portuguese");

	printf("Seja bem-vindo ao concatenador de duas strings por meio de fila!\n\n");
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
	printf("\n");
	system("pause");

	// Fazendo push para inserir o nome na stack "name"
	for (int i=0 ; i<=strlen(nameString) ; i++)
		Enqueue(name, nameString[i]);

	// Fazendo push para inserir o nome na stack "name"
	for (int i=0 ; i<=strlen(surnameString) ; i++)
		Enqueue(surname, surnameString[i]);

    // Chamando função de que juntar nome e sobrenome
    QUEUE* newQueue = JoinQueue(name, surname);

    // Imprimindo a nova Queue
    if(PrintQueue(newQueue));

    return 0;
}
