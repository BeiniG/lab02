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
alias edit=<nano|vi|vim|subl>
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
git config --global hub.protocol https
```

```sh
$ mkdir projects/lab02 && cd projects/lab02
$ git init
```
Вывод сообщает о том, что текущая ветка называется `master`
```sh
hint: Using 'master' as the name for the initial branch. This default branch name
hint: is subject to change. To configure the initial branch name to use in all
hint: of your new repositories, which will suppress this warning, call:
hint:
hint: 	git config --global init.defaultBranch <name>
hint:
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
hint: 'development'. The just-created branch can be renamed via this command:
hint:
hint: 	git branch -m <name>
Initialized empty Git repository in /home/vboxuser/Desktop/BeiniG/workspace/projects/lab02/.git/
```
Используем команду:
```sh
$ git branch -m main
```
Продолжаем настройку
```sh
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
# check your git global settings
$ git config -e --global
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
$ git pull origin main
```
```sh
$ touch README.md
$ git status
```
Вывод:
```sh
On branch main
Untracked files:
  (use "git add <file>..." to include in what will be committed)
	README.md
```
```sh
$ git add README.md
$ git commit -m"added README.md"
$ git push origin main
```

```sh
[main (root-commit) c20609a] added README.md
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 README.md
```
```sh
Username for 'https://github.com': BeiniG
Password for 'https://BeiniG@github.com': 
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 219 bytes | 219.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/BeiniG/lab02.git
 * [new branch]      main -> main
```
Добавляем на сервисе **GitHub** в репозитории **lab02** файл **.gitignore**
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
Вывод команды:
```sh
remote: Enumerating objects: 4, done.
remote: Counting objects: 100% (4/4), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 955 bytes | 955.00 KiB/s, done.
From https://github.com/BeiniG/lab02
 * branch            main       -> FETCH_HEAD
   c20609a..dadd5c0  main       -> origin/main
Updating c20609a..dadd5c0
Fast-forward
 f.gitignore | 4 ++++
 1 file changed, 4 insertions(+)
 create mode 100644 f.gitignore
commit dadd5c0e607cd4ec08c8a54b0c1f0689b6f751e8 (HEAD -> main, origin/main)
Author: BeiniG <111754603+BeiniG@users.noreply.github.com>
Date:   Fri Apr 3 23:08:23 2026 -0800

    Create f.gitignore

commit c20609a9185671628905e0c94b5921c7d8f7bb68
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:06:23 2026 -0700

    added README.md
```
Создаем файлы
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
Коммитим созданные файлы
$ git status
$ git add .
$ git commit -m"added sources"
$ git push origin main
```
```sh
On branch main
Untracked files:
  (use "git add <file>..." to include in what will be committed)
	examples/
	include/
	sources/

nothing added to commit but untracked files present (use "git add" to track)
[main f2a7d4a] added sources
 4 files changed, 32 insertions(+)
 create mode 100644 examples/example1.cpp
 create mode 100644 examples/example2.cpp
 create mode 100644 include/print.hpp
 create mode 100644 sources/print.cpp
Username for 'https://github.com': BeiniG
Password for 'https://BeiniG@github.com': 
Enumerating objects: 10, done.
Counting objects: 100% (10/10), done.
Delta compression using up to 3 threads
Compressing objects: 100% (7/7), done.
Writing objects: 100% (9/9), 934 bytes | 934.00 KiB/s, done.
Total 9 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/BeiniG/lab02.git
   dadd5c0..f2a7d4a  main -> main
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
Выполняется с помощью команды:
```sh
$ cat > hello_world.cpp << 'EOF'
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
$ git add hello_world.cpp
```
5. Закоммитьте изменения с осмысленным сообщением.
```bash
$ git commit -m "Добавлена программа с плохим стилем кода"
```
```sh
[main fec67f2] Добавлена программа с плохим стилем кода
 1 file changed, 8 insertions(+)
 create mode 100644 hello_world.cpp
```

6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение Hello world from @name, где @name имя пользователя.
Изменяем программу командами:
```sh
$ cat > hello_world.cpp << 'EOF'
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
$ git commit -am "Добавлен ввод с клавиатуры"
```
Вывод:
```sh
[main 292b27e] Добавлен ввод с клавиатуры
 1 file changed, 4 insertions(+), 1 deletion(-)
