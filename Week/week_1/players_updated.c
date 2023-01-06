#include<stdio.h>
#include<stdlib.h>
// node - details of one player
struct player {
int id; 
char name[20];
struct player * next; // link to next node
};

void init_list(struct player *);
struct player * insert_after_node(struct player *, struct player *);
void delete_after_node(struct player *);
void display_list(struct player *);
struct player * get_node_details();
void display_node_details(struct player *p);

int main()
{
struct player players; // list head - dummy node
struct player *p, *q;
players.next = NULL; // “defensive programming”, in case
p = &players;
while (q = get_node_details()) {
p = insert_after_node(p,q);
}
p->next = NULL; // “defensive programming”, in case
display_list(players.next);
//delete_after_node(p);
//display_list(students.next);
}

struct player * insert_after_node(struct player *p, struct player *q)
{
if ((!p) || (!q)) // in case NULL is passed
return NULL;
q->next = p->next;
p->next = q;
return q;
}

void delete_after_node(struct player *p)
{
struct player *q;
if (!p) // in case NULL is passed in p
return;
q = p->next; // to keep for the ‘free’
p->next = q->next;
if (q) // cannot ‘free’ NULL
free(q);
}

void display_list(struct player *p)
{
while (p) {
display_node_details(p);
p = p->next;
}
}

struct player * get_node_details()
{
struct player *p;
p = (struct player *) malloc( sizeof(struct player) );
if (p == NULL)
return(NULL);
printf("Enter player's id number (0 to stop)\n");
scanf ("%d", &(p->id) );
if((p->id) == 0)
return(NULL);
printf("Enter player's name\n");
scanf ("%s", &(p->name) );
p->next = NULL;
return p;
}
void display_node_details(struct player *p)
{
if (p) {
printf("Player => Id number %d: ",p->id);
printf("Name: %s\n",p->name);
}
}
