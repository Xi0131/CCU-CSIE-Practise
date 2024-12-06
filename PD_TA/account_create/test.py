import sys

# Open the file for writing
with open("output.txt", "w") as file:
    # Redirect stdout to the file
    sys.stdout = file

    # Anything printed will go to the file
    print("This will be written to the file.")
    print("So will this!")

# Reset stdout back to the default (console)
sys.stdout = sys.__stdout__

# Print to console to verify
print("Back to console output.")
