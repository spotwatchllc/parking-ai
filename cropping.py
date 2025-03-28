from PIL import Image
import pandas as pd
import os

# === Inputs ===
image_path = "/Users/arulmuralikrishna/Desktop/UMich/EECS 473/Parking Project/Cropping Parking Lots/2012-09-21_12_00_25_jpg.rf.08e9a3daa42984ca806e535fcc8af191.jpg"
txt_path = "/Users/arulmuralikrishna/Desktop/UMich/EECS 473/Parking Project/Cropping Parking Lots/2012-09-21_12_00_25_jpg.rf.08e9a3daa42984ca806e535fcc8af191.txt"
output_dir = "cropped_spots"

# === Create output directory ===
os.makedirs(output_dir, exist_ok=True)

# === Load image ===
image = Image.open(image_path)
width, height = image.size

# === Read label and bounding box data ===
with open(txt_path, "r") as file:
    lines = file.readlines()

cropped_data = []

# === Process each line in the annotation file ===
for i, line in enumerate(lines):
    parts = list(map(float, line.strip().split()))
    label, cx, cy, w, h = parts
    
    # Convert normalized coordinates to pixel values
    left = int((cx - w / 2) * width)
    right = int((cx + w / 2) * width)
    top = int((cy - h / 2) * height)
    bottom = int((cy + h / 2) * height)

    # Crop the image
    cropped_img = image.crop((left, top, right, bottom))

    # Save cropped image
    filename = f"spot_{i:03d}.jpg"
    cropped_img.save(os.path.join(output_dir, filename))

     # Save image
    image_filename = f"spot_{i:03d}.jpg"
    image_path_out = os.path.join(output_dir, image_filename)
    cropped_img.save(image_path_out)

    # Save label to text file
    label_filename = f"spot_{i:03d}.txt"
    label_path_out = os.path.join(output_dir, label_filename)
    with open(label_path_out, "w") as f:
        f.write(str(int(label)))
