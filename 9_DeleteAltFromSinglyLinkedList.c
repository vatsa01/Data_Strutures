#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int data;
	struct node* next;
}node;
node *head=NULL,*temp,*ptr;
int n;
node *temp=NULL;
node *ptr=NULL;

void insert_end()
{

		temp=(node*)malloc(sizeof(node));
		printf("\n Enter the data ");
		scanf("%d", &(temp->data));
		temp->next=NULL;

		if (head==NULL)
		{
			head=temp;
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;

			}
			ptr->next=temp;

		}

}


void del_end()
{	if (head==NULL)
	{
		printf("the list is empty");
	}
	else if(head->next == NULL)
	{   free(head);
	    head = NULL;
	}
	else
	{
		ptr=head;
		while (ptr->next!=NULL)
		{
			temp=ptr;
			ptr= ptr->next;

		}
		temp->next=NULL;
		free(ptr);
	}
}

void display()
{
	if (head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		ptr=head;
		while (ptr!=NULL)
		{
			printf("\t %d --> ",ptr->data);
			ptr=ptr->next;

		}
	}
}

void delete_alt()
{
  node *ptr = head->next,*prev = head,*temp = NULL;
  while(ptr!=NULL)
  {
    prev->next = ptr->next;
    temp = ptr;
    if(ptr->next == NULL)
        ptr = ptr->next;
    else
        ptr = ptr->next->next;

    prev = prev->next;
    free(temp);
  }
}

void main()
{
	int ch;

	while (1)
	{
		printf("\n Menu \n 1. Insert_end   \n 2. Delete_end  \n 3. Delete_alt \n 4. Display");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_end();
				break;
			case 2: del_end();
				break;
			case 3: delete_alt();
				break;
			case 4: display();
				break;

		}
	}
}
