// Задача 2. Копирование умных массивов.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class SmartArray {
private:
    int* arr;          // Указатель на динамическую память
    int capacity; // Максимальная емкость массива
    int size;    // Количество текущих элементов

public:
    // Конструктор
    explicit SmartArray(int initial_capacity)
        : arr(new int[initial_capacity]), capacity(initial_capacity), size(0) {
    }

    // Конструктор копирования
    SmartArray(const SmartArray& other) {
        this->arr = new int[other.capacity];
        this->capacity = other.capacity;
        this->size = other.size;

        for (int i = 0; i < size; ++i) {
            this->arr[i] = other.arr[i];
        }
    }

    // Операция присваивания
    SmartArray& operator=(const SmartArray& other) {
        if (this != &other) {  // Избегаем само-присваивания
            delete[] arr;     // Удаляем старый массив
            arr = new int[other.capacity];
            capacity = other.capacity;
            size = other.size;

            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Функция добавления элемента
    void add_element(int value) {
        if (size >= capacity) {
            resize(capacity * 2);  // Удвоение емкости, если нет свободного места
        }
        arr[size++] = value;
    }

    // Увеличение размера массива
    void resize(int new_capacity) {
        int* temp_data = new int[new_capacity];
        for (int i = 0; i < size; ++i) {
            temp_data[i] = arr[i];
        }
        delete[] arr;
        arr = temp_data;
        capacity = new_capacity;
    }

    // Доступ к элементу по индексу
    int& operator[](int index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    const int& operator[](int index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    int get_size() const { return size; }
    // Деструктор
    ~SmartArray() { delete[] arr; }
};

// Тестовый пример использования
int main() {
    SmartArray arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    SmartArray new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;  // Присваивание одного массива другому


    std::cout << "New array: ";
    for (int i = 0; i < arr.get_size(); ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
