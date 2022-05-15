#include <vector>
#include <string>
#include <iostream>
#include "Node.hpp"
#pragma once

using namespace std;

namespace ariel
{
    class OrgChart{
        public:
            // Node _root;
            string getRoot(){return "a";}
            vector<string> getChildren(string){
                vector<string> a;
                return a;
            }
            OrgChart add_root(string str);
            OrgChart add_sub(string parent,string child);
            vector<string>:: iterator begin_level_order();
            vector<string>:: iterator end_level_order();
            vector<string>:: iterator begin_reverse_order();
            vector<string>:: iterator reverse_order();//end
            vector<string>:: iterator begin_preorder();
            vector<string>:: iterator end_preorder();
            vector<int>:: iterator begin();
            vector<int>:: iterator end();
            friend std::ostream &operator<<(std::ostream &out, OrgChart &og);//{
    //     out<< og._root;
    //     return out;
    // };
    };
   
}