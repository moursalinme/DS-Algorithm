template <class T> 
class Queue {
    int n, siz, head, tail;
    T *arr = NULL;
    
public :
    Queue () = default;

    Queue (int t)  {
        arr = new T[t];
        n = t;
        siz = head = tail = 0;
    }

    void set_size (int t) {
        n = t;
        head = tail = siz = 0;
        
        if (arr != NULL) 
            free (arr);
        arr = new T[t];
    }

    int size () {
        return siz;
    }

    void enqueue (T data) {
        if (siz == n) 
            cout << "Overflow\n";
        else {
            arr[tail] = data;
            tail = (tail + 1) % n;
            ++siz;
        }
    }

    void dequeue() {
        if (siz) {
            head = (head + 1) % n;
            --siz;
        }
        else cout << "Underflow\n";
    }

    T front () {
        assert (siz);
        return arr[head];
    }

    ~Queue () {
        free (arr);
    }
};
