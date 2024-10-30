


import cv2
import os

def get_next_filename(directory, base_name, extension):
    """Generate the next incremental filename."""
    i = 1
    while True:
        filename = f"{base_name}_{i:03d}.{extension}"
        if not os.path.exists(os.path.join(directory, filename)):
            return filename
        i += 1

def capture_image():
    # Initialize the camera
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("Error: Could not open camera.")
        return

    # Create a window to display the camera feed
    cv2.namedWindow("Camera")

    while True:
        # Capture frame-by-frame
        ret, frame = cap.read()

        if not ret:
            print("Error: Could not read frame.")
            break

        # Display the resulting frame
        cv2.imshow("Camera", frame)

        # Wait for the user to press a key
        key = cv2.waitKey(1) & 0xFF

        # If the user presses 'c', capture and save the image
        if key == ord('c'):
            directory = "images"
            if not os.path.exists(directory):
                os.makedirs(directory)
            filename = get_next_filename(directory, "image", "jpg")
            cv2.imwrite(os.path.join(directory, filename), frame)
            print(f"Image saved as {filename}")

        # If the user presses 'q', exit the loop
        elif key == ord('q'):
            break

    # When everything is done, release the capture
    cap.release()
    cv2.destroyAllWindows()

if __name__ == "__main__":
    capture_image()
