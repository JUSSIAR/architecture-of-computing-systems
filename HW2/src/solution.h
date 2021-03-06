#include <iostream>
#include <fstream>
#include <vector>

enum AutoId {
  CAR,
  BUS,
  TRUCK
};

class Auto {
  public:
    Auto(int capacity, double spending, AutoId id) :
      fuel_capacity_(capacity),
      fuel_spending_(spending),
      transport_(id)
    {}
    ~Auto() = default;

    double calculateDistance() const;
    AutoId getTransport() const;

  private:
    int fuel_capacity_;
	  double fuel_spending_;
    AutoId transport_;
};

class Car : public Auto {
  public:
    Car(int capacity, double spending, short speed) :
      Auto(capacity, spending, AutoId::CAR),
      speed_(speed) 
    {}
    ~Car() = default;

  private:
    short speed_;
};

class Bus : public Auto {
  public:
    Bus(int capacity, double spending, short passangers) :
      Auto(capacity, spending, AutoId::BUS),
      passangers_(passangers)
    {}
    ~Bus() = default;

  private:
    short passangers_;
};

class Truck : public Auto {
  public:
    Truck(int capacity, double spending, int weight) :
      Auto(capacity, spending, AutoId::TRUCK),
      weight_(weight)
    {}
    ~Truck() = default;

  private:
    int weight_;
};

struct Container {
  std::vector<Auto*> array;
  size_t size;
};

class InteractiveController {
  public: static void input(std::ifstream& input, Container& container);
  public: static void output(std::ofstream& output, const Container& container);
};

namespace sorting {
  bool compare(Auto* lhs, Auto* rhs);

  void swap(Auto*& l, Auto*& r);

  void inclusionSort(Container& container);
}