#ifndef DATASET_READER_H
#define DATASET_READER_H

#include <vector>
#include <string>

struct ImageRecord {
    std::vector<double> pixel_buffer;
    int ground_truth_label;
};

class DatasetReader {
public:
    static std::vector<ImageRecord> loadMockDataset(const std::string& filepath, int sample_count, int pixel_features);
};

#endif // DATASET_READER_H
