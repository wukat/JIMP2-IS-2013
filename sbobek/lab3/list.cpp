#include <sstream>
#include "list.h"

using namespace std;

List::List():head(NULL)
{}

List::List(node * first) : head(first)
{}

List::List(const List &old)
{
  node * actual = old.head;
  if (old.head != NULL)
  {
    head = new node;
    node * actual2 = head;
    while (actual != NULL)
    {
      actual2->content = actual->content;
      if (actual->next != NULL)
      {
        actual2->next = new node;
        actual2 = actual2->next;
      }
      else
        actual2->next = NULL;
      actual = actual->next;
    }
  }
  else
    head = NULL;
}

List::~List()
{
  node * actual = head;
  node * help;
  int done;
  while (head != NULL)
  {
    actual = head;
    done = 1;
    while (actual->next != NULL)
    {
      help = actual;
      actual = actual->next;
      done = 0;
    }
    delete actual;
    if (done == 0) help->next = NULL;
    else head = NULL;
  }
}

void List::find(string word)
{
  string result = "";
  if (head != NULL)
  {
    node * actual = head;
    int i = 1;
    string number;
    if (actual->content == word)
    {
      ostringstream ss;
      ss << i;
      number = ss.str();
      result += " ";
      result += number;
      result += ",";
    }
    while (actual->next != NULL)
    {
      actual = actual->next;
      i++;
      if (actual->content == word)
      {
        ostringstream ss;
        ss << i;
        number = ss.str();
        result += " ";
        result += number;
        result += ",";
      }
    }
  }
  if (result != "") cout << "Slowo " << word << " jest na pozycji" << result << endl;
  else cout << "Slowa nie znaleziono.";
}

void List::add_on_end(string word)
{
  if (head == NULL)
  {
    head = new node;
    head->next = NULL;
    head->content = word;
  }
  else
  {
    node * actual = head;
    while (actual->next != NULL)
      actual = actual->next;
    actual->next = new node;
    actual = actual->next;
    actual->next = NULL;
    actual->content = word;
  }
}

void List::add_on_pos(int pos, string word)
{
  if (head != NULL)
  {
    node * actual = head;
    for (int i = 1; i < pos; i++)
      if (actual->next != NULL)
        actual = actual->next;
      else break;
    node * nowy = new node;
    nowy->next = actual->next;
    actual->next = nowy;
    nowy->content = word;
  }
  else
  {
    head = new node;
    head->next = NULL;
    head->content = word;
  }
  cout << "Dodano na pozycji lub koncu listy" << endl;
}


void List::del_pos(int pos)
{
  if (head != NULL and pos > 0)
  {
    node * actual = head;
    int ok = 1;
    for (int i = 1; i < pos - 1; i++)
      if (actual->next != NULL)
        actual = actual->next;
      else ok = 0;
    if (ok == 1 && actual->next != NULL)
    {
      node * help = actual->next->next;
      delete actual->next;
      actual->next = help;
    }
    else
      cout << "Taki element nie istnieje!" << endl;
  }
  else
    cout << "Taki element nie istnieje!" << endl;
}

void List::read()
{
  if (head != NULL)
  {
    node * actual = head;
    while (actual != NULL)
    {
      cout << actual->content << " ";
      actual = actual->next;
    }
  }
  else
  {
    cout << "Lista jest pusta!";
  }
  cout << endl;
}
