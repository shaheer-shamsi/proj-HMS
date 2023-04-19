#include<stdio.h>
#include<windows.h>

int n,i,j=0,a=0,sum=0,patIndex,docIndex,flag,num;

struct doctor{
    char name[30];
    char specialty[30];
    char gender[6];
    char post[30];
    int phone;
    int age;
};

struct doctor doc[100];

struct patient{
    char name[30];
    char disease[30];
    char gender[6];
    int room;
    int phone;
    int age;
};

struct patient pat[100];


int anyKey(){
printf("\n\n\t\t\t\t\t\tPress Any Key to Continue\n");
getch();
system("cls");
}


char animatedText(char* txt){
    int i,j;
    char str[256];
    strcpy(str,txt);
    for(j=0;j<34;j++){
        Sleep(12);
        printf("*");
    }

    for(j=0;j<strlen(str);j++){
        Sleep(10);
        printf("%c",str[j]);
    }

    for(j=0;j<34;j++){
        Sleep(12);
        printf("*");
    }
    printf("\n");
}

void loading(){
    system("color 00");
    char unfill = 177, filled = 219;

    int i,j;
    char d[]="\n\n\t\t\t\t\t\tLoading...\n\n\t\t\t\t\t";
    for(j=0;j<strlen(d);j++){
        Sleep(20);
        printf("%c",d[j]);
    }

    for (int i = 0; i < 26; i++){
    printf("%c", unfill);
    }
    printf("\r");
    printf("\t\t\t\t\t");

    for (int i = 0; i < 26; i++){
        printf("%c", filled);
        Sleep(50);
    }
    system("cls");
}



