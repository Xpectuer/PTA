//
//  Serialize.hpp
//  PTA
//
//  Created by Alex on 2020/11/4.
//  Copyright © 2020 Alex. All rights reserved.
//

#ifndef Serialize_hpp
#define Serialize_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) ;
};

#endif /* Serialize_hpp */
