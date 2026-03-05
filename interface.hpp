#include <iostream>
template <class T> struct BiList {
  T val;
  BiList<T> *next;
  BiList<T> *prev;
};

template <class T> // добавить перед
BiList<T> *add(BiList<T> *h, const T &v) {
  BiList<T> *e = new BiList<T>;
  e->val = v;
  e->prev = h->prev;
  e->next = h;

  e->next->prev = e;
  e->prev->next = e;

  return e;
}

template <class T> // добавить после
BiList<T> *insert(BiList<T> *h, const T &v) {
  BiList<T> *tmp = add(h->next, v);
  if (h->next) {
    h->next->prev = tmp;
  }

  h->next = tmp;
  return tmp;
}

template <class T> BiList<T> *fake(BiList<T> *h) {
  // BiList< T >* r = static_cast< BiList< T >* >(::operator new(sizeof(BiList<
  // T >*)));
  BiList<T> *a = new BiList<T>;

  a->prev = nullptr;
  a->next = h;

  if (h) {
    h->prev = a;
  }

  return a;
}

template <class T> BiList<T> *rmfake(BiList<T> *h) noexcept {
  BiList<T> *ret = h->next;
  delete h;
  return ret;
}

template <class T> // удалить элемент, который передается
BiList<T> *cut(BiList<T> *node) noexcept {
  BiList<T> *next = node->next;
  BiList<T> *prev = node->prev;

  if (prev) {
    prev->next = next;
  }

  if (next) {
    next->prev = prev;
  }
  delete node;
  return next;
}

template <class T> // удалить после
BiList<T> *erase(BiList<T> *h) noexcept {
  return h->next = cut(h->next);
}

template <class T> // очистить
BiList<T> *clear(BiList<T> *h, BiList<T> *e) noexcept {
  while (h != e) {
    h = cut(h);
  }
  return h;
}

template <class T> void print(BiList<T> *fake) noexcept {
  std::cout << "Forward: ";

  BiList<T> *cur = fake->next;
  BiList<T> *tail = nullptr;

  while (cur) {
    std::cout << cur->val << " ";
    if (!cur->next) {
      tail = cur;
    }
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
