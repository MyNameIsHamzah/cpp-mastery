#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <utility>
#include <optional>
#include <limits>

template <typename T>
std::optional<std::pair<std::size_t, std::size_t>> minMax(const std::vector<T>& v){
    if (v.empty()) return std::nullopt;

    std::size_t maxIndex {0};
    std::size_t minIndex {0};

    for (std::size_t i{1}; i < v.size(); i++){
        if (v[i] > v[maxIndex]){
            maxIndex = i;
        }
        if (v[i] < v[minIndex]){
            minIndex = i;
        }
    }
    return std::pair<std::size_t,std::size_t>{minIndex, maxIndex};
}

template <typename T>
void printResult(const std::vector<T>& v , const std::pair<std::size_t,std::size_t>& pair){
    assert(pair.first < v.size() && pair.second <= v.size() );
    std::cout << "With array: {";
    for (std::size_t i {0}; i < v.size(); ++i){
        if (i == v.size()-1){
            std::cout << v[i] << "}:\n";
        }
        else{
            std::cout << v[i] << ", ";
        }
    }

    std::cout << "The min element has index " << pair.first << " and value " << v[pair.first] << "\n";
    std::cout << "The max element has index " << pair.second << " and value " << v[pair.second] << "\n";
}

template <typename T>
void findAndPrintMinMax(const std::vector<T>& v){
    auto result {minMax(v)};
    
    if (result){
        printResult(v, *result);
    }
    else{
        std::cout << "vector is empty.\n";
    }
}

template <typename T>
std::vector<T> takeInput(){
    std::cout<<"Enter numbers to add (use -1 to stop)";
    std::vector<T> v {};
    T x {};
    while(true){
        std::cin >> x;
        if (x == -1) break;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input            continue;
            continue;
        }
        v.push_back(x);
    }
    return v;
}