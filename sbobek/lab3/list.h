#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstring>

struct node {
      struct node * next;
      std::string content;
};

typedef struct node node;

class List {
      node * head;

   public:
      List();
      List(node *);
      List(const List &);
      ~List();

      void find(std::string);
      void add_on_end(std::string);
      void add_on_pos(int, std::string);
      void del_pos(int);
      void read();
};

#endif
