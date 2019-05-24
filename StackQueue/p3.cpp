// Huy Vu
// p3.cpp
// Purpose:  Testing the functions of stack and queue package
// Input:
// The stack package provide methods for a dynamic array implementation
// of a stack of integers.
// The queue package provide methods for a linked list implementation
// of a queue of integers.
// Process: Push, pop, enqueue and dequeue data.
// Output: Print the data that were pushed, popped, enqueued and dequeue.

#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

// welcome message
void welcome();

// goodbye message
void goodbye();

// tests all stack package methods
void testStack();

// tests all queue package methods
void testQueue();

int main()
{
  welcome();
  
  cout << "Testing Stack operations...." << endl << endl;
  testStack();
  cout << "Press Enter to continue with the queue test";
  cin.ignore();
  cout << "Testing Queue operations...." << endl;
  testQueue();

  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl << endl;
  cout << "~~~~~~Welcome to Stack and Queue Test~~~~~~" << endl;
  cout << endl << endl << endl;
  cout << "This program show how stack and queue works." << endl;
  cout << "Stack will be implemented by using dynamic array." << endl;
  cout << "The default size of stack is 50 but it will be resized" << endl;
  cout << "if the stack doesn't have enough space for data" << endl;
  cout << "Queue will be implemented by using linked list." << endl;
  cout << "The size of queue is not limited." << endl;
  cout << "Here is the Stack and Queue Test." << endl << endl;
}

void goodbye()
{
  cout << endl << endl;
  cout << "~~~~~~Good bye!~~~~~~" << endl;
  cout << endl << endl;
}

void testStack()
{
  int num;
  // constructor
  Stack s1;
  // constructor with size
  Stack s2(3);

  cout << "There are 3 stacks in this test:" << endl;
  cout << "s1: default stack with size 50" << endl;
  cout << "s2: stack with size 3" << endl;
  cout << "s3: copied stack from dafault stack" << endl;
  
  // push
  cout << endl;
  cout << "Let push some values to s1" << endl;
  cout << "Here, pushing 4 values onto stack of size 50" << endl;
  for (int i = 0; i < 4; i++){
	if (!s1.push(i))
	  cout << "Sorry, could not push " << i << " onto stack" << endl;
	else
	  cout << "Successful push of " << i << endl;
  }

  // copy constructor
  cout << "Now let make a copy of stack 's1' into new instance 's3'" << endl;
  Stack s3(s1);
  
  // pop & isEmpty
  cout << "Now popping all values from original stack 's1'" << endl;
  while (!s1.isEmpty()){
	if (!s1.pop(num))
	  cout << "Could not pop from 's1'" << endl;
	else
	  cout << "Popped " << num << " from 's1'" << endl;
  }
  cout << "And also  popping all values from copied stack 's3'" << endl;
  while (!s3.isEmpty()){
	if (!s3.pop(num))
	  cout << "Could not pop from 's3'" << endl;
	else
	  cout << "Popped " << num << " from 's3'" << endl;
  }

  // resize
  cout << "Checking if the program resize stack s2 if put more than 3 value";
  cout << endl;
  cout << "Let pushing 5 values onto stack of size 3" << endl;
  for (int i = 0; i < 5; i++){
	if (!s2.push(i))
	  cout << "Sorry, could not push " << i << " onto stack" << endl;
	else
	  cout << "Pushed " << i << " onto stack" << endl;
  }

  // assignment operator
  cout << "Now copying 's2' into 's1'" << endl;
  s1 = s2;
  cout << "Then popping all of 's2'" << endl;
  while (!s2.isEmpty()){
	s2.pop(num);
	cout << "Popped " << num << " from 's2'" << endl;
  }
  cout << "Now popping all of 's1'" << endl;
  while (!s1.isEmpty()){
	s1.pop(num);
	cout << "Popped " << num << " from 's1'" << endl;
  }

}

void testQueue()
{
  int num;
  // constructor
  Queue q1, q3;
  cout << endl;
  cout << "There are 3 queues in this test:" << endl;
  cout << "q1:  default queue." << endl;
  cout << "q2:  copied queue of 'q1'." << endl;
  cout << "q3:  copied queue of 'q2'." << endl;
  
  // enqueue
  cout << endl;
  cout << "Let add 5 items to queue...." << endl;
  for (int i = 3; i < 8; i++){
	if (!q1.enqueue(i))
	  cout << "Could not add to 'q1'" << endl;
	else
	  cout << "Added " << i << " to 'q1'" << endl;
  }

  // copy constructor
  cout << "Making a copy of 'q1' into 'q2'(using copy constructor)" << endl;
  Queue q2(q1);
  cout << "Now emptying 'q1'" << endl;
  // dequeue & isEmpty
  while (!q1.isEmpty()){
	if (!q1.dequeue(num))
	  cout << "Could not dequeue from 'q1'" << endl;
	else
	  cout << "Removed " << num << " from 'q1'" << endl;
  }
  
  // assignment operator
  cout << "Copying 'q2' into 'q3' (using assignment operator)" << endl;
  q3 = q2;
  cout << "Now removing all values from 'q2'" << endl;
  while (!q2.isEmpty()){
	if (!q2.dequeue(num))
	  cout << "Could not dequeue from 'q2'" << endl;
	else
	  cout << "Removed " << num << " from 'q2'" << endl;
  }

  cout << "Now removing all values from 'q3'" << endl;
  while (!q3.isEmpty()){
	if (!q3.dequeue(num))
	  cout << "Could not dequeue from 'q3'" << endl;
	else
	  cout << "Removed " << num << " from 'q3'" << endl;
  }
}
  
