#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
void member_information();
void book_information();
void all_members();
void all_books();



int main() {
    int choice;

    do {
        printf("\nChoose one of the following options:\n");
        printf("1 - To add a new member\n");
        printf("2 - To add a new book\n");
        printf("3 - To print all members' information\n");
        printf("4 - To print all books' information\n");
        printf("5 - To quit\n");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            member_information();
            break;

        case 2:
            book_information();

            break;

        case 3:
            all_members();

            break;

        case 4:
            all_books();

            break;

        case 5:
            printf("Exiting the program...\n");
            break;

        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}


struct Member {
    int memberID;
    char name[20];
    char phone_number[10];
};
struct Member newMember[50];
int member_count = 0;
#define MAX_MEMBERS 100

void member_information() {
      
    int memberID;
    if (member_count >= MAX_MEMBERS) {
        printf("No available palces for new members!\n");
        return;
    }

    printf("\nEnter Member ID: ");
    scanf_s("%d", &memberID);


    for (int i = 0; i < member_count; i++ ) {
        if (newMember[i].memberID == memberID) {
            printf("member ID exists\n ");
            return;
        }
    }

    newMember[member_count].memberID = memberID;
    printf("Enter Member Name: ");
    scanf_s("%s", newMember[member_count].name, 20);

    printf("Enter Phone Number: ");
    scanf_s("%s", newMember[member_count].phone_number, 10);

    printf("\nNew Member Added Successfully!\n");
    printf("Member ID: %d\n", newMember[member_count].memberID);
    printf("Name: %s\n", newMember[member_count].name);
    printf("Phone Number: %s\n", newMember[member_count].phone_number);
     member_count++;

}


struct book {
    int bookID;
    char title[20];
    char author[20];
    int year_publish;
    int memberID; 
}; 
struct book newbook[50];
int book_count = 0;
#define MAX_book 100


void book_information() {

    if (book_count >= MAX_book) {
        printf("no available places for new books!\n");
        return;
    }

    int bookID;
    printf("\nEnter book ID: ");
    scanf_s("%d", &bookID);


    for (int i = 0; i < book_count; i++) {
        if (newbook[i].bookID == bookID) {
            printf("book ID exists\n ");
            return;
        }
    }
    newbook[book_count].bookID = bookID;
    printf("Enter book title: ");
    scanf_s("%s", newbook[book_count].title, 20);

    printf("Enter author : "); //
    scanf_s("%s", &newbook[book_count].author, 20);

    printf("Enter year publish : ");
    scanf_s("%d", &newbook[book_count].year_publish);

    printf("Enter memberID : ");
    scanf_s("%d", &newbook[book_count].memberID);

    printf("\nNew book Added Successfully!\n");
    printf("book ID: %d\n", newbook[book_count].bookID);
    printf("title: %s\n", newbook[book_count].title);
    printf("author: %s\n", newbook[book_count].author);
    printf("year_publish: %d\n", newbook[book_count].year_publish);
    printf("member ID: %d\n", newbook[book_count].memberID);

    book_count++;

}

void all_members() {
     
    if (member_count == 0) {
        printf("\nno member\n");

    }

    printf("%s %13s %17s\n", "memberID", "name", "phone_number");
      for (int i = 0; i < member_count; i++) {
        
       printf("%d ", newMember[i].memberID);
       printf("%14s ", newMember[i].name);
       printf("%15s ", newMember[i].phone_number);

       puts("");
      }
}


void all_books() {
    if (book_count == 0) {
        printf("No books available.\n");
    }

    printf("%s %13s %17s %22s %28s\n", "book ID", "title", "author", "year_publish", "memberID");
    for (int i = 0; i < book_count; i++) {

        printf("%d ", newbook[i].bookID);
        printf("%14s ", newbook[i].title);
        printf("%15s ", newbook[i].author);
        printf("%22d ", newbook[i].year_publish);
        printf("%28d ", newbook[i].memberID);

        puts("");
    }

}