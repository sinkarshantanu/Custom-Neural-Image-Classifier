#include "DatasetReader.h"
#include <cstdlib>

std::vector<ImageRecord> DatasetReader::loadMockDataset(const std::string& filepath, int sample_count, int pixel_features) {
    std::vector<ImageRecord> dataset;
    for (int i = 0; i < sample_count; ++i) {
        ImageRecord record;
        record.pixel_buffer.resize(pixel_features);
        for (int j = 0; j < pixel_features; ++j) {
            record.pixel_buffer[j] = static_cast<double>(rand()) / RAND_MAX;
        }
        record.ground_truth_label = rand() % 3;
        dataset.push_back(record);
    }
    return dataset;
}
