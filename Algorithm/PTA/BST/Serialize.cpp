//
//  Serialize.cpp
//  PTA
//
//  Created by Alex on 2020/11/4.
//  Copyright © 2020 Alex. All rights reserved.
//

#include "Serialize.hpp"

string Codec::serialize(TreeNode* root) {
    if(!root) return "";
    //preorder
    string s;
    string tmp;
    tmp = to_string(root->val);
     
    s= serialize(root->left)+",";
     serialize(root->right);
    return "";
}

TreeNode* Codec::deserialize(string data) {
    return nullptr;
}





int main(){
    
    vector<vector<int> > test_vec;
    test_vec.emplace_back();
    
//    vector<vector<int> >::iterator row;
//    vector<int>::iterator row;
    for(auto &row:test_vec) {
        for(auto &i: row) cout << i << endl;
    }
    return 0;
}
