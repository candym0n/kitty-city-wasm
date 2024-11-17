import os

APPLICATION_NAME = "game"

SRC_DIR = "src\\"
WASM_DIR = "public\\wasm"

CFLAGS = [
    "-Wno-undefined-internal",  # Ignore the internal linkage error (for EM_JS)
    "-I include",
    "-I library/include",
    "-O1",
    "-sERROR_ON_WASM_CHANGES_AFTER_LINK",
    "-sWASM_BIGINT"
]

# Count the number of newlines in a set of files
def count_lines_of_code(file_paths):
    total_lines = 0
    for file_path in file_paths:
        with open(file_path, 'r') as f:
            total_lines += sum(1 for _ in f)
    return total_lines

# Recursively find all files with a certain extension under the specified directory.
def find_files(extension, src_dir=SRC_DIR):
    c_files = []
    for root, _, files in os.walk(src_dir):
        for file in files:
            if file.endswith(extension):
                c_files.append(os.path.join(root, file))
    return c_files

def main():
    # Find the CPP files to compile
    cpp_files = find_files(".cpp", "src") + find_files(".cpp", "library/src")

    # Print the # of lines of code
    line_file_one = [
        *find_files(".cpp", "src"),
        *find_files(".h", "include")
    ]

    linesOne = count_lines_of_code(line_file_one)
    
    line_file_two = [
        *find_files(".cpp", "library/src"),
        *find_files(".h", "library/include")
    ]

    linesTwo = count_lines_of_code(line_file_two) + linesOne

    # Compile it!
    print("Compiling " + "\n".join(cpp_files))
    command = " ".join([
        "em++", *cpp_files,
        f"-o {WASM_DIR}\\{APPLICATION_NAME}.js",
        *CFLAGS,
    ])
    compile_proc = os.system(command)

    # Check for errors
    if compile_proc != 0:
        print("\n\nCommand that was run:")
        print(command)
        return

    # Delete the rubbish
    os.system(f"del {WASM_DIR}\\{APPLICATION_NAME}.js")

    # Yay!
    print("\nWe have compiled " + str(linesTwo) + " lines of code!")
    print(str(linesOne) + " of those YOU have written!")

if __name__ == "__main__":
    main()

