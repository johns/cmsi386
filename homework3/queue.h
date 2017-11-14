#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
class Queue {

  struct Node {
    T data;
    Node* next;
  };

  int size = 0;
  Node* head = nullptr;
  Node* tail = nullptr;

  Node* copy(Node* n) {
    return new Node {n->data, n->next ? copy(n->next) : nullptr};
  }

public:

  ~Queue() {
    while (head != nullptr) {
      dequeue();
    }
  }

  Queue() = default;

  Queue(const Queue& s) = delete;
  Queue& operator=(const Queue& s) = delete;

  Queue(Queue&& s): size(s.size), head(s.head), tail(s.tail) {
    s.head = nullptr;
    s.tail = nullptr;
    s.size = 0;
  }

  Queue& operator=(Queue&& s) {
    if (&s != this) {
      size = s.size;
      head = s.head;
      tail = s.tail;
      s.head = nullptr;
      s.tail = nullptr;
      s.size = 0;
    }
    return *this;
  }

  int get_size() {
    return size;
  }

  T get_head() {
    return head->data;
  }

  T get_tail() {
    return tail->data;
  }

  void enqueue(T x) {
    Node *temp = new Node {x, nullptr};
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    size++;
  }

  T dequeue() {
    if (size == 0) {
      throw std::underflow_error("Cannot dequeue from an empty Queue.");
    }
    Node* nodeToDelete = head;
    T valueToReturn = head->data;
    head = head->next;
    size--;
    delete nodeToDelete;
    return valueToReturn;
  }
};

// Queue<int> oneTwoThree() {
//   Queue<int> z;
//   z.enqueue(3);
//   z.enqueue(2);
//   z.enqueue(1);
//   return z;
// }

// int main() {
//   Queue<int> s;
//   assert(s.get_size() == 0);
//   s.enqueue(100);
//   assert(s.get_head() == 100);
//   assert(s.get_size() == 1);
//   s.enqueue(200);
//   assert(s.get_head() == 100);
//   assert(s.get_tail() == 200);
//   assert(s.get_size() == 2);
//   assert(s.dequeue() == 100);
//   assert(s.get_size() == 1);
//   assert(s.dequeue() == 200);
//   assert(s.get_size() == 0);
//   s.enqueue(300);
//   s.enqueue(400);

//   Queue<int> t = oneTwoThree();
//   assert(t.get_size() == 3);
//   assert(t.get_head() == 3);
//   assert(t.get_tail() == 1);
//   s.dequeue();
  
//   cout << "All tests passed\n";
// }
