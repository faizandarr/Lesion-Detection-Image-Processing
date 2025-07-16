# Lesion Detection Image Processing

A C++ project for automated lesion detection in skin images, leveraging classical image processing and clustering techniques. This project demonstrates the use of connected component labeling, K-means clustering, DICE coefficient evaluation, and run-length encoding for medical image analysis.

## Overview
This repository provides a modular and extensible framework for segmenting and analyzing skin lesion images. The code is organized for clarity, reproducibility, and ease of extension for research or clinical prototyping.

## Features
- **Connected Component Labeling**: Identifies and labels contiguous regions in binary images.
- **K-means Clustering**: Segments images into lesion and non-lesion regions using unsupervised clustering.
- **DICE Coefficient Evaluation**: Quantitatively compares segmentation results to ground truth masks.
- **Run-Length Encoding**: Efficiently encodes binary masks for storage or submission.
- **OpenCV Integration**: Utilizes OpenCV for robust image I/O and visualization.

## Data Structure
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

## Installation
1. **Dependencies**:
   - [OpenCV](https://opencv.org/) (C++ bindings)
   - C++17 or later
2. **Build**:
   - You can use CMake, Makefile, or direct compilation with g++/clang++.
   - Example (g++):
     ```sh
     g++ -std=c++17 -o connected_components src/connected_components.cpp `pkg-config --cflags --libs opencv4`
     g++ -std=c++17 -o kmeans_dice src/kmeans_dice.cpp `pkg-config --cflags --libs opencv4`
     g++ -std=c++17 -o run_length_encoding src/run_length_encoding.cpp `pkg-config --cflags --libs opencv4`
     ```

## Usage
- Place your images in the appropriate `data/` subfolders.
- Edit the image path constants at the top of each `.cpp` file to select which image to process.
- Run the desired executable:
  ```sh
  ./connected_components
  ./kmeans_dice
  ./run_length_encoding
  ```

## Methods
- **Connected Components**: Labels all connected regions in a binary mask, useful for isolating lesions.
- **K-means Clustering**: Segments grayscale or color images into clusters, typically separating lesion from background.
- **DICE Coefficient**: Measures overlap between predicted segmentation and ground truth (range: 0–1).
- **Run-Length Encoding**: Converts binary masks into a compact string format for efficient storage or competition submission.

## Results
*Add your results, sample outputs, or evaluation metrics here.*

## Contributing
Contributions, bug reports, and feature requests are welcome! Please open an issue or submit a pull request.

## License
*Specify your license here (e.g., MIT, Apache 2.0, etc.).*
