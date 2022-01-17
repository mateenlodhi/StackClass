#include <iostream>

template <typename T>
class Stack
{
public:
    Stack()
    {
        capacity = DEFAULT_CAPACITY;
        arr = new T[capacity];
        top = -1;
    }

    Stack(const Stack &other)
    {
        capacity = other.capacity;
        top = other.top;

        arr = new T[capacity];

        for (int i = 0; i <= other.top; ++i)
        {
            arr[i] = other.arr[i];
        }
    }

    Stack(int size)
    {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    // adds element to the top of the stack.
    // It should return true, if the element has been successfully pushed.
    // So as long as you do not provide an extend() method,
    // you need to check for available space
    // and return false if there is no more space.
    bool push(T element)
    {
        if (top == capacity - 1)
        {
            return false;
        }

        arr[++top] = element;
        return true;
    }

    // pops an element from the top of the stack. The element is put into out.
    // It should not crash if there are no elements on the stack,
    // but rather return false, otherwise it should return true.
    bool pop(T &out)
    {
        // check for stack underflow
        if (top == -1)
        {
            return false;
        }

        out = arr[top];

        // decrease stack size by 1
        --top;

        return true;
    }

    // returns the data on the top of the stack, without changing the stack.
    T back(void)
    {
        if (top == -1)
        {
            return NULL;
        }
        return arr[top];
    }

    // returns the number of entries of the stack at a given moment.
    int getNumEntries()
    {
        return top + 1;
    }

    // Destructor for the template class.
    ~Stack()
    {
        delete arr;
    }

private:
    T *arr;
    int top;
    int capacity;

    static const int DEFAULT_CAPACITY = 10;
};

using namespace std;

int main()
{
    // Stack using default constructor
    Stack<int> stack1;
    cout << "\nStack1 created using default constructor!";

    cout << "\nNumber of entries in stack1: " << stack1.getNumEntries() << endl;

    bool success = false;

    for (int i = 0; i < 12; ++i)
    {
        cout << "\n-> stack1: Pushing " << i + 1 << ": ";
        success = stack1.push(i + 1);
        cout << (success ? "Pushed!" : "Failed!");
    }

    cout << "\n\nNumber of entries in stack1: " << stack1.getNumEntries() << endl;

    // Stack using copy constructor
    Stack<int> stack2(stack1);
    cout << "\nStack2 created using copy constructor using stack1!";

    cout << "\nNumber of entries in stack2: " << stack2.getNumEntries() << endl;

    int val;

    for (int i = 0; i < 12; ++i)
    {
        cout << "\n-> stack1: Popping: ";
        success = stack1.pop(val);
        cout << (success ? (to_string(val) + " Popped!") : "Failed!");
    }

    cout << "\n\nNumber of entries in stack1: " << stack1.getNumEntries() << endl;

    return 0;
}
