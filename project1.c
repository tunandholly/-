#include <stdio.h>
#include <string.h>

struct Record{

    int id;
    char name[40];
    int age;

};

struct Record records[100];
int recordCount = 0;

void createRecord(){
    
    printf("~create the record~\n");
    records[recordCount].id = recordCount + 1;
    printf("please enter name:\n");
    scanf("%s", records[recordCount].name);
    printf("please enter your age:\n");
    scanf("%d", records[recordCount].age);
    recordCount++;
    printf("already created the record!\n");

}

void readRecord(){
    
    int id_read;
    printf("~read the record~\n");
    printf("please enter the id you want to read:\n");
    scanf("%d", &id_read);
    if(id_read > 0 && id_read <= recordCount){
        printf("id : %d name : %s age : %d \n", records[id_read-1].id, records[id_read-1].name, records[id_read-1].age);
    }else{
        printf("invalid id!\n");
    }
}

void updateRecord(){

    printf("~update the record~\n");
    int id_update;
    
    if(id_update > 0 && id_update <= recordCount){
        
        printf("enter the record you want to update: \n");
        scanf("%d", &id_update);
        printf("please enter the new name: ");
        scanf("%s", records[id_update-1].name);
        printf("please enter the new age: ");
        scanf("%d", &records[id_update-1].age);
        printf("already update the id = %d record", id_update);
    
    }else{
        printf("invalid id!\n");
    }
}

void deleteRecord(){

    printf("~delete the record~\n");
    
    int id_delete;
    printf("please enter the id you want to delete: ");
    scanf("%d", &id_delete);

    if(id_delete > 0 && id_delete <= recordCount){
        
        for(int i = id_delete - 1; i < recordCount - 1; i++){
            records[i] = records[i+1];
        }
        
        recordCount--;
        printf("already delete the id = %d record", id_delete);
    
    }else{
        printf("invalid id!\n");
    }

}

int main(){

    int choice;
    do{
        printf("\n1. create\n2. read\n3. update\n4. delete\n5. exit\n");
        printf("please enter the number (1~5) to perform: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: createRecord(); break;

        case 2: readRecord(); break;

        case 3: updateRecord(); break;

        case 4: deleteRecord(); break;

        case 5: printf("exit the program\n"); break;
            
        
        default: printf("invalid option\n");
        }
    }while(choice != 5);

    return 0;
}
