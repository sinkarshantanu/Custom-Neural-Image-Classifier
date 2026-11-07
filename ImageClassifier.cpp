#include "ImageClassifier.h"
#include <iostream>

ImageClassifier::ImageClassifier(int pixel_features, int target_classes) 
    : weights(pixel_features, target_classes) {
    weights.randomize();
    biases.resize(target_classes, 0.05);
}

int ImageClassifier::predict(const std::vector<double>& raw_pixels) {
    Matrix input_layer(1, raw_pixels.size());
    input_layer.data = raw_pixels;

    Matrix output_layer = Matrix::multiply(input_layer, weights);
    output_layer.addBias(biases);
    output_layer.applyReLU();

    int predicted_class = 0;
    double max_activation = output_layer.data[0][0];

    for (int i = 1; i < output_layer.cols; ++i) {
        if (output_layer.data[0][i] > max_activation) {
            max_activation = output_layer.data[0][i];
            predicted_class = i;
        }
    }
    return predicted_class;
}
