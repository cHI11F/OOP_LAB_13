#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Vector {
private:
    std::vector<T> data;

public:
    
    Vector(int size) : data(size) {}

    
    void set(int index, T value) {
        if (index < 0 || index >= data.size()) {
            throw std::out_of_range("Індекс виходить за межі вектора");
        }
        data[index] = value;
    }

    
    T get(int index) const {
        if (index < 0 || index >= data.size()) {
            throw std::out_of_range("Індекс виходить за межі вектора");
        }
        return data[index];
    }

    
    Vector operator+(const Vector& other) const {
        if (data.size() != other.data.size()) {
            throw std::invalid_argument("Розмір векторів не співпадає для додавання");
        }
        Vector result(data.size());
        for (int i = 0; i < data.size(); i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    
    Vector operator*(T scalar) const {
        Vector result(data.size());
        for (int i = 0; i < data.size(); i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

   
    void print() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int size;
    std::cout << "Введіть розмір вектора: ";
    std::cin >> size;

    Vector<int> v1(size);
    Vector<int> v2(size);

    std::cout << "Введіть елементи для першого вектора:" << std::endl;
    for (int i = 0; i < size; i++) {
        int value;
        std::cin >> value;
        v1.set(i, value);
    }

    std::cout << "Введіть елементи для другого вектора:" << std::endl;
    for (int i = 0; i < size; i++) {
        int value;
        std::cin >> value;
        v2.set(i, value);
    }

    Vector<int> sum = v1 + v2;
    std::cout << "Сума векторів: ";
    sum.print();

    int scalar;
    std::cout << "Введіть скаляр для множення: ";
    std::cin >> scalar;

    Vector<int> product = v1 * scalar;
    std::cout << "Результат множення першого вектора на " << scalar << ": ";
    product.print();

    return 0;
}
