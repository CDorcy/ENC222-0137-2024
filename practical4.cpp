 // //ENC222-0137/2024
 #include <iostream>
const int MAX_SIZE = 5;
int queueArray[MAX_SIZE];
int FRONT = -1;
int REAR = -1;

bool IsFull() {
    if ((REAR + 1) % MAX_SIZE == FRONT) {
        return true;
    } else {
        return false;
    }
}

bool IsEmpty() {
    if (FRONT == -1) {
        return true;
    } else {
        return false;
    }
}

void Enqueue(int value) {
    if (IsFull()) {
        std::cout << "Error: Queue is full." << std::endl;
        return;
    }

    if (IsEmpty()) {
        FRONT = 0;
        REAR = 0;
    } else {
        REAR = (REAR + 1) % MAX_SIZE;
    }
    
    queueArray[REAR] = value;
    std::cout << value << " added to the queue." << std::endl;
}

int Dequeue() {
    if (IsEmpty()) {
        std::cout << "Error: Queue is empty." << std::endl;
        return -9999; // Return an error value
    }
    
    int dequeuedValue = queueArray[FRONT];
    
    if (FRONT == REAR) {
        FRONT = -1;
        REAR = -1;
    } else {
        FRONT = (FRONT + 1) % MAX_SIZE;
    }
    
    return dequeuedValue;
}

void DisplayQueue() {
    if (IsEmpty()) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    
    int i = FRONT;
    std::cout << "Queue elements: ";
    
    while (i != REAR) {
        std::cout << queueArray[i] << " ";
        i = (i + 1) % MAX_SIZE;
    }
    
    std::cout << queueArray[REAR] << std::endl;
}

int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    DisplayQueue();

    int dequeued = Dequeue();
    std::cout << "Dequeued value: " << dequeued << std::endl;
    DisplayQueue();

    Enqueue(40);
    Enqueue(50);
    Enqueue(60); // This will show the "Queue is full" error

    DisplayQueue();

    return 0;
}
