class MyCircularQueue {

  // Things to note:
  // Can use nested ifelse statements by doing the quick return
  // Can use the construcution quick setters inline in the contructor
  // Think dynamiccally about it being a right queue instead with a vector in
  // c++ rather than a array type of more complex linked list
private:
  vector<int> queue;
  int capacity;
  int headIndex;
  int count;

public:
  MyCircularQueue(int k) : queue(k, 0), headIndex(0), count(0), capacity(k) {}

  bool enQueue(int value) {
    if (count == capacity) {
      return false;
    } else {
      queue[(headIndex + count) % capacity] = value;
      count++;
      return true;
    }
  }

  bool deQueue() {
    if (count == 0) {
      return false;

    } else {
      headIndex = (headIndex + 1) % capacity;
      count--;
      return true;
    }
  }

  int Front() { return (count == 0) ? -1 : queue[headIndex]; }

  int Rear() {
    return (count == 0) ? -1 : queue[(headIndex + count - 1) % capacity];
  }

  bool isEmpty() { return count = 0; }

  bool isFull() { return count == capacity; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */