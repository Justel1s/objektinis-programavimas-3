#include "vector.h"
#include <bits/stdc++.h>

using namespace std;

void resizeCount(int sz){
    int resize_count_v1 = 0;
    int resize_count_v2 = 0;
    std::vector<int> v1;
    Vector<int> v2;
    for (int i = 0; i < sz; ++i){
        v1.push_back(i);
        if(v1.capacity() == v1.size()) {
            ++resize_count_v1;
        }
    }
    v1.clear();

    for (int i = 0; i < sz; ++i) {
        v2.push_back(i);
        if(v2.capacity() == v2.size()) {
            ++resize_count_v2;
        }
    }
    v2.clear();

    std::cout << "Number of resizes in v1: " << resize_count_v1 << std::endl;
    std::cout << "Number of resizes in v2: " << resize_count_v2 << std::endl;
}


int main() {
    const int num_runs = 5;
    resizeCount(100000000);

    for (unsigned int sz : {10000, 100000, 1000000, 10000000, 100000000}) {
        std::vector<int> v1;
        Vector<int> v2;

        long long total_duration_v1 = 0;
        long long total_duration_v2 = 0;

        for (int run = 0; run < num_runs; ++run) {
            // Start v1 fill time measurement
            auto start_v1 = std::chrono::high_resolution_clock::now();
            for (int i = 1; i <= sz; ++i)
                v1.push_back(i);
            auto end_v1 = std::chrono::high_resolution_clock::now();
            auto duration_v1 = std::chrono::duration_cast<std::chrono::microseconds>(end_v1 - start_v1);
            total_duration_v1 += duration_v1.count();

            // Start v2 fill time measurement
            auto start_v2 = std::chrono::high_resolution_clock::now();
            for (int i = 1; i <= sz; ++i)
                v2.push_back(i);
            auto end_v2 = std::chrono::high_resolution_clock::now();
            auto duration_v2 = std::chrono::duration_cast<std::chrono::microseconds>(end_v2 - start_v2);
            total_duration_v2 += duration_v2.count();

            // Clear vectors for the next run
            v1.clear();
            v2.clear();
        }

        std::cout << "Average time taken to fill v1 of size " << sz << " over " << num_runs << " runs: " << total_duration_v1 / num_runs << " microseconds" << std::endl;
        std::cout << "Average time taken to fill v2 of size " << sz << " over " << num_runs << " runs: " << total_duration_v2 / num_runs << " microseconds" << std::endl;
    }


    return 0;
}
