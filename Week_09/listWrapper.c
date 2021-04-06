//#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char rollNo[20];
	char emailId[35];
	char lecture[3];
	char tutorial[3];
	char practical[3];
	struct student*left;
	struct student*right;
};
//This function allocates memory for a new node using malloc, receives the starting address in variable ptr and fills in the data from buffer, to the memory pointed by ptr
struct student*createNode(struct student buffer)
{
	struct student*ptr=(struct student*)malloc(sizeof(struct student));

	strcpy(ptr->rollNo,buffer.rollNo);
	strcpy(ptr->emailId,buffer.emailId);
	strcpy(ptr->lecture,buffer.lecture);
	strcpy(ptr->tutorial,buffer.tutorial);
	strcpy(ptr->practical,buffer.practical);	

	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}

int checkDuplicate(struct student** startPtr, struct student** temp)
{
	struct student* tmp = *startPtr;

	while(tmp!=NULL){
		if(strcmp(tmp->rollNo,temp->rollNo) == 0)
		{
			return 0;
		}

		if (strcmp(tmp->rollNo, temp->rollNo) > 0){
			tmp = tmp->right;
		}

		if (strcmp(tmp->rollNo, temp->rollNo) < 0)
		{
			tmp = tmp->left;
		}
	}

	return 1;
}

//This function inserts a node with pointer temp to the BST. The function checks whether a node with the same the roll number is already present in the BST (whose starting address is in *startPtr) or not. If not, the function inserts the node into the BST and returns 1 on successful insertion.  If there is already a record with the same roll number, the function returns 0. Note that if in case the node that you are inserting is the first, then you have to update the treeHead variable (a local variable in main) and that justifies the function being invoked with a reference to it (&treeHead)  
int insertNode(struct student**startPtr,struct student*temp)
{
	struct student* tmp = *startPtr;

	if(strcmp(tmp->rollNo,temp->rollNo) == 0)
	{
		return 0;
	}

	if (strcmp(tmp->rollNo, temp->rollNo) > 0){
		if(tmp->right!=NULL)
		{
			tmp = tmp->right;
		}
		else 
		{
			insert( &(tmp->right), temp);
		}
	}

	else if (strcmp(tmp->rollNo, temp->rollNo) < 0)
	{
		if(tmp->left!=NULL)
		{
			tmp = tmp->left;
		}
		else 
		{
			insert( &(tmp->left), temp);
		}
	}
}
//This function looks for a node with a specific roll number in the BST and deletes it if its present and returns 1 on successful deletion and 0 otherwise. Note that if in case the node that you are deleting is the first, then you have to update the treeHead variable (a local variable in main) and that justifies the function being invoked with a reference to it (&treeHead)  
int deleteNode(struct student**ptr,char rollNumber[20])
{

}
//This function takes the address of the root node of the BST and a roll number as input and checks whether there is a corresponding record  in the BST or not. If yes, the function return the height of the node in the BST (root has height 1, and otherwise height of a node is it's parent's height plus 1) and returns 0 otherwise. You could keep a counter and every time you take one step down over the tree, you may increment the count by 1
int searchNode(struct student*ptr,char rollNumber[20])
{

}

//This function takes the address of the root node in the BST as input and prints the roll number and email Id of each student in the BST, sorted in descending order of the roll number (use a variant of inorder traversal).To end with, the function returns the number of nodes in the BST. You may introduce your own global variable and increment it everytime a new value being printed
int displayBST(struct student*start)
{	

}


int main()
{
	FILE*fp1;
	FILE*fp2;
	int i,j;
	int val;
	int op;
	int hit;
	int status;
	struct student buffer;
	struct student*nodeCopy;
	struct student*treeHead=NULL;
	fp1=fopen("testCaseForBST.txt","r");
	fp2=fopen("testResult.txt","w");	
	if(fp1==NULL){printf("\nFile read error\n");exit(0);}
	for(i=0;i<138;i++)
	{
		fscanf(fp1,"%d",&op);
	
		if(op==1)//insert
		{
			fscanf(fp1,"%s",buffer.rollNo);
			fscanf(fp1,"%s",buffer.emailId);
			fscanf(fp1,"%s",buffer.lecture);
			fscanf(fp1,"%s",buffer.tutorial);
			fscanf(fp1,"%s",buffer.practical);
/*
			printf("%s ",buffer.rollNo);
			printf("%s ",buffer.emailId);
			printf("%s ",buffer.lecture);
			printf("%s ",buffer.tutorial);
			printf("%s\n",buffer.practical);
*/
			nodeCopy=createNode(buffer);
			status=insertNode(&treeHead,nodeCopy);
			if(status==0)//failed to insert
			{	
				fprintf(fp2,"Insertion failed: Duplicate entry for %s\n",nodeCopy->rollNo);
				free(nodeCopy);
			}
			else
				fprintf(fp2,"Details for %s successfully inserted\n",nodeCopy->rollNo);

		}
		else
		{	//hit=1 --> value is present in the BST and 0 otherwise
			fscanf(fp1,"%d %s",&hit,buffer.rollNo);	
			if((op==2)&&(deleteNode(&treeHead,buffer.rollNo)!=hit))
			{
				printf("\nThere is an error in delete function\n");
				exit(0);
			}
			else if(op==2) //corresponds to deletion
			{
				if(hit==0)
					fprintf(fp2,"Deletion Failed: %s not present in BST\n",buffer.rollNo);
				else
					fprintf(fp2,"Deletion successfull %s successfully removed\n",buffer.rollNo);

			}
			if(op==3)//corresponds to search, comment this if block if you want to test your deletion alone
			{
				int index=searchNode(treeHead,buffer.rollNo);
				if(((hit==0) && (index!=0))||((hit!=0)&&(index==0)))
				{	
					printf("\nThere is an error in search function\n");
					exit(0);
				}
				else if(hit==0)
					fprintf(fp2,"%s not present in BST\n",buffer.rollNo);
				else
					fprintf(fp2,"%s present at location %d\n",buffer.rollNo,index);

			}
			
		}
	}
	int count=displayBST(treeHead);
	printf("\nTotal count=%d\n",count);

	fclose(fp1);	
	fclose(fp2);
}



