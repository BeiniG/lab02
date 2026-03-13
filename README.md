## Laboratory work II

Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.

```bash
$ open https://git-scm.com
```

## Tutorial

```sh
$ export GITHUB_USERNAME=<имя_пользователя>
$ export GITHUB_EMAIL=<адрес_почтового_ящика>
$ export GITHUB_TOKEN=<сгенирированный_токен>
$ alias edit=<nano|vi|vim|subl>
```

```sh
$ cd ${GITHUB_USERNAME}/workspace
$ source scripts/activate
```

```sh
$ mkdir ~/.config
$ cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
$ git config --global hub.protocol https
```

```sh
$ mkdir projects/lab02 && cd projects/lab02
$ git init
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
# check your git global settings
$ git config -e --global
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
$ git pull origin main
$ touch README.md
$ git status
$ git add README.md
$ git commit -m"added README.md"
$ git push origin main
```

Добавить на сервисе **GitHub** в репозитории **lab02** файл **.gitignore**
со следующем содержимом:

```sh
*build*/
*install*/
*.swp
.idea/
```

```sh
$ git pull origin main
$ git log
```

```sh
$ mkdir sources
$ mkdir include
$ mkdir examples
$ cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF
```

```sh
$ cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF
```

```sh
$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF
```

```sh
$ cat > examples/example2.cpp <<EOF
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF
```

```sh
$ edit README.md
```

```sh
$ git status
$ git add .
$ git commit -m"added sources"
$ git push origin main
```

## Report

```sh
$ cd ~/workspace/
$ export LAB_NUMBER=02
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER}.git tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```

## Homework

### Part I

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.
3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.
Выполняется с помощью команд:
```bash
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}
EOF
```
4. Добавьте этот файл в локальную копию репозитория.
Используем команду:
```bash
git add hello_world.cpp
```
5. Закоммитьте изменения с осмысленным сообщением.
```bash
git commit -m "Добавлена программа с плохим стилем кода"
6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение Hello world from @name, где @name имя пользователя.
Изменяем программу командами:
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from " << name << endl;
    return 0;
}
EOF
```
7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно git add?
```bash
git commit -am "Добавлен ввод с клавиатуры"
```
8. Запуште изменения в удалёный репозиторий.
Выполняется с помощью команды:
```bash
git push origin main
```
9. Проверьте, что история коммитов доступна в удалёный репозитории

### Part II

1. В локальной копии репозитория создайте локальную ветку patch1.
Используем команду:
```bash
git checkout -b patch1
```
2. Внесите изменения в ветке patch1 по исправлению кода и избавления от using namespace std;.
Вносим изменения:
```bash
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
EOF
```
3. commit, push локальную ветку в удалённый репозиторий.
Используем команды:
```bash
git add hello_world.cpp
git commit -m "Убрана строчка 'using namespace std;'"
git push -u origin patch1
```
4. Проверьте, что ветка patch1 доступна в удалёный репозитории
Выполняется с помощью команд:
```bash
git branch -a
git branch -r
```
5. Создайте pull-request patch1 -> main.
Pull requests -> New pull request
6. В локальной копии в ветке patch1 добавьте в исходный код комментарии.
Добавляем комментарии:
```bash
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>

// Главная функция программы
int main() {
    // Переменная для хранения имени пользователя
    std::string name;
    
    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Вывод приветствия с именем пользователя
    std::cout << "Hello world from " << name << std::endl;
    
    return 0; // Успешное завершение программы
}
EOF
```
7. commit, push.
```bash
git add hello_world.cpp
git commit -m "Добавлены комментарии"
git push origin patch1
```
8. Проверьте, что новые изменения есть в созданном на шаге 5 pull-request
9. В удалённый репозитории выполните слияние PR patch1 -> main и удалите ветку patch1 в удаленном репозитории.
10. Локально выполните pull.
Для этого можно воспользоваться командой:
```bash
git pull origin main
```
11. С помощью команды git log просмотрите историю в локальной версии ветки main.
12. Удалите локальную ветку patch1.
```bash
git branch -d patch1
```

### Part III

1. Создайте новую локальную ветку patch2.
Используем команды:
```bash
git pull origin main
git checkout -b patch2
```
2. Измените code style с помощью утилиты clang-format. Например, используя опцию -style=Mozilla.
```bash
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>

// Главная функция программы
int main() {
  // Переменная для хранения имени пользователя
  std::string name;

  // Запрос имени у пользователя
  std::cout << "Enter your name: ";
  std::cin >> name;

  // Вывод приветствия с именем пользователя
  std::cout << "Hello world from " << name << std::endl;

  return 0; // Успешное завершение программы
}
EOF
```
3. commit, push, создайте pull-request patch2 -> main.
```bash
git add hello_world.cpp
git commit -m "Изменен стиль кода"
```
4. В ветке main в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
```bash
git checkout main
cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>

// Main function
int main() {
    // Username variable
    std::string name;
    
    // Name request
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Otput
    std::cout << "Hello world from " << name << std::endl;
    
    return 0; // Успешное завершение программы!
}
EOF
```
# Закоммитьте и отправьте изменения
Коммитим изменения с помощтю команд:
```bash
git add hello_world.cpp
git commit -m "Комментарии переведены на английский"
git push origin main
```
5. Убедитесь, что в pull-request появились конфликтны.
6. Для этого локально выполните pull + rebase (точную последовательность команд, следует узнать самостоятельно). Исправьте конфликты.
```bash
git checkout patch2
git fetch origin
git rebase origin/main

#include <iostream>
#include <string>

<<<<<<< HEAD
// Main function
int main() {
    // Username variable
    std::string name;
    
    // Name request
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Otput
    std::cout << "Hello world from " << name << std::endl;
    
    return 0; // End of program
=======
// Главная функция программы
int main() {
    // Переменная для хранения имени
    std::string name;

    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;

    // Вывод приветствия с именем пользователя
    std::cout << "Hello world from " << name << std::endl;

    return 0; // Конец программы
>>>>>>> 3fddefd (Изменен стиль кода)
}


git add hello_world.cpp
git rebase --continue
```
7. Сделайте force push в ветку patch2
Для этого применяем команду:
```bash
git push --force-with-lease origin patch2
```
8. Убедитель, что в pull-request пропали конфликтны.
9. Вмержите pull-request patch2 -> main.
Используем команды:
```bash
git checkout main
git merge patch2
git push origin main
```
