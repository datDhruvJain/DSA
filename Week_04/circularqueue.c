#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>

int*linear_queue;
int linear_queue_size;
int*circular_queue;
int circular_queue_size;
int opCode;
int frontL=0, rearL=0;
int frontC=0, rearC=0;
int isLinearQueueEmpty()
{
	if (rearL==0) return 1;
	else return 0;
}
int isLinearQueueFull()
{
	if (rearL == linear_queue_size-1) return 1;
	else return 0;
}
int linearEnqueue(int x)
{
	if(!isCircularQueueFull()){
		linear_queue[rearL] = x;
		rearL++;
		return 1;
	}
	else return -1;
}

int linearDequeue()
{
	if(!isCircularQueueEmpty()){
		linear_queue[frontL++];
	}
	else return -1;
}

int isCircularQueueEmpty()
{
	if (frontC == rearC){
		return 1;
	}
	else return 0;
}
int isCircularQueueFull()
{
	if ((circular_queue_size - frontC + rearC) % circular_queue_size == circular_queue_size - 1) return 1;
	else return 0;
}
int circularEnqueue(int x)
{
	if (!isCircularQueueFull()){
		circular_queue[rearC] == x;
		rearC++;
		return 1;
	}

	else return -1;
}

int circularDequeue()
{
	if (!isCircularQueueEmpty()){
		int temp = circular_queue[frontC];
		frontC =  (frontC+1)%circular_queue_size;
	}
}


int main()
{
	FILE*fp1;
	FILE*fp2;
	FILE*fp3;
	int i,j;
	int x,val;


	fp1=fopen("SearchTestcase.txt","r");	
	fp2=fopen("linear_QCount.txt","w");
	fp3=fopen("circular_QCount.txt","w");


	for(i=0;i<10;i++)
	{
		int size;	
		fscanf(fp1,"%d",&size);
		linear_queue_size=(int)(0.5*size);
		linear_queue=(int*)calloc(sizeof(int), linear_queue_size); //have a queue of reasonable size for each test case
		circular_queue_size=(int)(0.5*size);
		circular_queue=(int*)calloc(sizeof(int), linear_queue_size); //have a queue of reasonable size for each test case

		int linear_Q_Count=0; //counts the number of successful enque/deque operations in the linear version
		int circular_Q_Count=0;//counts the number of successful enque/deque operations in the circular version

		int status;
		for(j=0;j<size;j++)
		{

			fscanf(fp1,"%d",&opCode);
			if (opCode==1)//wants to enqueue
			{	x=rand()%10000;	//generate the random value to be enqueued		
				status=linearEnqueue(x);			
			
				if(status==-1)//queue full
				{
//					printf("\n Enqueuing %d failed, queue full",x);
				}
				else 
				{
					linear_Q_Count++;
				}


				status=circularEnqueue(x);			
			
				if(status==-1)//queue full
				{
//					printf("\n Enqueuing %d failed, queue full",x);
				}
				else 
				{
					circular_Q_Count++;
				}
			}
			else
			{				
				status=linearDequeue(x);			
			
				if(status==-1)//queue empty
				{
//					printf("\n DeQueuing failed, queue empty");
				}
				else
				{
					linear_Q_Count++;
				}

				status=circularDequeue(x);			
			
				if(status==-1)//queue empty
				{
//					printf("\n DeQueuing failed, queue empty");
				}
				else
				{
					circular_Q_Count++;
				}

			}
		}
		fprintf(fp2,"%d\n", linear_Q_Count); //write average computation time for a test case
		fprintf(fp3,"%d\n", circular_Q_Count); //write average computation time for a test case
	}
	fclose(fp1);
	fclose(fp2); 
	fclose(fp3); 
}



