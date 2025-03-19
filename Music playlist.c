#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSongs 100

struct Node{
    char song[MaxSongs];
    struct Node* next;
};


void insert_songs_in_playlist(struct Node **head, char *song){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song, song);
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
    }
    else{
        struct Node* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print_the_playlist(struct Node *head){
    printf("\nYour playlist:\n");
    int index = 1;
    while (head != NULL){
        printf("%d. %s\n", index++, head->song);
        head = head->next;
    }
}

void play_the_playlist(struct Node *head){
    int choice;
    do{
        struct Node* temp = head;
        while (temp != NULL){
            printf("Now playing: %s\n", temp->song);
            temp = temp-> next;
        }
        printf("\nDo you want to repeat the playlist? (1/0): ");
        scanf(" %d", &choice);
    }while (choice == 1);

    printf("\nExit the playlist.\n");
}

int main(){
    struct Node *playlist = NULL;
    int n;

    printf("Enter the total number of songs: ");
    scanf("%d", &n);

    if (n <= 0){
        printf("ERROR!!! Enter again\n");
        return 1;
    }

    char song[MaxSongs];
    for (int i = 0; i < n; i++){
        printf("Enter the name of song %d: ", i + 1);
        scanf(" %[^\n]", song);
       insert_songs_in_playlist(&playlist, song);
    }

    print_the_playlist(playlist);

    printf("\nPlaying the playlist:\n");
    play_the_playlist(playlist);

    return 0;
}
