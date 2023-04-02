with open("maze3.txt", "r") as f:
    with open("maze_out.txt", "w") as o:
        print('{', end='')
        for line in f.readlines():
            print('{', end='')
            for char in line:
                if char == '#':
                    print('-1, ', end='')
                elif char ==  ' ':
                    print('0, ', end='')
            print("},", end="")
        print("}")