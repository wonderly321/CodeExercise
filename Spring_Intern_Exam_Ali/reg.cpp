#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
using namespace std;

struct Node
{
    map<string, Node*> next;
    int id;
    Node(int id):id(id){}
    void add_next(string c, Node* nxt)
    {
        //cout << "add edge from " << this->id << " to " << nxt->id << " with " << c << endl;
        this->next[c] = nxt;
    }
};

string pattern, s;
stack<Node*> savepoint;
int tot = 0;
int fake = 0;
//vector<Node*> nodepool;

void get_endpoints(Node* root, set<Node*> &ret)
{
    if(root->next.size() == 0) {
        ret.insert(root);
        return;
    }
    for(map<string, Node*>::iterator it = root->next.begin(); it != root->next.end(); it++) {
        get_endpoints(it->second, ret);
    }
}

void delete_tree(Node* root)
{
    if(root == NULL) return;
    for(map<string, Node*>::iterator it = root->next.begin(); it != root->next.end(); it++) {
        delete_tree(it->second);
    }
    root->next.clear();
    delete root;
}

int main()
{
    while(cin >> pattern >> s) {
        Node* root = new Node(tot++);
        while(!savepoint.empty()) savepoint.pop();

        savepoint.push(root);

        Node* now = root;
        bool out_from_bucket = false;

        for(int i = 0; i < pattern.length(); i++) {
            if(pattern[i] == '<') {
                Node* fake_node = new Node(--fake);
                now->add_next("", fake_node);
                now = fake_node;
                savepoint.push(now);
            }
            else if(pattern[i] == '[') {
                Node* fake_node = new Node(--fake);
                now->add_next("", fake_node);
                now = fake_node;
                savepoint.push(now);
            }
            else if(pattern[i] == '>') {
                Node* fake_node = new Node(--fake);

                now = savepoint.top();
                savepoint.pop();

                set<Node*> endpoints;
                get_endpoints(now, endpoints);
                for(set<Node*>::iterator it = endpoints.begin(); it != endpoints.end(); it++) {
                    (*it)->add_next("", fake_node);
                }
                now = fake_node;
            }
            else if(pattern[i] == ']') {
                Node* fake_node = new Node(--fake);
                now = savepoint.top();
                savepoint.pop();

                set<Node*> endpoints;
                get_endpoints(now, endpoints);
                for(set<Node*>::iterator it = endpoints.begin(); it != endpoints.end(); it++) {
                    (*it)->add_next("", fake_node);
                }
                now->add_next("", fake_node);

                now = fake_node;
            }
            else if(pattern[i] == '|') {
                now = savepoint.top();
            }
            else {
                string tmp = "";
                tmp += pattern[i];
                if((int)(pattern[i]) < 0) {
                    i += 1;
                    tmp += pattern[i];
                }
                Node* nxt = new Node(tot++);
                now->add_next(tmp, nxt);
                now = nxt;
            }
        }

        now = root;
        bool flag = true;
        for(int i = 0; i < s.length(); i++) {
            string tmp = "";
            tmp += s[i];
            if((int)(s[i]) < 0) {
                i += 1;
                tmp += s[i];
            }

            if(now->next.find(tmp) != now->next.end()) {
                now = now->next[tmp];
            }
            else {
                while(now != NULL && now->next.find(tmp) == now->next.end()) {
                    now = now->next[""];
                }
                if(now == NULL) {
                    flag = false;
                    break;
                }
                else {
                    now = now->next[tmp];
                }
            }
        }
        if(flag) puts("1"); else puts("0");

        delete_tree(root);
    }
    return 0;
}

