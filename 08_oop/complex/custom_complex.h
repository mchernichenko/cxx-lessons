class Complex
{
public:
  double x; // филд для хранения реальной части
  double y; // филд для хранения мнимой части

  Complex(double a, double b) : x{a}, y{b} {}; // инициализация переменных класса https://radioprog.ru/post/1222

  double getRe();
  double getIm();

  Complex operator+(Complex other);
  Complex operator-(Complex other);
  bool operator==(Complex other) const; // константная функция, т.к. не меняет филды класса  ( https://radioprog.ru/post/1228 )

  double abs();
};