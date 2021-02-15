template <typename T>
struct Node {
    T data;
    Node *next = NULL;
};

template <class T>
class Linked_list {
    Node<T> *root = NULL, *last = NULL;
    int siz = 0;
public:

    Linked_list () = default;

    int size () {
        return siz;
    }

    void add (T value) {
        if (root) {
            Node<T> *temp = new Node<T> ();
            temp-> data = value;
            last-> next = temp;
            last = temp;
        }
        else {
            root = new Node<T> ();
            root-> data = value;
            last = root;
        }
        ++siz;
    }

    void add_front (T value) {
        if (root) {
            Node<T> *temp = new Node<T> ();
            temp-> data = value;
            temp-> next = root;
            root = temp;
        }
        else {
            root = new Node<T> ();
            root-> data = value;
            last = root;
        }
        ++siz;
    }

    bool search (T value) {
        bool found = 0;

        for (Node<T> *temp = root; temp; temp = temp-> next) 
            if (temp->data == value) {
                found = 1;
                break;
            }
        
        return found;
    }

    void remove_element_at_index (int pos) {
        if (pos < siz) {
            Node<T> *temp = root, *temp2;
            
            if (pos == 0) {
                root = root-> next;

                if (siz == 1) 
                    last = NULL;
                delete temp;
            }
            else {
                int cnt = 0;
                
                while (cnt + 1 < pos) {
                    ++cnt;
                    temp = temp-> next;
                }
                temp2 = temp-> next;
                temp->next = temp2->next;
                
                if (pos + 1 == siz) 
                    last = temp;
                delete temp2;
            }
            --siz;
        }
    }

    void print () {
        Node<T> *temp = root;

        while (temp) {
            cout << temp-> data << " \n"[temp->next == NULL];
            temp = temp-> next;
        }
    }

    ~Linked_list () {
        Node<T> *temp;

        while (root) {
            temp = root;
            root = root-> next;
            delete temp;
        }
    } 
};