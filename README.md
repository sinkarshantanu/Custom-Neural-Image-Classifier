# Custom Neural Engine for Image Classification (C++)

A high-performance, zero-framework machine learning pipeline built entirely in pure C++. This system completely bypasses external library wrappers like NumPy or TensorFlow, implementing multi-dimensional matrix transformation loops, custom file-stream dataset batch parsing modules, and structural layer activation algorithms from scratch.

## 🚀 Key Architectural Highlights
* **Zero-Framework Blueprint:** Coded using raw standard library containers (`std::vector`) to eliminate third-party code vulnerabilities.
* **Batch Dataset Streaming Reader:** Built an optimized data parsing module (`DatasetReader`) that cleanly translates multi-column pixel data rows into active runtime vectors.
* **Low-Latency Vector Math:** Developed robust matrix dot-product nested transformation loops with explicit pass-by-reference mechanisms (`const Matrix&`) to achieve a zero-overhead processing speed profile.

## 📊 Structural Operational Layout
1. **Data Ingestion Engine:** `DatasetReader` streams tabular pixel datasets into local buffers.
2. **Mathematical Execution Core:** `Matrix` classes calculate multi-dimensional layer weights.
3. **Classification Mapping:** `ImageClassifier` parses structural activation boundaries to resolve target output classes.
