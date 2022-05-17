#include <iostream>
#include <q>
#include "OrgChart.hpp"

using namespace std;

namespace ariel{

    OrgChart::OrgChart(){
        this->root = NULL;
        this->curr = NULL;
        this->start = new Iterator(root);
        this->back = new Iterator(root);
    }

    OrgChart::~OrgChart() {}

    OrgChart& OrgChart::add_root(const string curr) {
        if(this->root == NULL){
            this->root = new Node(curr);
            this->allNodes.push_back(this->curr);
        }
        else{
            this->root->value = curr;
        }
        return *this;
    }

    OrgChart& OrgChart::add_sub(const string curr, const string child) {
        Node* addTo;
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            if(this->allNodes.at(i)->value == curr){
                addTo = this->allNodes.at(i);
                break;
            }
        }
        Node* newChild = new Node(child);
        addTo->children.push_back(newChild);
        this->allNodes.push_back(newChild);
        return *this;
    }

    ostream& operator<<(ostream &out, const OrgChart &Orgchart) {
        return out;
    }

    Iterator& OrgChart::begin_preorder(){
        if(this->start->data == this->root){
            this->DFS();
        }
        this->start++;
        return this->start;
    }

    Iterator& OrgChart::begin_level_order(){
        if(this->start->data == this->root){
            this->BFS();
        }
        this->start++;
        return this->start;
    }

    Iterator& OrgChart::begin_reverse_order(){
        if(this->start->data == this->root){
            this->revBFS;
        }
        this->start++;
        return this->start;
    }

    Iterator OrgChart::end_preorder(){
        if(this->over->data == this->start->data){
            this->start->data = this->root;
            return this->over;
        }
        return this->over;
    }
    Iterator& OrgChart::end_level_order(){if(this->over->data == this->start->data){
            this->start->data = this->root;
            return this->over;
        }
        return this->over;
    }
    Iterator& OrgChart::reverse_order(){
        if(this->over->data == this->start->data){
            this->start->data = this->root;
            return this->over;
        }
        return this->over;
    }

    Iterator& OrgChart::begin(){
        return NULL;
    }
    Iterator& OrgChart::end(){
        return NULL;
    }

    void OrgChart::BFS() {
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            this->allNodes.at(i) = false;
        }
        queue<Node*> q;
        this->curr->visited = true;
        q.push(this->curr);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->children.size() == 0){
                curr->next = NULL;
                this->over= curr;
            }
            else{curr->next = q.start();}
            for (unsigned int i = 0; i < curr->children.size(); ++i){
                if (!curr->children.at(i)->visited){
                    curr->children.at(i)->visited = true;
                    q.push(curr->children.at(i));
                }
            }
        }
    }
    void OrgChart::DFS() {
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            this->allNodes.at(i) = false;
        }
        stack<Node*> stack;
        stack.push(curr);
        while (!stack.empty()){
            Node* curr = stack.top();
            stack.pop();
            if(curr->children.size() == 0){
                curr->next = NULL;
                this->over = curr;
            }
            else{curr->next = stack.top();}
            for (unsigned int i = curr->children.size() - 1; i >= ; i--){
                if (!curr->children.at(i)->visited){
                    curr->children.at(i)->visited = true;
                    stack.push(curr->children.at(i));
                }
            }
        }
    }
}