#include <iostream>
#include <queue>
#include <stack>
#include "OrgChart.hpp"

using namespace std;

namespace ariel{

    OrgChart::OrgChart(){
        this->root = NULL;
        this->curr = NULL;
        this->start = new Iterator(root);
        this->over = new Iterator(root);
    }

    OrgChart::~OrgChart() {}

    OrgChart& OrgChart::add_root(const string curr) {
        if(this->root == NULL){
            this->root = new Node(curr);
            this->allNodes.push_back(this->root);
        }
        else{
            this->root->value = curr;
        }
        return *this;
    }

    OrgChart& OrgChart::add_sub(const string curr, const string child) {
        Node* addTo = NULL;
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            if(this->allNodes.at(i)->value == curr){
                addTo = this->allNodes.at(i);
                break;
            }
        }
        if(addTo == NULL){
            throw invalid_argument("Parent is not in the organization\n");
        }
        Node* newChild = new Node(child);
        addTo->children.push_back(newChild);
        this->allNodes.push_back(newChild);
        return *this;
    }

    ostream& operator<<(ostream &out, const OrgChart &Orgchart) {
        return out;
    }

    Iterator OrgChart::begin_preorder(){
//        this->DFS();
//        return *(this->start);
        return nullptr;
    }

    Iterator OrgChart::begin_level_order(){
//        this->BFS();
//        return *(this->start);
        return nullptr;
    }

    Iterator OrgChart::begin_reverse_order(){
//        this->revBFS();
//        return *(this->start);
        return nullptr;
    }

    Iterator OrgChart::end_preorder(){
//        if(this->over->data == this->start->data){
//            this->start->data = this->root;
//            return *(this->over);
//        }
//        return *(this->over);
        return nullptr;
    }
    Iterator OrgChart::end_level_order(){
//        if(this->over->data == this->start->data){
//            this->start->data = this->root;
//            return *(this->over);
//        }
//        return *(this->over);
        return nullptr;
    }
    Iterator OrgChart::reverse_order(){
//        if(this->over->data == this->start->data){
//            this->start->data = this->root;
//            return *(this->over);
//        }
//        return *(this->over);
        return nullptr;
    }

    Iterator OrgChart::begin(){
//        if(this->start->data == this->root){
//            this->BFS();
//        }
//        this->start++;
//        return *(this->start);
        return nullptr;
    }
    Iterator OrgChart::end(){
//        if(this->over->data == this->start->data){
//            this->start->data = this->root;
//            return *(this->over);
//        }
//        return *(this->over);
        return nullptr;
    }

    void OrgChart::BFS() {
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            this->allNodes.at(i)->visited = false;
        }
        queue<Node*> q;
        this->root->visited = true;
        q.push(this->root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->children.size() == 0 && !q.empty()){
                curr->next = NULL;
                this->over->data= curr;
            }
            else{curr->next = q.front();}
            for (unsigned int i = 0; i < curr->children.size(); ++i){
                if (!curr->children.at(i)->visited){
                    curr->children.at(i)->visited = true;
                    q.push(curr->children.at(i));
                }
            }
        }
    }
    void OrgChart::revBFS() {
        vector<Node*> nextFix;
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            this->allNodes.at(i)->visited = false;
        }
        queue<Node*> q;
        this->root->visited = true;
        q.push(this->root);
        while(!q.empty()){
            Node* curr = q.front();
            nextFix.push_back(curr);
            q.pop();
            for (unsigned int i = 0; i < curr->children.size(); ++i){
                if (!curr->children.at(i)->visited){
                    curr->children.at(i)->visited = true;
                    q.push(curr->children.at(i));
                }
            }
        }
        for (int i = nextFix.size() - 1; i >= 0; --i) {
            if(i!=0){
                nextFix.at((unsigned int) i)->next = nextFix.at((unsigned int) i-1);
            }
            else{
                nextFix.at(0)->next = NULL;
            }
        }
    }
    void OrgChart::DFS() {
        for (unsigned int i = 0; i < this->allNodes.size(); ++i) {
            this->allNodes.at(i)->visited = false;
        }
        stack<Node*> stack;
        stack.push(this->root);
        while (!stack.empty()){
            Node* curr = stack.top();
            stack.pop();
            if(curr->children.size() == 0 && !stack.empty()){
                curr->next = NULL;
                this->over->data = curr;
            }
            else{curr->next = stack.top();}
            for (int i = curr->children.size() - 1; i >= 0; --i){
                if (!curr->children.at((unsigned) i)->visited){
                    curr->children.at((unsigned) i)->visited = true;
                    stack.push(curr->children.at((unsigned) i));
                }
            }
        }
    }
}