#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>

bool isEven(int a)
{
    if (a%2 == 0)
        return true;
    return false;
}

void print (int elem)
{
    std::cout << elem << ' ';
}

int main()
{
    //1
    /*std::cout << "Write number of numbers: ";
    int count;
    std::cin >> count;*/
    std::list <int> L;
    //std::cout << "Write " << count << " numbers:" << std::endl;
    std::cout << "Write numbers:" << std::endl;

    std::istream_iterator <int> it_EOF;
    std::istream_iterator <int> in_it (std::cin);

    while (in_it != it_EOF)
    {
       L.push_back(*in_it);
       ++in_it; 
    }

    //5
    std::copy (L.rbegin(), L.rend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    /*for (unsigned i = 0; i < count; ++i)
    {
        int elem;
        std::cin >> elem;
        L.push_back(elem);
    }*/

    int num; 

    num = std::count (L.begin(), L.end(), 6);
    std::cout << num << std::endl;

    num = std::count_if (L.begin(), L.end(), isEven);
    std::cout << num << std::endl;

    std::list<int>::iterator ans;
    ans = std::find_if (L.begin(), L.end(), isEven);

    std::cout << *ans << std::endl;

    //2
    std::vector <int> V (10, 10);
    std::copy (V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::insert_iterator <std::vector<int>> it (V, ++V.begin());
    *it = 7;

    std::copy (V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::back_inserter (V) = 30;
    std::copy (V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    auto pos = remove (V.begin(), V.end(), 10);
    V.erase (pos, V.end());
    std::copy (V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    /*std::insert_iterator <std::vector <int>> ins_i (V, V.begin()+3);

    auto it = V.begin();
    it = V.insert(ins_i, 3);*/

    //3
    std::vector <int> V1;

    std::ifstream in("ex.txt");
    if (in.is_open())
    {
        std::istream_iterator <int> ifn_it (in);

        while (ifn_it != it_EOF)
        {
            V1.push_back(*ifn_it);
            ++ifn_it; 
        }   
    }

    std::ofstream out("ex1.txt");
    if (out.is_open())
    {
        std::copy (V1.begin(), V1.end(), std::ostream_iterator<int>(out, " "));
        out << std::endl;
    }

    //4
    std::vector <int> V2 (7, 15);
    std::deque <int> Q (2, 10);

    std::copy (V2.begin(), V2.end(), std::back_inserter(Q));

    std::copy (Q.begin(), Q.end(), std::ostream_iterator<int>(std::cout, " "));

    //5
    /*std::list<int> L1;
    std::cout << "Write a list of numbers:" << std::endl;
    std::istream_iterator <int> it1_EOF;
    std::istream_iterator <int> in_it1 (std::cin);
    while (in_it1 != it1_EOF)
    {
       L1.push_back(*in_it1);
       ++in_it1; 
    }

    std::copy (L1.rbegin(), L1.rend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;*/

    return 0;
}