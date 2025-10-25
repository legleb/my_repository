#include <iostream>
#include <climits>

bool isPyth(unsigned a, unsigned b, unsigned c);
bool checkOverflow(unsigned a, unsigned b, unsigned c);

const unsigned MAX = std::numeric_limits<unsigned>::max();

int main()
{
  using u_t = unsigned;
  u_t a = 0, b = 0, c = 0;
  std::cin >> c >> b;
  u_t count = 0;
  while (std::cin >> a) {
    count += isPyth(a, b, c);
    c = b;
    b = a;
  }
  if (std::cin.eof()) {
    std::cout << count;
    std::cout << "\n";
  } else if (std::cin.fail()) {
    std::cerr << "Error\n";
    return 1;
  }
}

bool isPyth(unsigned a, unsigned b, unsigned c)
{
  bool p = (a * a == (b * b + c * c));
  p = p || (b * b == (a * a + c * c));
  p = p || (c * c == (a * a + b * b));
  return p;
}

bool checkOverflow(unsigned a, unsigned b, unsigned c)
{
  bool p = (a > MAX / a);
  p = p || (b > MAX / b);
  p = p || (c > MAX / c);
  if (p == true) {
    return p;
  } else {
    unsigned a2 = a * a, b2 = b * b, c2 = c * c;
    p = (a2 > MAX - b2);
    p = p || (a2 > MAX - c2);
    p = p || (b2 > MAX - c2);
    return p;
}
