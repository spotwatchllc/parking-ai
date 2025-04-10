# This cuts 75% of the dataset

import os
import random

def remove_percentage_of_data(folder_path, percentage=0.75, seed=42):
    random.seed(seed)
    files = os.listdir(folder_path)

    # Filter to only image files (assuming .jpg) – modify if using other formats
    image_files = [f for f in files if f.endswith('.jpg')]

    # Calculate number to remove
    num_to_remove = int(len(image_files) * percentage)

    # Randomly choose files to remove
    files_to_remove = random.sample(image_files, num_to_remove)

    for image_file in files_to_remove:
        image_path = os.path.join(folder_path, image_file)
        annotation_file = os.path.splitext(image_file)[0] + ".txt"
        annotation_path = os.path.join(folder_path, annotation_file)

        # Remove image
        if os.path.exists(image_path):
            os.remove(image_path)

        # Remove corresponding annotation
        if os.path.exists(annotation_path):
            os.remove(annotation_path)

    print(f"Removed {num_to_remove} images and their annotations from '{folder_path}'.")

# Update the paths if needed
base_path = "pklot_dataset"
subfolders = ["train", "valid", "test"]

for folder in subfolders:
    folder_path = os.path.join(base_path, folder)
    remove_percentage_of_data(folder_path, percentage=0.75)
