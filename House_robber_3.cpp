#include<bits/stdc++.h>
using namespace std;
//It is a problem of LeetCode
//It is a 1D DP Problem of Top Down approach

//You have just have to use memorization on trees which
//you can easily do by using map as where Tree* used as index

class Tree
{
public:
  int data;
  Tree* left;
  Tree* right;
};

Tree* create_node(int n)
{
  Tree* new_node = new Tree();
  new_node->data = n;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void in_order(Tree*& temp,map<Tree*,int>&m)
{
  if(temp != NULL)
  {
    in_order(temp->left,m);
    //cout << temp->data << " ";
    m[temp] = -1;
    in_order(temp->right,m);
  }
}

int recurr_dp(Tree*& temp,map<Tree*,int>& m)
{
  if(temp==NULL)
  {
    return 0;
  }
  if(m[temp] != -1)
  {
    return m[temp];
  }
  int a,b;
  a = temp->data;
  if(temp->left != NULL)
  {
    a += recurr_dp(temp->left->left,m);
    a += recurr_dp(temp->left->right,m);
  }
  if(temp->right != NULL)
  {
    a += recurr_dp(temp->right->left,m);
    a += recurr_dp(temp->right->right,m);
  }
  b = recurr_dp(temp->left,m);
  b += recurr_dp(temp->right,m);
  m[temp] = max(a,b);
  return m[temp];
}

int main()
{
  Tree* root = NULL;
  //Simple binary tree creation
  root = create_node(2);
  //Sub tree left
  root->left = create_node(1);
  root->left->right = create_node(4);
  //Sub tree right
  root->right = create_node(3);

  map<Tree*,int>m;
  in_order(root,m);
  cout << recurr_dp(root,m) << "\n";
}
