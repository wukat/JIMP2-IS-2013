#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstring>

using namespace std;

struct node 
{
  struct node * next;
  string content;
};

typedef struct node node;

class List
{
private:
  node * head;  

public:
  List();
  List(node *);
  List(const List &);
  ~List();

  void find(string);
  void add_on_end(string);
  void add_on_pos(int, string);
  void del_pos(int);
  void read();
};

#endif