```
Повторно `git add` писать не нужно, поскольку `hello_world.cpp` уже находится в репозитории.

8. Запуште изменения в удалёный репозиторий.
Выполняется с помощью команды:
```bash
$ git push origin main
```
```sh
Username for 'https://github.com': BeiniG
Password for 'https://BeiniG@github.com': 
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 3 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 760 bytes | 253.00 KiB/s, done.
Total 6 (delta 3), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (3/3), completed with 1 local object.
To https://github.com/BeiniG/lab02.git
   f2a7d4a..292b27e  main -> main
```

9. Проверьте, что история коммитов доступна в удалёный репозитории
```sh
$ git log
```
Вывод:
```sh
commit 292b27e0661af7eb364dfb0959fcc9ed400e189e (HEAD -> main, origin/main)
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:13:12 2026 -0700

    Добавлен ввод с клавиатуры

commit fec67f25a42dd0bf61ec8dd99273dd07fbb49c5b
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:12:31 2026 -0700

    Добавлена программа с плохим стилем кода

commit f2a7d4a7fa997854450da9002be6b798ba1690a0
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:10:47 2026 -0700

    added sources

commit dadd5c0e607cd4ec08c8a54b0c1f0689b6f751e8
Author: BeiniG <111754603+BeiniG@users.noreply.github.com>
Date:   Fri Apr 3 23:08:23 2026 -0800

    Create f.gitignore

commit c20609a9185671628905e0c94b5921c7d8f7bb68
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:06:23 2026 -0700

    added README.md
```
### Part II

1. В локальной копии репозитория создайте локальную ветку patch1.
Используем команду:
```bash
$ git checkout -b patch1
```
```sh
Switched to a new branch 'patch1'
```
2. Внесите изменения в ветке patch1 по исправлению кода и избавления от using namespace std;.
Вносим изменения:
```bash
$ cat > hello_world.cpp << 'EOF'
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
$ git add hello_world.cpp
$ git commit -m "Убрана строчка 'using namespace std;'"
$ git push -u origin patch1
```
```sh
[patch1 f10b247] Убрана строчка 'using namespace std;'
 1 file changed, 4 insertions(+), 5 deletions(-)
Username for 'https://github.com': BeiniG
Password for 'https://BeiniG@github.com': 
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 3 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 428 bytes | 428.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/BeiniG/lab02/pull/new/patch1
remote: 
To https://github.com/BeiniG/lab02.git
 * [new branch]      patch1 -> patch1
branch 'patch1' set up to track 'origin/patch1'.
```
4. Проверьте, что ветка patch1 доступна в удалёный репозитории
Выполняется с помощью команд:
```bash
$ git log
```
```sh
commit f10b2472ef7f6fd3d23c446c7857639f4ae2a255 (HEAD -> patch1, origin/patch1)
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:15:05 2026 -0700

    Убрана строчка 'using namespace std;'

commit 292b27e0661af7eb364dfb0959fcc9ed400e189e (origin/main, main)
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:13:12 2026 -0700

    Добавлен ввод с клавиатуры

commit fec67f25a42dd0bf61ec8dd99273dd07fbb49c5b
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:12:31 2026 -0700

    Добавлена программа с плохим стилем кода

commit f2a7d4a7fa997854450da9002be6b798ba1690a0
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:10:47 2026 -0700

    added sources

commit dadd5c0e607cd4ec08c8a54b0c1f0689b6f751e8
Author: BeiniG <111754603+BeiniG@users.noreply.github.com>
Date:   Fri Apr 3 23:08:23 2026 -0800

    Create f.gitignore

commit c20609a9185671628905e0c94b5921c7d8f7bb68
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:06:23 2026 -0700

    added README.md
```
5. Создайте pull-request patch1 -> main.
Pull requests -> New pull request
6. В локальной копии в ветке patch1 добавьте в исходный код комментарии.
Добавляем комментарии:
```bash
$ cat > hello_world.cpp << 'EOF'
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
EOF
```
7. commit, push.
```bash
$ git add hello_world.cpp
$ git commit -m "Добавлены комментарии"
$ git push origin patch1
```
```sh
[patch1 cc1e4d7] Добавлены комментарии
 1 file changed, 8 insertions(+), 1 deletion(-)
Username for 'https://github.com': BeiniG
Password for 'https://BeiniG@github.com': 
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 3 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 555 bytes | 555.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/BeiniG/lab02.git
   f10b247..cc1e4d7  patch1 -> patch1
