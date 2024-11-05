#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    //创建空 Mymap 容器
    unordered_map<int, vector<unordered_map<char, int>>> Mymap;

    vector<unordered_map<char, int>> maps_3, maps_2;
    maps_3.push_back(unordered_map<char, int> {{'a', 1}, {'t', 1}, {'e', 1}});
    maps_3.push_back(unordered_map<char, int> {{'a', 1}, {'t', 1}, {'n', 1}});
    maps_2.push_back(unordered_map<char, int> {{'a', 1}, {'t', 1}});
    //向 Mymap 容器添加新键值对
    Mymap.emplace(3, maps_3);
    Mymap.emplace(2, maps_2);

    //输出 Mymap 存储键值对的数量
    cout << "umap size = " << Mymap.size() << endl << endl;

    //使用迭代器输出 Mymap 容器存储的所有键值对
    for (auto iter = Mymap.begin(); iter != Mymap.end(); ++iter) {
        cout << "map of int " << iter->first << ": " << endl;

        // 输出vector里的所有 map 容器存储的所有键值对
        for (int i = 0; i < iter->second.size(); i++) {
            cout << "vector item " << i << ": ";

            for (auto mmiter = iter->second[i].begin(); mmiter != iter->second[i].end(); ++mmiter) {
                cout << mmiter->first << "->" << mmiter->second << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
