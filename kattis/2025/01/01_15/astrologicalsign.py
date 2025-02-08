from sys import stdin
read = lambda: stdin.readline().strip()

def algo(d, m):
    if m == 'Mar':
        print('Pisces' if d < 21 else 'Aries')
    elif m == 'Apr':
        print('Aries' if d < 21 else 'Taurus')
    elif m == 'May':
        print('Taurus' if d < 21 else 'Gemini')
    elif m == 'Jun':
        print('Gemini' if d < 22 else 'Cancer')
    elif m == 'Jul':
        print('Cancer' if d < 23 else 'Leo')
    elif m == 'Aug':
        print('Leo' if d < 23 else 'Virgo')
    elif m == 'Sep':
        print('Virgo' if d < 22 else 'Libra')
    elif m == 'Oct':
        print('Libra' if d < 23 else 'Scorpio')
    elif m == 'Nov':
        print('Scorpio' if d < 23 else 'Sagittarius')
    elif m == 'Dec':
        print('Sagittarius' if d < 22 else 'Capricorn')
    elif m == 'Jan':
        print('Capricorn' if d < 21 else 'Aquarius')
    else:
        print('Aquarius' if d < 20 else 'Pisces')   

def main():
    args = []
    n = int(read())
    for i in range(n):
        d, m = read().split()
        algo(int(d), m)
main()