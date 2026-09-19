class DynamicArray {
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        buffer = new int[capacity];
    }

    int get(int i) {
        return buffer[i];
    }

    void set(int i, int n) {
        buffer[i] = n;
    }

    void pushback(int n) {
        if(size + 1 > capacity)
        {
            resize();
        }

        buffer[size++] = n;
    }

    int popback() {
        size--;
        return buffer[size];
    }

    void resize() {
        capacity *= 2;
        int* newBuffer = new int[capacity];
        for(int i = 0; i < size; i++)
        {
            newBuffer[i] = buffer[i];
        }

        buffer = newBuffer;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

private:
int* buffer = nullptr;
int size = 0;
int capacity = 0;
};
