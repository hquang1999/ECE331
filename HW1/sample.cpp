#include "sample.hpp"

float sampleMean(float tests, std::vector<int> &x) {
    int sum = std::accumulate(x.begin(), x.end(), 0);
    float mean = (float) sum / tests;
    return mean;
}

float sampleVariance(float tests, float mean, std::vector<int> &x) {
    int max = x.size();
    float acc = 0;
    float temp;
    for (int i = 0; i < max; i++) {
        temp = (float) x[i] - mean; 
        acc += temp * temp;
    }

    acc = acc / tests;

    return acc;
}