```
8. Проверьте, что новые изменения есть в созданном на шаге 5 pull-request. Подтверждаем это через гитхаб.
9. В удалённый репозитории выполните слияние PR patch1 -> main и удалите ветку patch1 в удаленном репозитории. Это можно сделать на гитхабе.
10. Локально выполните pull.
Для этого можно воспользоваться командой:
```bash
$ git pull origin main
```
```sh
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 885 bytes | 885.00 KiB/s, done.
From https://github.com/BeiniG/lab02
 * branch            main       -> FETCH_HEAD
   292b27e..cb83046  main       -> origin/main
Updating 292b27e..cb83046
Fast-forward
 hello_world.cpp | 18 ++++++++++++------
 1 file changed, 12 insertions(+), 6 deletions(-)
```
11. С помощью команды git log просмотрите историю в локальной версии ветки main.
```sh
$ git log
```
```sh
commit cb83046f759392619c915ab5d2b526d10464d345 (HEAD -> main, origin/main)
Merge: 292b27e cc1e4d7
Author: BeiniG <111754603+BeiniG@users.noreply.github.com>
Date:   Fri Apr 3 23:20:30 2026 -0800

    Merge pull request #1 from BeiniG/patch1
    
    Patch1

commit cc1e4d7f5758a0998ea2550e94d1ea93d1e27372 (origin/patch1, patch1)
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:17:21 2026 -0700

    Добавлены комментарии

commit f10b2472ef7f6fd3d23c446c7857639f4ae2a255
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:15:05 2026 -0700

    Убрана строчка 'using namespace std;'

commit 292b27e0661af7eb364dfb0959fcc9ed400e189e
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:13:12 2026 -0700

    Добавлен ввод с клавиатуры

commit fec67f25a42dd0bf61ec8dd99273dd07fbb49c5b
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:12:31 2026 -0700

    Добавлена программа с плохим стилем кода

commit f2a7d4a7fa997854450da9002be6b798ba1690a0
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:10:47 2026 -0700

    added sources

commit dadd5c0e607cd4ec08c8a54b0c1f0689b6f751e8
Author: BeiniG <111754603+BeiniG@users.noreply.github.com>
Date:   Fri Apr 3 23:08:23 2026 -0800

    Create f.gitignore

commit c20609a9185671628905e0c94b5921c7d8f7bb68
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:06:23 2026 -0700

    added README.md

```

12. Удалите локальную ветку patch1.
```bash
$ git branch -d patch1
```
```sh
Deleted branch patch1 (was cc1e4d7).
```
### Part III

1. Создайте новую локальную ветку patch2.
Используем команды:
```bash
$ git pull origin main
$ git checkout -b patch2
```
```sh
From https://github.com/BeiniG/lab02
 * branch            main       -> FETCH_HEAD
Already up to date.
Switched to a new branch 'patch2'
```
2. Измените code style с помощью утилиты clang-format. Например, используя опцию -style=Mozilla.
```sh
$ clang-format -style=Mozilla -i hello_world.cpp 
```
Файл выглядит следующим образом:
```cpp
#include <iostream>
#include <string>

// Главная функция программы
int
main()
{
  // Переменная для хранения имени пользователя
  std::string name;

  // Запрос имени у пользователя
  std::cout << "Enter your name: ";
  std::cin >> name;

  // Вывод приветствия с именем пользователя
  std::cout << "Hello world from " << name << std::endl;

  return 0; // Успешное завершение программы
}
```
3. commit, push, создайте pull-request patch2 -> main.
```bash
$ git commit -m "Изменен стиль кода"
$ git push origin patch2
```
```sh
Username for 'https://github.com': BeiniG
Password for 'https://BeiniG@github.com': 
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 3 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 394 bytes | 394.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/BeiniG/lab02.git
   cb83046..aba1322  patch2 -> patch2
```
Создаем pull request на гитхабе

4. В ветке main в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
```bash
$ git checkout main
$ cat > hello_world.cpp << 'EOF'
#include <iostream>
#include <string>

// Main function
int main() {
    // Name variable
    std::string name;
    
    // Name request
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Output
    std::cout << "Hello world from " << name << std::endl;
    
    return 0; // End of program
}
EOF
```
Закоммитьте и отправьте изменения

Коммитим изменения с помощью команд:
```bash
$ git add hello_world.cpp
$ git commit -m "Комментарии переведены на английский"
$ git push origin main
```
```sh
[main 899dd22] Комментарии переведены на английский
 1 file changed, 5 insertions(+), 5 deletions(-)
Username for 'https://github.com': BeiniG
Password for 'https://BeiniG@github.com': 
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 3 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 432 bytes | 432.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/BeiniG/lab02.git
   cb83046..899dd22  main -> main
