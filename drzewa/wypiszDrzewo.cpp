#include <iostrem>
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
};
int leaves ( node *tree )
{
    if ( tree == nullptr ) return 0;
    if ( tree->left == nullptr && tree->right == nullptr ) return 1;
    return leaves(tree->left) + leaves(tree->right)
}
int wysokosc ( node *tree )
{
    if ( tree == nullptr ) return 0;
    return max(wysokosc( tree->left ), wysokosc( tree->rught )) + 1;
}
