#include "interface.hpp"
template < class T > // добавить перед
BiList< T >* add(BiList< T >* h, const T& v)
{
  return new BiList< T >{v, h, h->prev};
}

template < class T > // добавить после
BiList< T >* insert(BiList< T >* h, const T& v)
{
  BiList< T >* tmp=add(h->next,v);
  if (h->next) {
    h->next->prev=tmp;
  }

  h->next=tmp;
  return tmp;

}

template < class T >
BiList< T >* fake(BiList< T >* h)
{
  // BiList< T >* r = static_cast< BiList< T >* >(::operator new(sizeof(BiList< T >*)));
  BiList<T>* а=new BiList<T>;


  а->prev=nullptr;
  f->next = h;

  if (h)
    head->prev = f;
  return r;
}

template < class T >
BiList< T >* rmfake(BiList< T >* h) noexcept
{
  BiList<T>* ret = h->next;
  delete h;
  return ret;
}

template < class T > // удалить голову
BiList< T >* cut(BiList< T >* node) noexcept
{
    BiList<T>* next = node->next;
    BiList<T>* prev = node->prev;

    if (prev) {
      prev->next = next;
    }


    if (next) {
       next->prev = prev;
    }
    delete node;
    return next;
}

template < class T > // удалить после
BiList< T >* erase(BiList< T >* h) noexcept
{
  return h->next=cut(h->next);
}

template < class T > // очистить
BiList< T >* clear(BiList< T >* h, BiList< T >* e) noexcept
{
  while(h!=e) {
    h=cut(h);
  }
  return h;
}

template<class T>
void print(BiList<T>* fake)
{
  std::cout << "Forward: ";

  BiList<T>* cur = fake->next;
  BiList<T>* tail = nullptr;

  while (cur) {
      std::cout << cur->val << " ";
      if (!cur->next)
          tail = cur;
      cur = cur->next;
  }

  std::cout << "Back: ";

  std::cout << "\n";
  while (tail) {
      std::cout << tail->val << " ";
      tail = tail->prev;
  }

  std::cout << "\n";
}
