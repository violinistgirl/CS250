#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    float balance = 0.0;
    // Create a queue of floats, named transactions
	queue<float> transactions;

    // Push some + and - floats into the transactions queue.
	transactions.push(5.23);
	transactions.push(-3);
	transactions.push(20.99);
	transactions.push(-5.99);
    
    // Loop through all the transactions - while the queue is empty.
    // Within the loop, whatever amount is at the front of the queue,
    // add it to the balance and then pop it off the queue.

	while (!transactions.empty()) {
		balance += transactions.front();
		transactions.pop();
	}

    cout << "Final balance: $" << balance << endl;
    
    return 0;
}
