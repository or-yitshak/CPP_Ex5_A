#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Node{
    public:
    string _name;
    vector<Node*> children;

    Node(){
        this->_name = "null";
    }
    Node(string name){
        this->_name = name;
    }
    friend std::ostream &operator<<(std::ostream &out, Node &nd){
    out<< "Name: " << nd._name << endl;
    out << "Children: [";
    return out;
    }
};
// friend std::ostream &operator<<(std::ostream &out, Node &nd){
//     out<< "Name: " << nd->_name << endl;
//     out << "Children: [";
//     return out;
// }
    
    //  for (size_t i = 0; i < nd; i++)
    // {
    //     out << "[";
    //     for (size_t j = 0; j < col; j++)
    //     {
    //         out << mat._mat.at(i).at(j);
    //         if (j != col - 1)
    //         {
    //             out << " ";
    //         }
    //     }
    //     if (i == row - 1)
    //     {
    //         out << "]";
    //     }
    //     else
    //     {
    //         out << "]\n";
    //     }
    // }