```

5. Убедитесь, что в pull-request появились конфликтны.

На гитхабе появился конфликт, выполнить merge невозможно

6. Для этого локально выполните pull + rebase (точную последовательность команд, следует узнать самостоятельно). Исправьте конфликты.
```sh
$ git checkout patch2
$ git rebase main
```
Вывод:
```sh
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply aba1322... Изменен стиль кода
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
hint: Disable this message with "git config advice.mergeConflict false"
```
hello_world.cpp выглядит так:
```bash

#include <iostream>
#include <string>

<<<<<<< HEAD
// Main function
int main() {
    // Name variable
    std::string name;
    
    // Name request
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Output
    std::cout << "Hello world from " << name << std::endl;
    
    return 0; // End of program
=======
// Основная функция
int
main()
{
  // Переменная имени
  std::string name;

  // Запрос имени у пользователя
  std::cout << "Enter your name: ";
  std::cin >> name;

  // Вывод
  std::cout << "Hello world from " << name << std::endl;

  return 0; // Завершение программы
>>>>>>> aba1322 (Изменен стиль кода)
}
```
Исправляем файл:
```sh
#include <iostream>
#include <string>

// Main function
int
main()
{
  // Name variable
  std::string name;

  // Name request
  std::cout << "Enter your name: ";
  std::cin >> name;

  // Output
  std::cout << "Hello world from " << name << std::endl;

  return 0; // End of program
}
```
```sh
$ git add hello_world.cpp
$ git rebase --continue
```
```sh
[detached HEAD 6916594] Изменен стиль кода
 1 file changed, 14 insertions(+), 12 deletions(-)
Successfully rebased and updated refs/heads/patch2.
```
7. Сделайте force push в ветку patch2
Для этого применяем команду:
```bash
$ git push --force-with-lease origin patch2
```
```sh
Username for 'https://github.com': BeiniG
Password for 'https://BeiniG@github.com': 
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 3 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 406 bytes | 135.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/BeiniG/lab02.git
 + aba1322...6916594 patch2 -> patch2 (forced update)
```
8. Убедитель, что в pull-request пропали конфликтны.
9. Вмержите pull-request patch2 -> main. Делаем этот на гитхабе.

Смотрим историю:
```bash
$ git log
```
```sh
commit 34c1639518b06a1d7dff7604bf9c1fa55a732aba (HEAD -> patch2, origin/main)
Merge: 899dd22 6916594
Author: BeiniG <111754603+BeiniG@users.noreply.github.com>
Date:   Fri Apr 3 23:40:17 2026 -0800

    Merge pull request #2 from BeiniG/patch2
    
    Изменен стиль кода

commit 6916594d362f6c34223edb5d5d3f642b943c9adc (origin/patch2)
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:32:20 2026 -0700

    Изменен стиль кода

commit 899dd22c0b984042506432801d4b028f454bf8f2 (main)
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:34:46 2026 -0700

    Комментарии переведены на английский

commit cb83046f759392619c915ab5d2b526d10464d345
Merge: 292b27e cc1e4d7
Author: BeiniG <111754603+BeiniG@users.noreply.github.com>
Date:   Fri Apr 3 23:20:30 2026 -0800

    Merge pull request #1 from BeiniG/patch1
    
    Patch1

commit cc1e4d7f5758a0998ea2550e94d1ea93d1e27372 (origin/patch1)
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:17:21 2026 -0700

    Добавлены комментарии

commit f10b2472ef7f6fd3d23c446c7857639f4ae2a255
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:15:05 2026 -0700

    Убрана строчка 'using namespace std;'

commit 292b27e0661af7eb364dfb0959fcc9ed400e189e
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:13:12 2026 -0700

    Добавлен ввод с клавиатуры

commit fec67f25a42dd0bf61ec8dd99273dd07fbb49c5b
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:12:31 2026 -0700

    Добавлена программа с плохим стилем кода

commit f2a7d4a7fa997854450da9002be6b798ba1690a0
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:10:47 2026 -0700

    added sources

commit dadd5c0e607cd4ec08c8a54b0c1f0689b6f751e8
Author: BeiniG <111754603+BeiniG@users.noreply.github.com>
Date:   Fri Apr 3 23:08:23 2026 -0800

    Create f.gitignore

commit c20609a9185671628905e0c94b5921c7d8f7bb68
Author: BeiniG <ivanvas1247@gmail.com>
Date:   Sat Apr 4 00:06:23 2026 -0700

    added README.md
```
Лабораторная работа успешно выполнена.
