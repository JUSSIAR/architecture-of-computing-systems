#include "./solution.h"

const char* names[3] = {"Car", "Bus", "Truck"};

void input(Auto& object) {
  int value_type;

  scanf("%d ", &object.fuel_capacity);
  scanf("%lf ", &object.fuel_spending);
  scanf("%d ", &value_type);

  switch (value_type) {
    case 1: {
      object.transport = Auto::Type::CAR;
      scanf("%d\n", &object._car.speed);
      break;
    }
    case 2: {
      object.transport = Auto::Type::BUS;
      scanf("%d\n", &object._bus.passangers);
      break;
    }
    case 3: {
      object.transport = Auto::Type::TRUCK;
      scanf("%d\n", &object._truck.weight);
      break;
    }
    default: {
      printf("wrong type of tansport\n");
    }
  }
}

void output(const Auto& object) {
  printf(
    "%s maxDistance = %lf\n", 
    names[object.transport - 1],
    calculateDistance(object)
  );
}

double calculateDistance(const Auto& object) {
  double fc = static_cast<double>(object.fuel_capacity);
  double fs = static_cast<double>(object.fuel_spending);
  return 100.0 * fc / fs;
}

bool compare(const Auto& lhs, const Auto& rhs) {
  return calculateDistance(lhs) < calculateDistance(rhs);
}

void smartFill(const Auto& l, Auto& r) {
  r.fuel_capacity = l.fuel_capacity;
  r.fuel_spending = l.fuel_spending;
  r.transport = l.transport;

  r._bus.passangers = l._bus.passangers;
  r._car.speed = l._car.speed;
  r._truck.weight = l._truck.weight;
}

void swap(Auto& l, Auto& r) {
  Auto temp_entity;
  smartFill(l, temp_entity);
  smartFill(r, l);
  smartFill(temp_entity, r);
}

void inclusionSort(Container& container) {
  for (size_t i = 1; i < container.size; i++) {
    for (size_t j = i; j > 0 && compare(container.array[j], container.array[j - 1]); j--) {
      swap(container.array[j], container.array[j - 1]);
    }
  }
}
