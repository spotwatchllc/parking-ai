import os
import shutil

# === Directories ===
source_dir = "cropped_spots"  # Folder containing cropped images and label text files
empty_dir = "empty"           # Destination for images with label '0'
occupied_dir = "occupied"     # Destination for images with label '1'

# Create destination directories if they don't exist (outside the cropped_spots folder)
os.makedirs(empty_dir, exist_ok=True)
os.makedirs(occupied_dir, exist_ok=True)

# Iterate over all files in the source directory
for filename in os.listdir(source_dir):
    # Process only text files (labels)
    if filename.endswith(".txt"):
        label_path = os.path.join(source_dir, filename)
        with open(label_path, "r") as f:
            label = f.read().strip()  # Expecting "0" or "1"

        # Derive corresponding image filename (assumes same base name with .jpg extension)
        base_name = os.path.splitext(filename)[0]
        image_filename = base_name + ".jpg"
        image_path = os.path.join(source_dir, image_filename)

        # Check if the corresponding image file exists
        if os.path.exists(image_path):
            if label == "0":
                shutil.copy(image_path, empty_dir)
            elif label == "1":
                shutil.copy(image_path, occupied_dir)
            else:
                print(f"Unexpected label '{label}' in {filename}")
        else:
            print(f"Image file {image_filename} not found for label file {filename}")
