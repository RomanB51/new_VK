/*#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <deque>

int main() {
    std::vector<int> v = {3, 14, 15, 92, 6};
    std::list<int> l;
    l.resize(v.size());  // теперь в списке l 5 нулей     что интересно, это то, что функция reserve актуальна только
                                                          // для string и vector, с deque, с list она не канает
    std::copy(v.rbegin(), v.rend(), l.rbegin());

    for (int x : l) {
        std::cout << x << " ";
    }
    std::cout << "\n";  // 6 92 15 14 3
}*/

/*#include <vector>                       //написание шаблона функции для удвоения вектора
#include <algorithm>
#include <iterator>

template <typename T>
void Duplicate(std::vector<T>& v) {
    v.reserve(v.size() * 2);              //reserve отличается от resize тем, что резервирует память, но не увеличивает размер вектора
                                          //в плане количества элементов, это позволяет избежать релокации при push_back,
                                          //а вот resize увеличивает количество элементов в векторе, заполняя их случайными значениями
                                          //нужного типа, как правило resize приводит к релокации.
    std::copy(v.rbegin(), v.rend(), std::back_inserter(v));
}
*/

/*#include <vector>                       //2 вариант написания шаблона функции для удвоения вектора
#include <algorithm>
#include <iterator>

template <typename G>
void Duplicate(std::vector<G>& h)
{
    for(size_t e = h.size(), i = 0; i != e; ++i)
        h.push_back(h[i]);
}

int main(){
    std::vector<int> d;
    d = {1,2,3};
    Duplicate(d);
}*/

#include <iterator>
#include <vector>
#include <deque>
#include <iostream>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    auto it1 = first;
    auto it2 = first;
    while (it2 != last) { //до тех пор пока мы не достигли конца вектора
        if (it1 != it2) { //если они не равны, то присвой *it1 значение *it2;
            *it1 = *it2;
        }
        ++it1; //двигаемся к сдедующему элементу
        const auto& value = *it2; //присваиваем промежуточной переменной значение *it2
        while (it2 != last && *it2 == value) { //до тех пор it2 не равен последней позиции
            ++it2;                  
        }
    }
    return it1;
}

int main(){
    std::deque<int> arra = {5, 3, 2, 3, 1, 5, 17, 8, 1};
    Unique(arra.begin(), arra.end() - 1);
    std::cout << "Pricol";
}


