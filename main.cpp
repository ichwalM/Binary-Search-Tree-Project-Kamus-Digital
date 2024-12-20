

void hapus(Node*& root, string data) {
    if (root == nullptr)
        return;
    else if (data < root->data)
        hapus(root->left, data);
    else if (data > root->data)
        hapus(root->right, data);
    else {
        // kasus I
        if (root->left == nullptr && root->right == nullptr) {
            delete(root);
            root = nullptr;
        }
        // kasus II
        else if (root->left == nullptr) {
            temp = root;
            root = root->right;
            delete(temp);
            temp = nullptr;
        }
        else if (root->right == nullptr) {
            temp = root;
            root = root->left;
            delete(temp);
            temp = nullptr;
        }
        // kasus III
        else {
            temp = cariMin(root->right);
            root->Meaning = temp->Meaning;
            root->right = deleteNode(root->right, temp->key);
        }
    }
}