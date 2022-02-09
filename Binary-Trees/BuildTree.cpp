

    class Node {

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};




// I will create node with the given data and i will recursively call the left subtree
// and then i will recursively call the right subtree and will return the addresss of my
// root node of my tree simple


Node *BuildTree()
{

    // Taking input data
    int d;
    cin >> d;

    // creating node with the given data
    Node *n = new Node(d);

    // recursively call left subtree and store its address in my left pointer
    n->left = BuildTree();

    // after that recursively call right subtree and store its address in my right pointer
    n->right = BuildTree();

    // after that return the address of my Tree's root node same as head in LL
    return n;
}
