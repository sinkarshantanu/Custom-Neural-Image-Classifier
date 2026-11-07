#ifndef IMAGE_CLASSIFIER_H
#define IMAGE_CLASSIFIER_H

#include <vector>
#include <string>
#include "Matrix.h"

class ImageClassifier {
private:
    Matrix weights;
    std::vector<double> biases;

public:
    ImageClassifier(int pixel_features, int target_classes);
    int predict(const std::vector<double>& raw_pixels);
};

#endif // IMAGE_CLASSIFIER_H
