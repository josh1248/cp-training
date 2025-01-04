from sys import stdin
read = lambda: stdin.readline().strip()

def query(v, r):
    if r <= 0:
        return 0
    
    cycles = r // len(v)
    remaining = r % len(v)
    acc = cycles * v[-1]

    rights = (remaining + cycles - 1) % len(v)

    if rights - remaining >= 0:
        return acc + v[rights] - v[rights - remaining]
    elif rights - remaining == 0:
        return acc + v[rights]
    else:
        wraparound = rights + len(v) - remaining
        return acc + v[rights] + v[-1] - v[wraparound]
    

def main():
    total_inputs = int(read())
    for _ in range(total_inputs):
        n, q = [int(i) for i in read().split(" ")]
        prefixes = []
        for k in [int(i) for i in read().split(" ")]:
            if not prefixes:
                prefixes.append(k)
            else:
                prefixes.append(k + prefixes[-1])

        for i in range(q):
            l, r = [int(i) for i in read().split(" ")]
            print(query(prefixes, r) - query(prefixes, l - 1))

main()