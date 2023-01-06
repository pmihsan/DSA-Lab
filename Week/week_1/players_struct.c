#include<stdio.h>
#include<stdlib.h>
#define ARRSIZE 50
struct player{
	int position;
	char name[ARRSIZE];
	char role[ARRSIZE];
	struct player *next;
};
struct player *get_input();
void displayPlayers(struct player *);
int insertPlayer(struct player *,struct player *);
int updatePlayer(struct player *,int);
int deletePlayer(struct player *,int);

int main(){
	int n,position;
	struct player *p, *q, *players;
	players = (struct player *)malloc(sizeof(struct player));
	if(players == NULL){
		return 1;
	}
	players->next = NULL;
	while(1){
		printf("FootBall - FIFA Game\n");
		printf("1.Insert a Player\n2.Update a Player\n3.Delete a Player\n4.Display the Players\nEnter your choice\n");
        scanf("%d",&n);
		if(n == 1){
			printf("\nInsert a player\n\n");
			if((q = get_input()) && insertPlayer(players,q)){ //To get the input players and create a list
				printf("Successfully Inserted\n\n");
			}else{
				printf("Insertion Failed\n\n");
			}
		}else if(n == 2){
			printf("\nUpdate a player\n\n");
			printf("Enter the position(1-10) to which you want the player to be updated\n");
			scanf("%d",&position);
			if(position > 0 && position <= 10 && updatePlayer(players,position)){ //To update a player in the list using position
				printf("Successfully Updated\n\n");
			}else{
					printf("Update Failed\n\n");
				}
		}else if(n == 3){
			printf("\nDelete a player\n\n");
			printf("Enter the position(1-10) to delete the player\n");
			scanf("%d",&position);
			if(position > 0 && position <= 10 && deletePlayer(players,position)){ //To delete a player in list with position
				printf("Successfully Deleted\n\n");
			}else{
				printf("Deletion Failed\n");
			}
		}else if(n == 4){
			printf("\nDisplaying the players\n\n");
			displayPlayers(players); //Displaying the Players list
			printf("\n");
		}else{
			break;
		}
	}
	printf("\nProgram Ended\n");
	return 0;
}
struct player *get_input(){
	struct player *temp;
	temp = (struct player *)malloc(sizeof(struct player *));//
	printf("Enter the position to insert the player\n");
    scanf("%d",&temp->position);
    if(temp->position > 0 && temp->position <= 10){
        printf("Enter the name of the player\n");
		scanf("%s",temp->name);
		printf("Enter the role of the player\n");
		scanf("%s",temp->role);
		return temp;
	}else{
		return NULL;
	}
}
int insertPlayer(struct player *players,struct player *new){
	struct player *temp;//
	temp = players;
	if(temp->next == NULL){
		new->next = temp->next;
		temp->next = new;
		return 1;
	}
	while(temp->next != NULL){
		if((temp->next)->position == new->position){
			return 0;
		}else if((temp->next)->position > new->position){
			new->next = temp->next;
			temp->next = new;
			return 1;
		}else{
			temp = temp->next;
		}
	}
	new->next = temp->next;
	temp->next = new;
	return 1;
}
int deletePlayer(struct player *players,int position){
	struct player *temp,*prev;//
	temp = players->next;
	prev = players;
	if(temp == NULL){
		return 0;
	}
	while(temp != NULL){
		if(temp->position == position){
			prev->next = temp->next;
			free(temp);
			return 1;
		}
		prev = temp;
		temp = temp->next;
	}
	return 0;
}
int updatePlayer(struct player *players,int position){
	struct player *new;
	if(!deletePlayer(players,position)){
		return 0;
	}
	new = (struct player *)malloc(sizeof(struct player *)); 
    new->position = position;
    printf("Enter the new name of the player to update at %d position\n",position);
	scanf("%s",new->name);
	printf("Enter the new role of the player to update at %d position\n",position);
	scanf("%s",new->role);
	if(!insertPlayer(players,new)){
		return 0;
	}
	return 1;
}
void displayPlayers(struct player *players){
	struct player *temp;
	temp = players->next;
	if(temp == NULL){
		printf("Player list is Empty\n");
	}else{
	printf("Players list\n");
	}
	while(temp != NULL){
		printf("Player: %d\n",temp->position);
		printf("Name : %s\nRole: %s\n",temp->name,temp->role);
		temp = temp->next;
	}
}
