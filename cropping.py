from PIL import Image
import os

# === Inputs ===
input_dir = "PKLot/train"
output_dir = "cropped_spots"

# === Create output directory ===
os.makedirs(output_dir, exist_ok=True)

# === Process each image and its annotation file in the input folder ===
for file in os.listdir(input_dir):
    if file.lower().endswith(".jpg"):
        image_path = os.path.join(input_dir, file)
        txt_filename = os.path.splitext(file)[0] + ".txt"
        txt_path = os.path.join(input_dir, txt_filename)
        
        # Check if the corresponding annotation file exists
        if not os.path.exists(txt_path):
            print(f"Annotation file for {file} not found, skipping.")
            continue
        
        # Load image and get its dimensions
        image = Image.open(image_path)
        width, height = image.size
        
        # Read label and bounding box data from the text file
        with open(txt_path, "r") as annotation_file:
            lines = annotation_file.readlines()
        
        # Process each annotation line
        for i, line in enumerate(lines):
            parts = list(map(float, line.strip().split()))
            if len(parts) != 5:
                print(f"Skipping invalid line in {txt_filename}: {line}")
                continue
            label, cx, cy, w, h = parts
            
            # Convert normalized coordinates to pixel values
            left = int((cx - w / 2) * width)
            right = int((cx + w / 2) * width)
            top = int((cy - h / 2) * height)
            bottom = int((cy + h / 2) * height)
            
            # Crop the image
            cropped_img = image.crop((left, top, right, bottom))
            
            # Create unique filenames based on the original image name and spot index
            base_name = os.path.splitext(file)[0]
            image_filename = f"{base_name}_spot_{i:03d}.jpg"
            label_filename = f"{base_name}_spot_{i:03d}.txt"
            
            # Save the cropped image
            cropped_img.save(os.path.join(output_dir, image_filename))
            
            # Save the label in a text file
            with open(os.path.join(output_dir, label_filename), "w") as f:
                f.write(str(int(label)))
