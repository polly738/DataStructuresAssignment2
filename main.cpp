#include <stdio.h>
#include <stdlib.h>

typedef struct Date{


}Date;

typedef struct Car{

    int avabileForRent;
    int mileage;
    int isInRepair;
}Car;

typedef struct CarNode{

    Car * data;
    CarNode * next;
}CarNode;

void printSingleNode(const CarNode *head){

  if(head !=NULL){
  printf("mileage: %d\n",head->data->mileage);
  }
}

void printList(const CarNode *head){
  
  while(head != NULL){

    printSingleNode(head);
    head = head->next;
  }

}



void push(CarNode* head, Car * input){

  if(head -> data ==NULL){

    head ->data = input;
    return;
  }

  while(head->next !=NULL){
    head = head-> next;
  }

  CarNode * add = (CarNode*)malloc(sizeof(CarNode));
  head -> next = add;
  head -> next-> data =input;
  head -> next ->next = NULL;
}

void freeBoth(CarNode *head){

  free(head->data);
  free(head);
  
}


void freeAllCarNodes(CarNode * head){

  CarNode*temp = (CarNode*)malloc(sizeof(CarNode));
  
  
  while(head ->next !=NULL){

    temp = head;
    head = head->next;
    freeBoth(temp);
    
  }

  freeBoth(head);
  
}

int main(void){
  
  CarNode * headtest = (CarNode*)malloc(sizeof(CarNode));


Car * data1 = (Car*)malloc(sizeof(Car));
Car * data2 = (Car*)malloc(sizeof(Car));
Car * data3 = (Car*)malloc(sizeof(Car));
  
  data1->mileage = 8;
  data2->mileage = 7;
  data3->mileage =5;



  push(headtest,data1);
  push(headtest,data2);
  push(headtest,data3);


printList(headtest);  

  freeAllCarNodes(headtest);
 

  return 0;
  }