/* 
 * what you have to do
 * create a circularqueue for keeping a record of all the positive integers
 * eg 2,3, 4,5,(from 2) 6,7 from(3)
 * */

#include<iostream>
using namespace std;

struct Queue
{
	// Initialize front and rear
	int rear, front;

	// Circular Queue
	int size;
	int *arr;

	Queue(int s)
	{
	front = rear = -1;
	size = s;
	arr = new int[s];
	}

	void enQueue(int value);
	int deQueue();
	void displayQueue();
};


/* Function to create Circular queue */
void Queue::enQueue(int value)
{
	if ((front == 0 && rear == size-1) ||
			(rear == (front-1)%(size-1)))
	{
		printf("\nQueue is Full");
		return;
	}

	else if (front == -1) /* Insert First Element */
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size-1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ",arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
}

int main(){

	Queue q(10);
	Queue rq(10);

	int tstar[] =  {0,  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int tstarr[] = {-1,-1,1,0,1,0,0,0,9,0,0, 0, 0, 0, 0, 0, 1};
	int size = sizeof(tstarr)/sizeof(int);

	// add every element that satisfies the condition, either i*2 satisfies, or (i*2)+1 satisfies, or both satisfy

	int i=2;
	while (i<size/2){
		if (tstarr[i]>0){
			rq.enQueue(i);
			if (tstarr[2*i] > 0){
				q.enQueue(2*i);
			}

			if (tstarr[2*i +1] > 0){
				q.enQueue(2*i + 1);
			}
			if (q.size != 0){
				i = q.deQueue();
			}
		}
	} 
	rq.enQueue(i);
	if(tstarr[i*2]!=0){
		rq.enQueue(i*2);
	}
	if (tstarr[i*2 + 1] != 0){
		rq.enQueue(i+2 + 1);
	}
	rq.displayQueue();

}

