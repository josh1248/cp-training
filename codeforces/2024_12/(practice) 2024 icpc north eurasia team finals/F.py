from sys import stdin
read = lambda: stdin.readline().strip()

lines_per_test_case = 2

def algo(tiles):
    i = 0
    flag = False
    while i < len(tiles[0]):
        '''
        ..
        #.
        '''
        if tiles[0][i] == '.' and tiles[1][i] == '#':
            if i < len(tiles[0]) - 1 and tiles[0][i + 1] == '.':
                tiles[0][i] = '#'
                tiles[0][i + 1] = '#'
                i += 1
            else:
                return 'None'
        elif tiles[0][i] == '#' and tiles[1][i] == '.':
            if i < len(tiles[0]) - 1 and tiles[1][i + 1] == '.':
                tiles[1][i] = '#'
                tiles[1][i + 1] = '#'
                i += 1
            else:
                return 'None'
        elif tiles[0][i] == '.' and tiles[1][i] == '.':
            if i == len(tiles[0]) - 1:
                i += 1
            elif tiles[0][i + 1] == '.' and tiles[1][i + 1] == '.':
                flag = True
                i += 2
            else:
                i += 1
        else:
            i += 1

    return 'Unique' if not flag else 'Multiple'

def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        int(read())
        tiles = []
        for _ in range(2):
            tiles.append(list(read()))
        print(algo(tiles))

main()