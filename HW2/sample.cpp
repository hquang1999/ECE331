#include "sample.hpp"

float sampleMean(float tests, std::vector<int> &x) {
    int sum = std::accumulate(x.begin(), x.end(), 0);
    float mean = (float) sum / tests;
    return mean;
}

float sampleVariance(float tests, float mean, std::vector<int> &x) {
    int max = x.size();
    float acc = 0;
    int temp;
    for (int i = 0; i < max; i++) {
        temp = x[i] - mean; 
        acc += pow(temp,2);
    }

    acc = (float) acc / tests;

    return acc;
}
