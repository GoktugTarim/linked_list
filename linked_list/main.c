#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
}node_a;

node_a *insert(node_a *head,node_a *insert_node)
{

    insert_node->next=head;
    return insert_node;
}

void printlist (node_a *head)
{
    node_a *temporary = head;
     while (temporary != NULL)
     {
         printf("%d->",temporary ->value);
         temporary = temporary ->next;
     }
     if(temporary ==NULL)
     {
         printf("null.");
     }
    printf("\n");
}


node_a *create(int value)
{
    node_a *result=malloc(sizeof(node_a));
    result->value=value;
    result->next=NULL;
    return result;

}

node_a *find_node (node_a *head,int value)
{
    node_a *temp=head;

    while(temp!=NULL)
    {
        if(temp->value == value)
        {
            printf("sayi bulundu.\n");
            return temp;
        }
        temp=temp->next;

    }
    return printf("sayi bulunamadi.\n");
}

node_a *deleting(node_a *head , int value)
{
    node_a *temp=head;
    node_a *temp2;

    /*if(temp->next ==NULL)
    {
        return
    }*/

    while(temp->next->value != value && temp->next != NULL)
    {
        temp=temp->next;
    }


    temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);



}


int main()
{
    int sayi,sayi2,sayi3;
    node_a *head=NULL;
    node_a *temp;

    printf("kac eleman eklemek istersiniz: ");
    scanf("%d",&sayi);

    for(int i=0;i<sayi;i++)
    {
        int sayii;
        printf("sayiyi girin: ");
        scanf("%d",&sayii);
        temp=create(sayii);
        head=insert(head,temp);
    }

    printlist(head);

    printf("bulmak istediginiz sayi nedir: \n");
    scanf("%d",&sayi2);
    find_node(head,sayi2);

    printf("silmek istediginiz sayi nedir: ");
    scanf("%d",&sayi3);
    deleting(head,sayi3);

    printlist(head);

    return 0;
}