//
void docAdd(){
    printf("\n\n");
    printf("Number of existing entries on the database:%d\n\n",num);
    printf("How many doctor entries do you wish to add?:\n");
    scanf("%d",&n);
    sum=n+num;

    for(i=num,j=0; i<sum; i++){
        printf("\n");
        fflush(stdin);
        printf("Enter doctor name:");
        gets(doc[i].name);
        fflush(stdin);
        printf("Enter doctor specialty:");
        scanf("%d",&doc[i].specialty);
        fflush(stdin);
        printf("Enter doctor gender:");
        gets(doc[i].gender);
        fflush(stdin);
        printf("Enter doctor post:");
        gets(doc[i].post);
        fflush(stdin);
        printf("Enter doctor phone number(+880):");
        scanf("%d",&doc[i].phone);
        fflush(stdin);
        printf("Enter doctor age:");
        scanf("%d",&doc[i].age);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}

void docView(){
    for(i=1; i<=num; i++)
    {
        printf("\n");
        printf("Serial number:%d\n",i);
        printf("Name:");
        puts(doc[i].name);
        printf("Gender:");
        puts(doc[i].gender);
        printf("Specialty:");
        puts(doc[i].specialty);
        printf("Post:");
        puts(doc[i].post);
        printf("Phone number:+880%d\n",doc[i].phone);
        printf("Age:%d",doc[i].age);
        printf("\n\n");
    }
}

void docEdit(){
    int entry,serial;
    fflush(stdin);
    printf("Which entry do you wish to edit?\n");
    printf("1.Name\n");
    printf("2.Gender\n");
    printf("3.Specialty\n");
    printf("4.Post\n");
    printf("5.Phone number\n");
    printf("6.Age\n");
    printf("Enter your choice\n");
    printf("=>");
    scanf("%d",&entry);
    if(entry<=6){
        printf("Enter the serial number of the doctor(1 - %d):",num-1);
        scanf("%d",&serial);
        if(serial<num){
            if(entry==1){
                fflush(stdin);
                printf("Enter new doctor name:");
                gets(doc[serial].name);

            }
            else if(entry==2){
                fflush(stdin);
                printf("Enter new doctor gender:");
                gets(doc[serial].gender);
            }
            else if(entry==3){
                fflush(stdin);
                printf("Enter new doctor specialty:");
                gets(doc[serial].specialty);
            }
            else if(entry==4){
                fflush(stdin);
                printf("Enter new doctor post");
                gets(doc[serial].post);
            }
            else if(entry==5){
                fflush(stdin);
                printf("Enter the new doctor phone number(+880):");
                scanf("%d",&doc[serial].phone);
            }
            else if(entry==6){
                fflush(stdin);
                printf("Enter the new doctor age:");
                scanf("%d",&doc[serial].age);
            }
        }
        else
        {
            printf("\n\nInvalid serial! Try again.");
        }
    }
    else
    {
        printf("\n\nInvalid choice! Try Again.");
    }
}

void docSearch(){
    int sSerial,sCh,sFlag;
    char sQuery[100];
    printf("By which criteria, do you want to search?\n");
    printf("1.Serial number\n");
    printf("2.Name\n");
    printf("3.Gender\n");
    printf("4.Specialty\n");
    printf("5.Post\n");
    printf("6.Phone number\n");
    printf("7.Age\n");
    printf("Enter your choice.\n");
    printf("=>");
    scanf("%d",&sCh);
    if(sCh==1){
        printf("Enter serial number of the doctor:");
        scanf("%d",&sSerial);
        if(sSerial<num){
            printf("\n");
            printf("Serial number:%d\n",sSerial);
            printf("Name:");
            puts(doc[sSerial].name);
            printf("Specialty:");
            puts(doc[sSerial].specialty);
            printf("Gender:");
            puts(doc[sSerial].gender);
            printf("Post:");
            puts(doc[sSerial].post);
            printf("Phone number:0%d\n",doc[sSerial].phone);
            printf("Age:%d",doc[sSerial].age);
            printf("\n\n");
        }
        else
            printf("\n\nSearch result not found!\n\n");
    }
    else if(sCh==2){
        int sFlag=1;
        fflush(stdin);
        printf("Enter doctor name:");
        gets(sQuery);
        fflush(stdin);
        for(docIndex=0; docIndex<num; docIndex++){
            if(strcmp(sQuery,doc[docIndex].name)==0){
                printf("\n");
                printf("Serial number:%d\n",docIndex);
                printf("Name:");
                puts(doc[docIndex].name);
                printf("Specialty:");
                puts(doc[docIndex].specialty);
                printf("Gender:");
                puts(doc[docIndex].gender);
                printf("Post:");
                puts(doc[docIndex].post);
                printf("Phone number:0%d\n",doc[docIndex].phone);
                printf("Age:%d",doc[docIndex].age);
                printf("\n\n");
                sFlag=0;
            }
        }
        if(sFlag==1)
            printf("\n\nSearch result not found!\n\n");

    }
    else if(sCh==3){
        int sFlag=1;
        int sNum;
        printf("Enter doctor gender:");
        gets(sQuery);
        for(docIndex=0; docIndex<num; docIndex++){
            if(strcmp(sQuery,doc[docIndex].gender)==0){
                printf("\n");
                printf("Serial number:%d\n",docIndex);
                printf("Name:");
                puts(doc[docIndex].name);
                printf("Specialty:");
                puts(doc[docIndex].specialty);
                printf("Gender:");
                puts(doc[docIndex].gender);
                printf("Post:");
                puts(doc[docIndex].post);
                printf("Phone number:0%d\n",doc[docIndex].phone);
                printf("Age:%d",doc[docIndex].age);
                printf("\n\n");
                sFlag=0;
            }
        }
        if(sFlag==1)
            printf("\n\nSearch result not found!\n\n");

    }
    else if(sCh==4){
        int sFlag=1;
        fflush(stdin);
        printf("Enter doctor specialty:");
        gets(sQuery);
        fflush(stdin);
        for(docIndex=0; docIndex<num; docIndex++){
            if(strcmp(sQuery,doc[docIndex].specialty)==0){
                printf("\n");
                printf("Serial number:%d\n",docIndex);
                printf("Name:");
                puts(doc[docIndex].name);
                printf("Specialty:");
                puts(doc[docIndex].specialty);
                printf("Gender:");
                puts(doc[docIndex].gender);
                printf("Post:");
                puts(doc[docIndex].post);
                printf("Phone number:0%d\n",doc[docIndex].phone);
                printf("Age:%d",doc[docIndex].age);
                printf("\n\n");
                sFlag=0;
            }
        }
        if(sFlag==1)
            printf("\n\nSearch result not found!\n\n");
    }
    else if(sCh==5){
        int sFlag=1;
        int sNum;
        printf("Enter doctor post:");
        gets(sQuery);
        for(docIndex=0; docIndex<num; docIndex++){
            if(strcmp(sQuery,doc[docIndex].post)==0){
                printf("\n");
                printf("Serial number:%d\n",docIndex);
                printf("Name:");
                puts(doc[docIndex].name);
                printf("Specialty:");
                puts(doc[docIndex].specialty);
                printf("Gender:");
                puts(doc[docIndex].gender);
                printf("Post:");
                puts(doc[docIndex].post);
                printf("Phone number:0%d\n",doc[docIndex].phone);
                printf("Age:%d",doc[docIndex].age);
                printf("\n\n");
                sFlag=0;
            }
        }
        if(sFlag==1)
            printf("\n\nSearch result not found!\n\n");

    }
    else if(sCh==6){
        int sFlag=1;
        int sNum;
        printf("Enter doctor phone number:");
        scanf("%d",&sNum);
        for(docIndex=0; docIndex<num; docIndex++){
            if(sNum==doc[docIndex].phone){
                printf("\n");
                printf("Serial number:%d\n",docIndex);
                printf("Name:");
                puts(doc[docIndex].name);
                printf("Specialty:");
                puts(doc[docIndex].specialty);
                printf("Gender:");
                puts(doc[docIndex].gender);
                printf("Post:");
                puts(doc[docIndex].post);
                printf("Phone number:0%d\n",doc[docIndex].phone);
                printf("Age:%d",doc[docIndex].age);
                printf("\n\n");
                sFlag=0;
            }
        }
        if(sFlag==1)
            printf("\n\nSearch result not found!\n\n");
    }
    else if(sCh==7){
        int sFlag=1;
        int sNum;
        printf("Enter doctor age in years:");
        scanf("%d",&sNum);
        for(patIndex=0; patIndex<num; patIndex++){
            if(sNum==pat[patIndex].age){
                printf("\n");
                printf("Serial number:%d\n",docIndex);
                printf("Name:");
                puts(doc[docIndex].name);
                printf("Specialty:");
                puts(doc[docIndex].specialty);
                printf("Gender:");
                puts(doc[docIndex].gender);
                printf("Post:");
                puts(doc[docIndex].post);
                printf("Phone number:0%d\n",doc[docIndex].phone);
                printf("Age:%d",doc[docIndex].age);
                printf("\n\n");
                sFlag=0;
            }
        }
        if(sFlag==1)
            printf("\n\nSearch result not found!\n\n");
    }
    else
        printf("\n\nInvalid input!\n\n");
}

void docDel(){
    int delOption;
    printf("Enter the serial number of the doctor that you want to delete:");
    scanf("%d",&patIndex);
    if(patIndex<num){
        printf("Which entry do you wish to delete?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove specialty\n4.Remove gender\n5.Remove post\n6.Remove phone number\n7.Remove age\n=>");
        scanf("%d",&delOption);
        if(delOption==1){
            while(patIndex<num){
                strcpy(doc[docIndex].name,doc[docIndex+1].name);
                strcpy(doc[docIndex].specialty,doc[docIndex+1].specialty);
                strcpy(doc[docIndex].gender,doc[docIndex+1].gender);
                strcpy(doc[docIndex].post,doc[docIndex+1].post);
                doc[docIndex].phone=doc[docIndex+1].phone;
                doc[docIndex].age=doc[docIndex+1].age;
                docIndex++;
            }
            num--;
        }
        else if(delOption==2){
            strcpy(doc[docIndex].name,"Cleared");
        }
        else if(delOption==3){
            strcpy(doc[docIndex].specialty,"Cleared");
        }
        else if(delOption==4){
            strcpy(doc[docIndex].gender,"Cleared");
        }
        else if(delOption==5){
            strcpy(doc[docIndex].post,"Cleared");
        }
        else if(delOption==6){
            doc[docIndex].phone=0;
        }
        else if(delOption==7){
            doc[docIndex].age=0;
        }
    }
    else printf("\n\nInvalid input!\n");
}

void docRead(){
    FILE *fp = fopen("doctor.txt","r");
    if(fp==NULL){
        fp=fopen("doctor.txt","w");
        fclose(fp);
        printf("Doctor file scanned!\n\n\n");
        return 0;
    }
    num=fread(pat, sizeof(struct doctor),100, fp);
    fclose(fp);
}

void docWrite(){
    FILE *fp = fopen("doctor.txt","w");
    if(fp == NULL){
        printf("Error opening doctor file!");
        exit(1);
    }
    fwrite(pat, sizeof(struct doctor),num, fp);
    printf("Doctor file created!\n\n\n");
    fclose(fp);
}


void patAdd(){
    printf("\n\n");
    printf("Number of existing entries on the database:%d\n\n",num);
    printf("How many patient entries do you wish to add?:\n");
    scanf("%d",&n);
    sum=n+num;

    for(i=num,j=0; i<sum; i++){
        printf("\n");
        fflush(stdin);
        printf("Enter patient name:");
        gets(pat[i].name);
        fflush(stdin);
        printf("Enter patient disease:");
        gets(pat[i].disease);
        fflush(stdin);
        printf("Enter patient gender:");
        gets(pat[i].gender);
        fflush(stdin);
        printf("Enter patient room number:");
        scanf("%d",&pat[i].room);
        fflush(stdin);
        printf("Enter patient phone number(+880):");
        scanf("%d",&pat[i].phone);
        fflush(stdin);
        printf("Enter patient age:");
        scanf("%d",&pat[i].age);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}


void patView(){
    for(i=1; i<=num; i++){
        printf("\n");
        printf("Serial number:%d\n",i);
        printf("Name:");
        puts(pat[i].name);
        printf("Disease:");
        puts(pat[i].disease);
        printf("Gender:");
        puts(pat[i].gender);
        printf("Room number:%d\n",pat[i].room);
        printf("Phone number:+880%d\n",pat[i].phone);
        printf("Age:%d",pat[i].age);
        printf("\n\n");
    }
}

void patEdit(){
    int entry,serial;
    fflush(stdin);
    printf("Which entry do you wish to edit?\n");
    printf("1.Name\n");
    printf("2.Disease\n");
    printf("3.Gender\n");
    printf("4.Room number\n");
    printf("5.Phone number\n");
    printf("6.Age\n");
    printf("Enter your choice.\n");
    printf("=>");
    scanf("%d",&entry);
    if(entry<=6){
        printf("Enter the serial no of that patient= (1 - %d)=",num-1);
        scanf("%d",&serial);
        if(serial<num){
            if(entry==1){
                fflush(stdin);
                printf("Enter the new patient name:");
                gets(pat[serial].name);
            }
            else if(entry==2){
                fflush(stdin);
                printf("Enter the new patient disease:");
                gets(pat[serial].disease);
            }
            else if(entry==3){
                fflush(stdin);
                printf("Enter the new patient gender:");
                gets(pat[serial].gender);
            }
            else if(entry==4){
                fflush(stdin);
                printf("Enter the new room number:");
                scanf("%d",&pat[serial].room);
            }
            else if(entry==5){
                fflush(stdin);
                printf("Enter the new phone number(+880):");
                scanf("%d",&pat[serial].phone);
            }
            else if(entry==6){
                fflush(stdin);
                printf("Enter the new age:");
                scanf("%d",&pat[serial].age);
            }
        }
        else
        {
            printf("\n\nInvalid serial! Try again.");
        }
    }
    else
    {
        printf("\n\nInvalid choice! Try Again.");
    }
}

void patSearch(){
    int sSerial,sCh,sFlag;
    char sQuery[100];
    printf("By which criteria, do you want to search?\n");
    printf("1.Serial number\n");
    printf("2.Name\n");
    printf("3.Disease\n");
    printf("4.Gender\n");
    printf("5.Room number\n");
    printf("6.Phone no.\n");
    printf("7.Age\n\n=");
    printf("Enter your choice.\n");
    printf(">");
    scanf("%d",&sCh);
    if(sCh==1){
        printf("Enter serial number of the patient=");
        scanf("%d",&sSerial);
        if(sSerial<num){
            printf("\n");
            printf("Serial Number:%d\n",sSerial);
            printf("Name:");
            puts(pat[sSerial].name);
            printf("Disease:");
            puts(pat[sSerial].disease);
            printf("Gender:");
            puts(pat[sSerial].gender);
            printf("Room number:%d\n",pat[patIndex].room);
            printf("Phone number:0%d\n",pat[patIndex].phone);
            printf("Age:%d",pat[patIndex].age);
            printf("\n\n");
        }
        else
            printf("\n\nSearch result not found!\n\n");
    }
    else if(sCh==2){
        int sFlag=1;
        fflush(stdin);
        printf("Enter patient name:");
        gets(sQuery);
        fflush(stdin);
        for(patIndex=0; patIndex<num; patIndex++){
            if(strcmp(sQuery,pat[patIndex].name)==0){
                printf("\n");
                printf("Serial number:%d\n",patIndex);
                printf("Name:");
                puts(pat[patIndex].name);
                printf("Disease:");
                puts(pat[patIndex].disease);
                printf("Room number:%d\n",pat[patIndex].room);
                printf("Phone number:0%d\n",pat[patIndex].phone);
                printf("Age:%d",pat[patIndex].age);
                printf("\n\n");
                sFlag=0;

            }
        }
        if(sFlag==1)
            printf("\nSearch result not found!\n");

    }
    else if(sCh==3){
        int sFlag=1;
        fflush(stdin);
        printf("Enter patient disease:");
        gets(sQuery);
        fflush(stdin);
        for(patIndex=0; patIndex<num; patIndex++){
            if(strcmp(sQuery,pat[patIndex].disease)==0){
                printf("\n");
                printf("Serial number:%d\n",patIndex);
                printf("Name:");
                puts(pat[patIndex].name);
                printf("Disease:");
                puts(pat[patIndex].disease);
                printf("Room number:%d\n",pat[patIndex].room);
                printf("Phone number:0%d\n",pat[patIndex].phone);
                printf("Age:%d",pat[patIndex].age);
                printf("\n\n");
                sFlag=0;
            }
        }
        if(sFlag==1)
            printf("\nSearch result not found!\n");
    }
    else if(sCh==4){
        int sFlag=1;
        fflush(stdin);
        printf("Enter patient gender:");
        gets(sQuery);
        fflush(stdin);
        for(patIndex=0; patIndex<num; patIndex++){
            if(strcmp(sQuery,pat[patIndex].gender)==0){
                printf("\n");
                printf("Serial number:%d\n",patIndex);
                printf("Name:");
                puts(pat[patIndex].name);
                printf("Disease:");
                puts(pat[patIndex].disease);
                printf("Room number:%d\n",pat[patIndex].room);
                printf("Phone number:0%d\n",pat[patIndex].phone);
                printf("Age:%d",pat[patIndex].age);
                printf("\n\n");
                sFlag=0;
            }
        }
        if(sFlag==1)
            printf("\nSearch result not found!\n");
    }
    else if(sCh==5){
        int sFlag=1;
        int sNum;
        printf("Enter patient room number:");
        scanf("%d",&sNum);
        for(patIndex=0; patIndex<num; patIndex++){
            if(sNum==pat[patIndex].room){
                printf("\n");
                printf("Serial number:%d\n",patIndex);
                printf("Name:");
                puts(pat[patIndex].name);
                printf("Disease:");
                puts(pat[patIndex].disease);
                printf("Room number:%d\n",pat[patIndex].room);
                printf("Phone number:0%d\n",pat[patIndex].phone);
                printf("Age:%d",pat[patIndex].age);
                printf("\n\n");
                sFlag=0;
            }
        }
        if(sFlag==1)
            printf("\nSearch result not found!\n");

    }
    else if(sCh==6){
        int sFlag=1;
        int sNum;
        printf("Enter patient phone number:");
        scanf("%d",&sNum);
        for(patIndex=0; patIndex<num; patIndex++){
            if(sNum==pat[patIndex].phone){
                printf("\n");
                printf("Serial number:%d\n",patIndex);
                printf("Name:");
                puts(pat[patIndex].name);
                printf("Disease:");
                puts(pat[patIndex].disease);
                printf("Room number:%d\n",pat[patIndex].room);
                printf("Phone number:0%d\n",pat[patIndex].phone);
                printf("Age:%d",pat[patIndex].age);
                printf("\n\n");
                sFlag=0;
            }

        }
        if(sFlag==1)
            printf("\nSearch result not found!\n");
    }
    else if(sCh==7){
        int sFlag=1;
        int sNum;
        printf("Enter patient age:");
        scanf("%d",&sNum);
        for(patIndex=0; patIndex<num; patIndex++){
            if(sNum==pat[patIndex].age){
                printf("\n");
                printf("Serial number:%d\n",patIndex);
                printf("Name:");
                puts(pat[patIndex].name);
                printf("Disease:");
                puts(pat[patIndex].disease);
                printf("Room number:%d\n",pat[patIndex].room);
                printf("Phone number:0%d\n",pat[patIndex].phone);
                printf("Age:%d",pat[patIndex].age);
                printf("\n\n");
                sFlag=0;
            }

        }
        if(sFlag==1)
            printf("\nSearch result not found!\n");
    }
    else
        printf("\n\nInvalid input!\n\n");
}

void patDel(){
    int patIndex,delOption;
    printf("Enter the serial number of the patient that you want to delete=");
    scanf("%d",&patIndex);
    if(patIndex<num){
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n");
        printf("2.Remove Name\n");
        printf("3.Remove Disease\n");
        printf("4.Remove age\n");
        printf("5.Remove Cabin\n");
        printf("6.Remove phone number\n");
        printf("=>");
        scanf("%d",&delOption);
        if(delOption==1){
            while(patIndex<num){
                strcpy(pat[patIndex].name,pat[patIndex+1].name);
                strcpy(pat[patIndex].disease,pat[patIndex+1].disease);
                pat[patIndex].age=pat[patIndex+1].age;
                pat[patIndex].room=pat[patIndex+1].room;
                pat[patIndex].phone=pat[patIndex+1].phone;
                patIndex++;
            }
            num--;
        }
        else if(delOption==2){
            strcpy(pat[patIndex].name,"Cleared");
        }
        else if(delOption==3){
            strcpy(pat[patIndex].disease,"Cleared");
        }
        else if(delOption==4){
            pat[patIndex].age=0;
        }
        else if(delOption==5){
            pat[patIndex].room=0;
        }
        else if(delOption==6){
            pat[patIndex].phone=0;
        }
    }
    else printf("\n\nInvalid input!\n");
}

void patRead(){
    FILE *fp = fopen("patient.txt","r");
    if(fp==NULL){
        fp=fopen("patient.txt","w");
        fclose(fp);
        printf("Patient File Created\n\n\n");
        return 0;
    }
    num=fread(pat, sizeof(struct patient),100, fp);
    fclose(fp);
}

void patWrite(){
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL){
        printf("Error");
        exit(1);
    }
    fwrite(pat, sizeof(struct patient),num, fp);
    fclose(fp);
}
struct userAcc{
    char username[100];
    char password[100];
};
struct userAcc u[200];

writeAcc(char *user, char *userpass){
    FILE *fp;
    fp=fopen("users.txt","w");
    //fp=fopen("users.txt","wb");           //for binary encrypted data, unreadable so secure
    for(int i=0; i<200; i++){
        fscanf(fp,"%s %s\n",u[i].username,u[i].password);
    }
    for(int i=0; i<200; i++){
        fprintf(fp,"%s %s\n",u[i].username,u[i].password);
    }
    fprintf(fp,"%s %s\n",user,userpass);
}



int main(){
    read();
    int i,ch,userType;
    char user[100];
    char userpass[100];
    loading();
    anyKey();
    char welcome[256]="Welcome to the Prometheus Hospital Management System";
    char adminWelcome[256]="Welcome to Administrative Management Section";
    char docWelcome[256]="Welcome to Doctor Management Section";
    animatedText(welcome);

    printf("\n\nIf you are a patient, please go to the help desk and contact an administrator. Thank you");
    Sleep(3000);
    system("cls");

    printf("\n\n\t\t\t\t\t\t1.Create administrator account.\n");
    printf("\t\t\t\t\t\t2.Login as administrator.\n");
    printf("\t\t\t\t\t\t3.Create doctor account.\n");
    printf("\t\t\t\t\t\t4.Login as doctor.\n");
    printf("\t\t\t\t\t\t5.Exit.\n");
    printf("=>");
    scanf("%d",&userType);
    system("cls");

    if(userType==1){
        printf("\n\n\t\t\t\t\t\tEnter username:");
        scanf("%s",user);
        printf("\t\t\t\t\t\tEnter password:");
        scanf("%s",userpass);

        writeAcc(user,userpass);
    }

    else if(userType=2){
        animatedText(adminWelcome);
        printf("\n\n\t\t\t\t\t\tEnter username:");
        fflush(stdin);
        gets(user);
        printf("\t\t\t\t\t\tEnter password:");
        fflush(stdin);
        gets(userpass);
        if((strcmp(user,"admin"))==0&&(strcmp(userpass,"admin")==0)){
            while(ch!=6){
                printf("Enter your choice\n\n");
                printf("01. Add patient information\n");
                printf("02. View patient information\n");
                printf("03. Search patient information\n");
                printf("04. Edit patient nformation\n");
                printf("05. Delete patient information\n");
                printf("06. Add doctor information\n");
                printf("07. View doctor information\n");
                printf("08. Search doctor information\n");
                printf("09. Edit doctor nformation\n");
                printf("10. Delete doctor information\n");
                printf("11. Exit\n\n=>");
                scanf("%d",&ch);
                fflush(stdin);
                if(ch==1){
                    system("cls");
                    patAdd();
                }
                else if(ch==2){
                    system("cls");
                    patView();
                }
                else if(ch==3){
                    system("cls");
                    patSearch();
                }
                else if(ch==4){
                    system("cls");
                    patEdit();
                }
                else if(ch==5){
                    system("cls");
                    patDel();
                }
                else if(ch==6){
                    docAdd();
                    return 0;
                }
                else if(ch==7){
                    system("cls");
                    docView();
                }
                else if(ch==8){
                    system("cls");
                    docSearch();
                }
                else if(ch==9){
                    system("cls");
                    docEdit();
                }
                else if(ch==10){
                    system("cls");
                    docDel();
                }
                else if(ch==11){
                    patWrite();
                    docWrite();
                    return 0;
                }
                else{
                    system("cls");
                    printf("\n\nInvalid input! Please try again");
                }
                printf("\n\n");
            }
        }
    }

    else if(userType==3){
        printf("\n\n\t\t\t\t\t\tEnter username:");
        scanf("%s",user);
        printf("\t\t\t\t\t\tEnter password:");
        scanf("%s",userpass);

        writeAcc(user,userpass);
    }

    else if(userType=4){
        animatedText(docWelcome);
        printf("\n\n\t\t\t\t\t\tEnter username:");
        gets(user);
        printf("\t\t\t\t\t\tEnter password:");
        gets(userpass);
        for(i=100; i<200; i++){
            if(strcmp(u[i].username,user)==0){
                if(strcmp(u[i].password,userpass)==0){
                    while(ch!=6){
                        printf("Enter your choice\n\n");
                        printf("1. Add patient information\n");
                        printf("2. View patient information\n");
                        printf("3. Search patient information\n");
                        printf("4. Edit patient nformation\n");
                        printf("5. Delete patient information\n");
                        printf("6. Exit\n\n=>");
                        scanf("%d",&ch);
                        fflush(stdin);
                        if(ch==1){
                            system("cls");
                            patAdd();
                        }
                        else if(ch==2){
                            system("cls");
                            patView();
                        }
                        else if(ch==3){
                            system("cls");
                            patSearch();
                        }
                        else if(ch==4){
                            system("cls");
                            patEdit();
                        }
                        else if(ch==5){
                            system("cls");
                            patDel();
                        }
                        else if(ch==6){
                            patWrite();
                            return 0;
                        }
                        else{
                            system("cls");
                            printf("\n\nInvalid input! Please try again");
                        }
                        printf("\n\n");
                    }
                }
            }
        }
    }

}



