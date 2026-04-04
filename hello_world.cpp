#include <iostream>
#include <string>

// Основная функция
int main() {
    // Переменная имени
    std::string name;
    
    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Вывод
    std::cout << "Hello world from " << name << std::endl;
    
    return 0; // Завершение программы
}
