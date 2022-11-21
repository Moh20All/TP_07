#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
//Definition de la structure
   typedef struct node
    {
      int val;
      struct node *link;
    }node;
    node *Tete,*temp,*Tet1,*ink;
    int i=1,alt;
//Def de fonction de creation

node *creation(int n ){
//La fonction de creation de "Nodes"
node * HEAD=NULL;
node * TEMP=NULL;
node * P=NULL;

for(int i=0;i<n;i++){

    TEMP=(node*)malloc(sizeof(node));
    printf("Entrer la valeur %d \n",i+1);
    scanf("%d",&(TEMP->val));
    TEMP->link=NULL;

    if(HEAD==NULL){
        HEAD=TEMP;
    }else{

    P=HEAD;
    while(P->link != NULL){
        P = P->link;
    }//Loop
    P->link=TEMP;

    }//else


}
   return HEAD;
}

void display(node *HEAD){

node * P=HEAD;

    while(P!=NULL)
    {
       printf("%d->",P->val);
       P=P->link;
    }



}

//Fonction d'ajout node pour la list de resault
node *push(node* head,int val){
node * newp = (node*)malloc(sizeof(node));
newp->val=val;
newp->link=head;
head=newp;
return head;

}
//Recherche de element
bool reche(int x,node *EL){

node *P=EL;
bool ch=false;
    while(P!=NULL)
    {
       if((P->val)==x){
       ch=true;
       return ch;
       }else{
       P=P->link;
       }

    }
}

//Ajout un element
void insert(node *q,node *l,int p){
    printf("Entrer la valeur de element a inserer : ");
   scanf("%d",&(q->val)) ;
   node *temp =l  ;
   for(int i=2; i < p; i++){
   if(temp->link != NULL){
   temp = temp->link;
   }
   }
   q->link = temp->link;
    temp->link = q;
    }
//inserer au debut
    void insert_debut()
{
         node *temp;
        temp=( node *)malloc(sizeof(node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEntrer le valeur de node:\t" );
        scanf("%d",&temp->val);
        temp->link =NULL;
        if(Tete==NULL)
        {
                Tete=temp;
        }
        else
        {
                temp->link=Tete;
                Tete=temp;
        }
}
//inserer a la fin
    void insert_fin()
{
         node *temp,*ptr;
        temp=(node *)malloc(sizeof( node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->val );
        temp->link =NULL;
        if(Tete==NULL)
        {
                Tete=temp;
        }
        else
        {
                ptr=Tete;
                while(ptr->link !=NULL)
                {
                        ptr=ptr->link ;
                }
                ptr->link =temp;
        }
}
//Deletion de node
void delete_pos(node *Tete,int pos)
{
        int i;
        struct node *temp,*ptr;
        if(Tete==NULL)
        {
                printf("\nLa liste est vide:\n");
                exit(0);
        }
        else
        {

                if(pos==0)
                {
                        ptr=Tete;
                        Tete=Tete->link ;
                        printf("L'element a supprimer est:%d\t",ptr->val  );
                        free(ptr);
                }
                else
                {
                        ptr=Tete;
                        for(i=1;i<pos;i++) {
                                temp=ptr; ptr=ptr->link ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition est introvable:\n");
                                        return;
                                }
                        }
                        temp->link =ptr->link ;
                        printf("l'element supprimer est:%d\t",ptr->val );
                        free(ptr);
                }
        }
}


//Tri par bulle
//swap fonction
 node* swap(node* ptr1,node* ptr2)
{
    node* tmp = ptr2->link;
    ptr2->link = ptr1;
    ptr1->link = tmp;
    return ptr2;
}

//fonction de tri

int bulle_tri(node** head, int count)
{
    struct node** h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            node* p1 = *h;
            node* p2 = p1->link;

            if (p1->val > p2->val)
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->link;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}
//deletion de debut
void delete_debut()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
                ptr=Tete;
                Tete=Tete->link ;
                printf("\nThe deleted element is :%d\t",ptr->val);
                free(ptr);
        }
}
//deletion a fin
void delete_fin()
{
        struct node *temp,*ptr;
        if(Tete==NULL)
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(Tete->link ==NULL)
        {
                ptr=Tete;
                Tete=NULL;
                printf("\nThe deleted element is:%d\t",ptr->val);
                free(ptr);
        }
        else
        {
                ptr=Tete;
                while(ptr->link!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->link;
                }
                temp->link=NULL;
                printf("\nThe deleted element is:%d\t",ptr->val);
                free(ptr);
        }
}
int max_list(){
struct node *temp,*ptr;
node * P=Tete;
int x=0,pos=0,pos_1=0;
    while(P!=NULL)
    {
       if((P->val)>x){
       x=(P->val);
       pos_1=pos+1;
       }else{
       P=P->link;
       pos=pos+1;
       }

    }
//delete_pos(Tete,pos);
//printf("Le nombre max %d \n",x);
//printf("Le nombre  %d ",ptr->val);
   //printf("IF %d\n",x);
alt=x;
return pos_1;

}
int recha_val(node *tot,int pos){
int i=1;
while(i<pos){
    tot=tot->link;
    i=i+1;
}
return tot->val;
}
//tri par supression
node* tri_list(){
node *P,*ptr,*temp,*tat=Tete;
int x=0,pos=1,i;
Tet1=NULL;
i=0;
while(tat!=NULL){
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL)
         printf("NULL\n");
    pos=max_list();
    x=recha_val(Tete,pos);
    deleteN(&Tete,pos);
    ptr->val=x;
if(P == NULL){
P=ptr;
Tet1=ptr;
    printf("IF\n");

}else{
    P->link=ptr;
    P=P->link;
    printf("Else\n");

}

}

