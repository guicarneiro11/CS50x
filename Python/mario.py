def print_pyramid(height):
    for i in range(1, height + 1):
        spaces = " " * (height - i)
        hashes = "#" * i
        print(spaces + hashes)


if __name__ == "__main__":
    height = 8
    print_pyramid(height)
