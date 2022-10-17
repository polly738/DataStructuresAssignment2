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

int hasLessMileage(const Car*a , const Car*b ){

  if(a ->mileage < b -> mileage){

    return 1;
  }
  else{

    return 0;
  }
}



int push(CarNode* head, Car * input,int(*compar)(const Car*,const Car*)){

  if(head -> data ==NULL&& head->next ==NULL){



    head ->data = input;
    return -1;
  }


  while(head->next !=NULL){

    if(compar(input,head->next->data )){

      CarNode * temp = (CarNode*)malloc(sizeof(CarNode));
      temp->data = input;
      temp->next = head->next;
      head->next = temp;
      


      return -1;
    }

    
    head = head-> next;
  }

  CarNode * add = (CarNode*)malloc(sizeof(CarNode));
  head -> next = add;
  head -> next-> data =input;
  head -> next ->next = NULL;

  return -1;
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

  int (*mileagefunc)(const Car*,const Car*);
  mileagefunc = &hasLessMileage;
  
  CarNode * headtest = (CarNode*)malloc(sizeof(CarNode));

  headtest->data = NULL;
  headtest->next = NULL;


Car * data1 = (Car*)malloc(sizeof(Car));
Car * data2 = (Car*)malloc(sizeof(Car));
Car * data3 = (Car*)malloc(sizeof(Car));
Car * data4 = (Car*)malloc(sizeof(Car));
  
  data1->mileage = 8;
  data2->mileage = 7;
  data3->mileage =5;
  data4 ->mileage = 10;



  push(headtest,data1,mileagefunc);
  push(headtest,data2,mileagefunc);
  push(headtest,data3,mileagefunc);
  push(headtest,data4,mileagefunc);


printList(headtest);  

  freeAllCarNodes(headtest);
 

  return 0;
  }