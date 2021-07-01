template <class T> 
class BST {

private:
  template <typename X> 
  struct Node {
    int cnt{}; // counts the number of nodes with same data.
    X data;
    Node* right;
    Node* left;

    Node () {
      cnt = 1;
      right = left = NULL;
    }
  };

  int total_n; // counts the number of nodes in binary tree
  Node<T>* root = NULL;

  Node<T>* add_node (Node<T>* cur, T value) {
    cur = new Node<T> ();
    cur-> data = value;
    return cur;
  }

  Node<T>* successor (Node<T>* cur) {
    while (cur-> right != NULL) {
      cur = cur-> right;
    }
    return cur;
  }

  Node<T>* remove (T key, Node<T>* cur) {
    if (!cur) {
      return cur;
    } else if (key > cur-> data) {
      cur-> right = remove (key, cur-> right);
    } else if (key < cur-> data) {
      cur-> left = remove (key, cur-> left);
    } else {

      if (cur-> cnt >= 2) {
        cur-> cnt--;
      } else if (!cur->left && !cur-> right) {
        delete cur;
        cur = NULL;
      } else if (!cur-> left) {
        Node<T>* temp = cur;
        cur = cur-> right;
        delete temp;
      } else if (!cur-> right) {
        Node<T>* temp = cur;
        cur = cur-> left;
        delete temp;
      } else {
        Node<T>* temp = successor (cur-> left);
        cur-> data = temp-> data;
        cur-> left = remove (temp-> data, cur-> left);
      }
    }
    return cur;
  }

  void inorder (Node<T> *cur) {
    if (!cur) {
      return;
    }
    inorder (cur-> left);

    int x = cur-> cnt;
    while (x--) {
      cout << cur-> data << " ";
    }
    inorder (cur-> right);
  }

  void preorder (Node<T> *cur) {
    if (!cur) {
      return;
    }

    int x = cur-> cnt;
    while (x--) {
      cout << cur-> data << " ";
    }
    preorder (cur-> left);
    preorder (cur-> right);
  } 

  void postorder (Node<T>* cur) {
    if (!cur) {
      return;
    }
    postorder (cur-> left);
    postorder (cur-> right);
    
    int x = cur-> cnt;
    while (x--) {
      cout << cur-> data << " ";
    }
  }

  void dlt (Node<T> *head) {
    if (head == NULL) {
      return;
    }
    dlt (head-> left);
    dlt (head-> right);
    delete head;
  }

public: 

  BST () {
    total_n = 0;
    root = NULL;
  }

  void insert (T value) {
    total_n++;
    
    if (!root) {
      root = add_node (root, value);
      return;
    }
    Node<T>* cur = root;

    while (true) {
      if (value == cur->data) {
        cur-> cnt++;
        return;
      } else if (value < cur-> data) {
        if (!cur-> left) {
          cur->left = add_node (cur->left, value);
          return;
        } else {
          cur = cur-> left;
        }
      } else {
        if (!cur-> right) {
          cur-> right = add_node (cur-> right, value);
          return;
        } else {
          cur = cur-> right;
        }
      }
    } 
    return;
  }

  bool search (T key) {
    Node<T>* cur = root;

    while (cur) {
      if (cur-> data == key) {
        return true;
      } else if (key > cur-> data) 
        cur = cur->right;
      else cur = cur-> left;
    }
    return false;
  }

  void remove (T key) {
    if (search(key)) { 
      root = remove (key, root);
      total_n--;
    }
    return;
  }

  void inorder_traversal () {
    if (root) {
      inorder (root);
      cout << endl;
    }
    return;
  }

  void preorder_traversal () {
    if (root) {
      preorder (root);
      cout << endl;
    }
    return;
  }

  void postorder_traversal () {
    if (root) {
      postorder (root);
      cout << endl;
    }
    return;
  }

  int total_nodes () {
    return total_n;
  }
  
  ~BST () {
    dlt (root);
  } 
};
