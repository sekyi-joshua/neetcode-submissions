struct Node 
{
    int value = 0;
    Node* next = nullptr;
};

class LinkedList {
public:
    LinkedList() {
    }

    Node* getNodeFromIndex(int index)
    {
        Node* current = head;

        while(index-- > 0)
        {
             current = current->next;
        }

        return current;
    }

    void p()
    {
        puts("-----\n");
        for(auto x :  getValues())
        {
            printf("%d, ", x);
        }
        printf("\n-----S: %d\n", size);
        printf("+ %d + \n", get(size - 1));
    }

    int get(int index) {
        if(index >= size)
        {
            return -1;
        }

        return getNodeFromIndex(index)->value;
    }

    void insertHead(int val) {
        Node* newNode = new Node();

        newNode->value = val;
        newNode->next = head;

        head = newNode;
        size++;
    }
    
    void insertTail(int val) {
        Node* tail = getNodeFromIndex(size - 1);

        Node* newNode = new Node();

        newNode->value = val;
        
        if(tail == nullptr)
        {
            head = newNode;
        } else 
        {
            tail->next = newNode;
        }

        size++;
    }

    bool remove(int index) {
        if(index >= size)
        {
            return false;
        }

        Node* node = head;
        Node* nodePrev = head;

        for(int i = 0; i < index; i++)
        {
            nodePrev = node;
            node = node->next;
        }

        if(node == head)
        {
            head = head->next;
            delete node;
            size--;
            return true;
        }

        // Previous node (node) must link to nodeTwo next
        nodePrev->next = node->next;

        delete node;
        size--;

        return true;
    }

    vector<int> getValues() {
        vector<int> vec;

        Node* current = head;
        while(current != nullptr)
        {
            vec.push_back(current->value);
            current = current->next;
        }

        return vec;
    }

private:
    Node* head = nullptr;
    int size = 0;
};

