#include "interface.hpp"
#include <iostream>
int main() {
  BiList<int> *fake = make(10);   // list — это fake-заголовок!
  BiList<int> *list = fake->next; // list — это fake-заголовок!

  add(list, 5); // добавляем перед первым реальным элементом
  add(list, 3);
  insert(list, 15); // добавляем после первого элемента
  
  print(fake); // передаём fake-узел

  list = rmfake(fake);
}
