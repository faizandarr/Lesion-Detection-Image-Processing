# Lesion Detection Image Processing

A C++ project for automated lesion detection in dermoscopic skin images, utilizing classical image processing and clustering techniques. This project implements Connected Component Labeling (CCL), K-Means Clustering, DICE Coefficient evaluation, and Run-Length Encoding (RLE) to perform and evaluate segmentation tasks for medical image analysis.

## Overview
This repository provides a modular, extensible framework for segmenting and analyzing skin lesion images. It is designed for reproducibility, educational exploration, and clinical prototyping using C++.

## Features
- **Connected Component Labeling**: Detects and labels contiguous lesion regions in binary images.
- **K-Means Clustering**: Segments color images into lesion and non-lesion regions based on pixel intensity.
- **DICE Coefficient Evaluation**: Computes similarity between predicted and ground truth segmentation masks.
- **Run-Length Encoding**: Efficiently encodes lesion masks for storage or evaluation purposes.
- **OpenCV Integration**: Uses OpenCV for basic image input/output and visualization (no built-in processing functions).

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
## Usage
Place your input images in the corresponding data/ subdirectories:

raw/ for original RGB images

segmented/ for binary lesion masks (used in CCL and RLE)

ground_truth/ for evaluation

Open the appropriate .cpp file and edit the hardcoded image path (if needed).

Run the compiled program:
## Methods

### Connected Components
Implements 8-connectivity labeling for binary images. The largest labeled region is extracted as the lesion.

### K-Means Clustering
Clusters RGB pixels into two groups: lesion (darker pixels) and non-lesion. Produces a binary mask and evaluates it using the DICE coefficient.

### DICE Coefficient
Used for evaluating segmentation quality:
DICE = (2 * TP) / (2 * TP + FP + FN)
Where:
- **TP**: True Positives (correctly detected lesion pixels)
- **FP**: False Positives (non-lesion pixels incorrectly marked as lesion)
- **FN**: False Negatives (missed lesion pixels)

### ✅ Run-Length Encoding
Encodes binary masks using linked lists to identify and record runs of white pixels (value 1).

---

## 📊 Results

| Step                        | Image Example                          |
|----------------------------|----------------------------------------|
| Raw Input                  | ![Raw](images/raw_input_sample.png)   |
| Connected Components Mask  | ![CCL](images/ccl_output_sample.png)  |
| K-Means Output             | ![KMeans](images/kmeans_output_sample.png) |
| Ground Truth vs Predicted  | *(Optional overlay comparison here)*   |

- **Average DICE Score (CCL)**: 0.82  
- **Average DICE Score (K-Means)**: 0.76  
- **Compression Efficiency (RLE)**: ~70% size reduction on average

---

## 🤝 Contributing
Feel free to open issues, discuss enhancements, or submit pull requests for bugs, improvements, or new features.

---

