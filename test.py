from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing.image import load_img, img_to_array
import numpy as np

# === Load the trained model ===
model = load_model('parking_spot_classifier.h5')

# === Set image parameters (should match your training settings) ===
IMAGE_SIZE = (40, 40)  # Adjust if you used a different size during training
image_path = "test6-occupied.jpg"  # Replace with your test image path

# === Load and preprocess the image ===
img = load_img(image_path, target_size=IMAGE_SIZE)
img_array = img_to_array(img)
img_array = img_array / 255.0  # Normalize the pixel values
img_array = np.expand_dims(img_array, axis=0)  # Add batch dimension

# === Make a prediction ===
prediction = model.predict(img_array)

# Since the model uses a sigmoid activation, a threshold of 0.5 is used for classification.
predicted_class = 1 if prediction[0][0] > 0.5 else 0

print(f"Predicted class: {predicted_class} (Probability: {prediction[0][0]:.2f})")
