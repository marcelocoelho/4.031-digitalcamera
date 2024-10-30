# Python Camera


## How to use this script:

1. Install OpenCV: You can install it using pip with the command pip install opencv-python.
2. Run the script.
3. Press 'c' to capture an image.
4. Press 'q' to exit the camera feed.


## Explanation:

1. OpenCV Initialization: The script uses OpenCV to access the camera and capture images.
2. Incremental File Naming: The get_next_filename function checks for existing files and generates the next available filename with an incremental number.
3. Capture and Save: The script captures images when the user presses the 'c' key and saves them in a directory named "images". If the directory doesn't exist, it creates one.
Exit: The user can exit the camera feed by pressing the 'q' key.

## Requirements:

Install OpenCV: You can install it using pip with the command pip install opencv-python.
This script should be run in an environment where a camera is available, such as a laptop with a built-in webcam.
'''
