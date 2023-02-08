#include "sample.hpp"

float sampleMean(float tests, std::vector<float> &x) {
    float sum = std::accumulate(x.begin(), x.end(), 0);
    float mean = (float) sum / tests;
    return mean;
}

float sampleVariance(float tests, float mean, std::vector<float> &x) {
    int max = x.size();
    float acc = 0;
    float temp;
    for (int i = 0; i < max; i++) {
        temp = x[i] - mean; 
        acc += pow(temp,2);
    }

    acc = (float) acc / tests;

    return acc;
}
