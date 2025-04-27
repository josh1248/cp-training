from sys import stdin
read = lambda: stdin.readline().strip()

catalans = [-1] * 5002
catalans[1] = 1

def populate_catalans():
    '''
    // https://en.wikipedia.org/wiki/Catalan_number
    // Cn = (2n)! / (n + 1)!n!
    // Cn+1 = (2n + 2)! / (n+2)!(n+1)!
    // Cn+1/Cn = (2n + 2) (2n + 1) / (n + 2)(n + 1)
    // = (4n + 2) / (n + 2)
    // Cn/Cn-1 = (4n - 2) / (n + 1)
    '''
    for i in range(2, 5002):
        catalans[i] = catalans[i - 1] * (4 * i - 2) // (i + 1)

def main():
    populate_catalans()
    print(str(catalans[int(read()) + 1]))

main()