return Tet1;
}

void deleteN(node** head, int position)
{
    node* temp;
    node* prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->link;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->link = temp->link;
                free(temp);
            }
            else {
                prev = temp;

                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->link;
            }
        }
    }
}
int main()
{
    node *HEAD=NULL,*P=NULL,*TEMP=NULL;
    int n,x,d,pos;

     int choice;
        while(1){

                printf("\n                MENU                             \n");
                printf("\n 1.Cree un liste     \n");
                printf("\n 2.afficher la liste    \n");
                printf("\n 3.Rechercher un element   \n");
                printf("\n 4.Inserer un element   \n");
                printf("\n 5.supprimer un element    \n");
                printf("\n 6.Trier la liste en utiliser Bulle       \n");
                printf("\n 7.Trier la liste en utiliser La deletion       \n");
                printf("\n 8.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                               printf("Voulez vous entrer la taille de list : ");
                               scanf("%d",&n);
                               Tete=creation(n);
                                        break;
                        case 2:
                                        printf("\n");
                                        display(Tete);
                                        break;
                        case 3:
                               printf("\nEntrer l'element a rechercher");
                               scanf("%d",&x);
                               if(reche(x,Tete)==true)
                               printf("L'element est trouve\n");
                               else
                               printf("L'element ne trouve pas\n");
                                        break;
                        case 4:
                               system("cls");
                               printf("\n1.inserer a le debut\n");
                               printf("\n2.inserer a certain position\n");
                               printf("\n3.inserer a la fin\n");
                               scanf("%d",&choice);
                               switch(choice){
                                case 1:
                                    insert_debut();
                                    break;
                                case 2:
                                    temp=(node*)malloc(sizeof(node));
                                    temp->link=NULL;
                                    printf("entrer la position a inserer:");
                                    scanf("%d",&d);
                                    insert(temp,Tete,d);
                                        break;

                                case 3:
                                    insert_fin();
                                    break;


                                        }
                                        break;


                        case 5:
                               system("cls");
                               printf("\n1.supprimer a le debut\n");
                               printf("\n2.supprimer a certain position\n");
                               printf("\n3.supprimer a la fin\n");
                               scanf("%d",&choice);
                               switch(choice){
                           case 1:
                            delete_debut();
                            break;
                           case 2:

                printf("\nEntrer la position de node a supprimer:\t");
                scanf("%d",&pos);
                deleteN(&Tete,pos);
                            //delete_pos(Tete,pos);
                            break;
                           case 3:
                            delete_fin();
                            break;


                               }
                               break;


                        case 6:
                                        bulle_tri(&Tete,n);
                                        printf("La liste est trier entrer 2 pour afficher la list");
                                        break;
                        case 7:
                                            //Tet1=(node*)malloc(sizeof(node));
                                            //ink=Tet1;

for(int i=0;i<n;i++){

    TEMP=(node*)malloc(sizeof(node));
    pos=max_list();
    x=recha_val(Tete,pos);
    //printf("RoZA %d\n",x);
    //printf("amores %d\n",pos);
    if(TEMP==NULL)
        printf("NULLLLL\n");
    TEMP->val=x;
    TEMP->link=NULL;
    deleteN(&Tete,pos);
    if(Tet1==NULL){
        Tet1=TEMP;
    }else{

    P=Tet1;
    while(P->link != NULL){
        P = P->link;
        // printf("////%d////\n",1);
    }//Loop
    P->link=TEMP;

    }//else

    //printf("IF /////****//////\n");

}
                                            /*while(Tete!=NULL){
                                                pos=max_list();
                                                x=recha_val(Tete,pos);
                                                push(Tet1,x);


                                            }*/





                                            //Tet1=tri_list();
                                            //printf("jj %d \t %d\n",pos,recha_val(Tete,pos));
                                            //
                                            //Tet1=HEAD;
                                            display(Tet1);
                                        break;
                        case 8:
                                        exit(0);
                                        break;
                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }
        }


    //creer La liste chainee

    //afficher La liste chainee

    //rechercher un element

    //inserer un element a certain position

    // afficher un lsite chainee

    //supprimer un element de certain position

    //afficher La liste chainee


    return 0;
}
