#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ImageClassifier.h"
#include "DatasetReader.h"

int main() {
    srand(time(0));
    std::cout << "⚙️ Booting Zero-Framework Custom Image Classification Engine...\n";

    int pixel_features = 16;  
    int target_classes = 3;   // Categories: [0: Landscape, 1: Portrait, 2: Document]
    int batch_size = 3;       

    std::cout << "📂 Streaming batch image objects via DatasetReader interface...\n";
    std::vector<ImageRecord> batch_images = DatasetReader::loadMockDataset("data/mnist_mock.csv", batch_size, pixel_features);

    ImageClassifier classifier(pixel_features, target_classes);

    std::cout << "\n=============================================";
    std::cout << "\n🎯 STRUCTURAL IMAGE BATCH CLASSIFICATION LOGS";
    std::cout << "\n=============================================\n";

    for (int i = 0; i < batch_images.size(); ++i) {
        int prediction = classifier.predict(batch_images[i].pixel_buffer);
        int actual = batch_images[i].ground_truth_label;

        std::cout << "📸 Processing Sample [#" << i + 1 << "] -> ";
        std::cout << "Predicted Target ID: " << prediction << " | ";
        std::cout << "Ground Truth Target ID: " << actual << " -> ";
        
        if (prediction == actual) {
            std::cout << "[✅ MATCH]\n";
        } else {
            std::cout << "[❌ MISMATCH]\n";
        }
    }
    std::cout << "=============================================\n";
    return 0;
}
