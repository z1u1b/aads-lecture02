template < class T >
struct BiList
{
  T val;
  BiList< T >* next;
  BiList< T >* prev;
};

template < class T > // добавить перед
BiList< T >* add(BiList< T >* h, const T& v);

template < class T > // добавить после
BiList< T >* insert(BiList< T >* h, const T& v);

template < class T > // удалить голову
BiList< T >* cut(BiList< T >* node) noexcept;

template < class T > // удалить после
BiList< T >* erase(BiList< T >* h) noexcept;

template < class T > // очистить
BiList< T >* clear(BiList< T >* h, BiList< T >* e) noexcept;

template < class T, class F > // обход
F traverse(F f, BiList< T >* h, BiList< T >* e);

template < class T >
BiList< T >* fake(BiList< T >* h);

template < class T >
BiList< T >* rmfake(BiList< T >* h) noexcept;
