# Lesion Detection Image Processing

A C++ project for lesion detection on skin images using connected component labeling, K-means clustering, DICE coefficient evaluation, and run-length encoding.

## Project Structure

```
Lesion-Detection-Image-Processing/
│
├── data/
│   ├── raw/                # Original images
│   ├── ground_truth/       # Ground truth masks
│   └── segmented/          # Segmented outputs
│
├── src/
│   ├── connected_components.cpp  # Connected component labeling
│   ├── kmeans_dice.cpp           # K-means clustering & DICE evaluation
│   ├── run_length_encoding.cpp   # Run-length encoding
│
├── README.md
└── ...
```

## Requirements
- OpenCV
- C++17 or later

## Build & Run
Add your build instructions here (e.g., using CMake or g++ directly).
